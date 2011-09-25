#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>

using namespace std;

int n,m;

long long int l[5010];
vector<int> ogra[5010];
vector<int> gra[5010];
vector<int> tgra[5010];
vector<long long int> cgra[5010];

int hl[5010];
int gap[5010];
long long int pf[5010];
int path[5010];
int pt[5010];
int scan[5010];

char lmap[5010];

long long int isap(){
    long long int flow;
    int i;
    int ver;
    int u,v;
    int now;

    ver=n+2;

    for(i=0;i<=ver;i++){
	hl[i]=0;
	gap[i]=0;
	pf[i]=3223372036854775807LL;
	path[i]=-1;
	pt[i]=-1;
	scan[i]=0;
    }
    
    hl[0]=1;
    path[0]=0;
    flow=0LL;
    now=0;
    while(hl[0]<ver){
	if(now==(n+1)){
	    u=path[now];
	    while(u!=now){
		v=pt[now];

		cgra[u][v]-=pf[n+1];
		cgra[now][tgra[u][v]]+=pf[n+1];

		scan[now]=0;

		now=u;
		u=path[u];
	    }
	    scan[now]=0;
	    flow+=pf[n+1];
	    continue;
	}

	u=gra[now].size();
	for(i=scan[now];i<u;i++){
	    v=gra[now][i];
	    if(hl[now]==(hl[v]+1) && cgra[now][i]>0LL){
		pf[v]=min(pf[now],cgra[now][i]);
		path[v]=now;
		pt[v]=i;
		scan[now]=i+1;

		now=v;
		break;
	    }
	}
	if(i==u){
	    scan[now]=0;

	    gap[hl[now]]--;
	    if(gap[hl[now]]==0){
		return flow;
	    }
	    hl[now]++;
	    gap[hl[now]]++;

	    now=path[now];
	}
    }

    return flow;
}

int ru(int a){
    int i;
    int u,v;

    lmap[a]=1;

    u=gra[a].size();
    for(i=0;i<u;i++){
	v=gra[a][i];
	if(lmap[v]==0 && cgra[a][i]>0LL){
	    ru(v);
	}
    }

    return 0;
}

int main(){
    int i,j;
    int u,v;

    long long int sum;

    while(scanf("%d %d",&n,&m)!=EOF){
	u=n+2;
	for(i=0;i<u;i++){
	    ogra[i].clear();
	    gra[i].clear();
	    cgra[i].clear();
	    tgra[i].clear();
	}
	sum=0LL;
	for(i=0;i<n;i++){
	    scanf("%I64d",&l[i+1]);

	    if(l[i+1]>=0LL){
		tgra[0].push_back(gra[i+1].size());
		tgra[i+1].push_back(gra[0].size());

		gra[0].push_back(i+1);
		cgra[0].push_back(l[i+1]);
		gra[i+1].push_back(0);
		cgra[i+1].push_back(0LL);

		sum+=l[i+1];
	    }else{
		tgra[i+1].push_back(gra[n+1].size());
		tgra[n+1].push_back(gra[i+1].size());

		gra[i+1].push_back(n+1);
		cgra[i+1].push_back(-l[i+1]);
		gra[n+1].push_back(i+1);
		cgra[n+1].push_back(0LL);
	    }
	}
	for(i=0;i<m;i++){
	    scanf("%d %d",&u,&v);

	    ogra[u].push_back(v);

	    tgra[v].push_back(gra[u].size());
	    tgra[u].push_back(gra[v].size());

	    gra[v].push_back(u);
	    cgra[v].push_back(0LL);
	    gra[u].push_back(v);
	    cgra[u].push_back(3223372036854775807LL);
	}

	sum=sum-isap();

	for(i=0;i<=n;i++){
	    lmap[i]=0;
	}
	lmap[n+1]=0;

	ru(0);	
	u=0;
	for(i=1;i<=n;i++){
	    if(lmap[i]==1){
		u++;
	    }
	}
	printf("%d %I64d\n",u,sum);

    }

    return 0;
}
