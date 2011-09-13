/*
PROG: packdel
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

struct node{
    int idx;
    int cost;
};

vector<int> map[50010];
vector<int> cmap[50010];
vector<node> q;
char lmap[50010];

bool cmp(node a,node b){
    return a.cost>b.cost;
}

int main(){
    freopen("packdel.in","r",stdin);
    freopen("packdel.out","w",stdout);

    int n,m;
    int i,j;
    int a,b,c;
    int u,v;

    node nn,cn;

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
	map[i].clear();
	lmap[i]=0;
    }
    for(i=0;i<m;i++){
	scanf("%d %d %d",&a,&b,&c);
	a--;
	b--;
	map[a].push_back(b);
	map[b].push_back(a);
	cmap[a].push_back(c);
	cmap[b].push_back(c);
    }

    q.clear();
    nn.idx=0;
    nn.cost=0;
    q.push_back(nn);
    while(!q.empty()){
	pop_heap(q.begin(),q.end(),cmp);
	cn=q.back();
	q.pop_back();

	if(lmap[cn.idx]==0){
	    lmap[cn.idx]=1;
	    if(cn.idx==n-1){
		printf("%d\n",cn.cost);
		break;
	    }

	    u=map[cn.idx].size();
	    for(i=0;i<u;i++){
		v=map[cn.idx][i];
		if(lmap[v]==0){
		    nn.idx=v;
		    nn.cost=cn.cost+cmap[cn.idx][i];
		    q.push_back(nn);
		    push_heap(q.begin(),q.end(),cmp);
		}
	    }
	}
    }

    return 0;
}
