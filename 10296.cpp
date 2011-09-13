#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> map[20];
vector<int> cmap[20];
char l[20];
int n,m;

char lmap[20];
int dmap[20];
vector<int> q;
int umap[20][20];
int mi;

bool cmp(int a,int b){
	return dmap[a]>dmap[b];
}
int sp(int s){
	int i;
	int u,v;
	int a,c;

	for(i=0;i<n;i++){
		lmap[i]=0;
		dmap[i]=2047483640;
	}

	q.clear();	
	q.push_back(s);
	dmap[s]=0;
	push_heap(q.begin(),q.end(),cmp);
	while(!q.empty()){
		a=q[0];
		pop_heap(q.begin(),q.end(),cmp);
		q.pop_back();
		if(lmap[a]==0){
			lmap[a]=1;
			u=map[a].size();
			for(i=0;i<u;i++){
				v=map[a][i];
				c=dmap[a]+cmap[a][i];
				if(lmap[v]==0 && c<dmap[v]){
					dmap[v]=c;
					q.push_back(v);
					push_heap(q.begin(),q.end(),cmp);
				}
			}
		}
	}

	return 0;
}
int dfs(int a,int sum){
	int i;
	int u,v;

	if(a==n){
		mi=min(mi,sum);
		return 0;
	}
	if(lmap[a]==0 && l[a]==1){
		lmap[a]=1;	
		for(i=a+1;i<n;i++){
			if(lmap[i]==0 && l[i]==1){
				lmap[i]=1;
				dfs(a+1,sum+umap[a][i]);
				lmap[i]=0;
			}
		}
		lmap[a]=0;
	}else{
		dfs(a+1,sum);
	}
}

int main(){
	int i,j,k;
	int a,b,c;
	int u,v;
	int s;

	while(scanf("%d",&n)!=EOF){
		if(n==0){
			break;
		}
		for(i=0;i<n;i++){
			map[i].clear();
			cmap[i].clear();
		}
		scanf("%d",&m);
		s=0;
		for(i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			a--;
			b--;
			map[a].push_back(b);
			map[b].push_back(a);
			cmap[a].push_back(c);
			cmap[b].push_back(c);
			s+=c;
		}
		for(i=0;i<n;i++){
			l[i]=0;
			if(map[i].size()%2==1){
				l[i]=1;
			}
		}
		for(i=0;i<n;i++){
			if(l[i]==1){
				sp(i);
				for(j=0;j<n;j++){
					umap[i][j]=dmap[j];
					umap[j][i]=dmap[j];
				}
			}	
		}
		mi=2147483640;
		for(i=0;i<n;i++){
			lmap[i]=0;
		}
		dfs(0,0);
		printf("%d\n",s+mi);	
	}

	return 0;
}
