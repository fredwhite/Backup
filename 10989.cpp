#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct node{
    int idx;
    int cost;
};

int n,m;
vector<int> gra[200];
vector<int> cgra[200];
int lik[200];

char lmap[200];
int cmap[200];
int lidx,sidx;

int dis(int a){
    if(lik[a]==a){
	return a;
    }
    return lik[a]=dis(lik[a]);
}
bool cmp(node a,node b){
    return a.cost<b.cost;
}

int st(){
    vector<node> q;
    node nn,cn; 

    int i,j;
    int u,v;
    int a,b;

    for(i=0;i<n;i++){
	lmap[i]=0;	
	cmap[i]=0;
    }
    q.clear();

    sidx=-1;
    lidx=-1;
    nn.idx=0;
    nn.cost=0;
    q.push_back(nn);

    while(!q.empty()){
	pop_heap(q.begin(),q.end(),cmp);
	cn=q.back();
	q.pop_back();

	if(lmap[cn.idx]==0){
	    lmap[cn.idx]=1;

	    sidx=lidx;
	    lidx=cn.idx;

	    u=gra[cn.idx].size();
	    for(i=0;i<u;i++){
		v=dis(gra[cn.idx][i]);		
		if(lmap[v]==0){
		    cmap[v]+=cgra[cn.idx][i];
		    nn.idx=v;
		    nn.cost=cmap[v];
		    q.push_back(nn);
		    push_heap(q.begin(),q.end(),cmp);
		}
	    }
	}
    }

    return 0;
}
int fus(){
    int i,j;
    int u,v;
    int s,t;
    int tmp;

    s=min(sidx,lidx);
    t=max(sidx,lidx);

    lik[t]=s;

    u=gra[t].size();
    for(i=0;i<u;i++){
	v=gra[t][i];
	tmp=dis(v);
	if(tmp!=s){
	    gra[s].push_back(tmp);
	    cgra[s].push_back(cgra[t][i]);
	}
    }

    return 0;
}
int ru(int idx){
    int i;
    int u,v;

    lmap[idx]=1;

    u=gra[idx].size();
    for(i=0;i<u;i++){
	v=gra[idx][i];
	if(lmap[v]==0){
	    ru(v);
	}
    }

    return 0;
}

int main(){
    int t;
    int a,b,c;

    int i,j;
    int u,v;
    int count;

    int mi;

    count=1;
    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d",&n);
	scanf("%d",&m);

	for(i=0;i<n;i++){
	    gra[i].clear();
	    cgra[i].clear();
	    lik[i]=i;
	}
	for(i=0;i<m;i++){
	    scanf("%d %d %d",&a,&b,&c);
	    a--;
	    b--;

	    if(a!=b){
		gra[a].push_back(b);
		gra[b].push_back(a);
		cgra[a].push_back(c);
		cgra[b].push_back(c);
	    }
	}

	printf("Case #%d: ",count);
	count++;

	for(i=0;i<n;i++){
	    lmap[i]=0;
	}
	ru(0);
	u=0;
	for(i=0;i<n;i++){
	    if(lmap[i]==0){
		printf("0\n");
		u=1;
		break;
	    }
	}   
	if(u==1){
	    continue;
	}

	mi=2147483647;
	for(i=1;i<n;i++){
	    st();
	    mi=min(mi,cmap[lidx]);
	    fus();
	}

	printf("%d\n",mi);
    }

    return 0;
}
