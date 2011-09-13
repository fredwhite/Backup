#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> map[1005];
vector<int> cost[1005];
int cmap[1005];
char lmap[1005];
int dp[1005];

int cmp(pair<int,int>a,pair<int,int>b){
	return a.second>b.second;
}

int ru(int a){
	int i;
	int u,v;
	int s;

	if(dp[a]!=-1){
		return dp[a];
	}

	s=0;
	u=map[a].size();
	for(i=0;i<u;i++){
		v=map[a][i];
		if(cmap[a]>cmap[v]){
			s+=ru(v);
		}
	}
	dp[a]=s;

	return s;
}

int main(){
	int n,m;
	int i,j,k;
	int u,v;
	int a,b,c;

	vector< pair<int,int> > q;

	while(true){
		scanf("%d",&n);
		if(n==0){
			return 0;
		}
		scanf("%d",&m);
		for(i=0;i<n;i++){
			map[i].clear();
			cost[i].clear();
			lmap[i]=0;
			cmap[i]=2147483640;
			dp[i]=-1;
		}
		for(i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			a--;
			b--;
			map[a].push_back(b);
			map[b].push_back(a);
			cost[a].push_back(c);
			cost[b].push_back(c);
		}
		
		q.clear();
		q.push_back(pair<int,int>(1,0));
		cmap[1]=0;
		while(!q.empty()){
			pop_heap(q.begin(),q.end(),cmp);
			a=q.back().first;
			q.pop_back();

			if(lmap[a]==0){
				lmap[a]=1;
				u=map[a].size();
				for(i=0;i<u;i++){
					v=map[a][i];
					if(lmap[v]==0 && (cmap[a]+cost[a][i])<cmap[v]){
						cmap[v]=cmap[a]+cost[a][i];
						q.push_back(pair<int,int>(v,cmap[v]));
						push_heap(q.begin(),q.end(),cmp);
					}
				}
			}
		}
		dp[1]=1;
		printf("%d\n",ru(0));
	}

	return 0;
}
