#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>

using namespace std;

int n;

vector<int> gra[250];
vector<long long int> fgra[250];
vector<int> tgra[250];

int h[250];
int gap[250];
long long int pf[250];
int path[205];
int pedge[205];
int scanlog[205];

long long int isap(){
    int i,j;
    int ver;
    int u,v;
    
    long long int flow;

    int now;

    ver=(n+1)*2;
    for(i=0;i<ver;i++){
	h[i]=0;
	pf[i]=0;
	path[i]=i;
	pedge[i]=-1;
	scanlog[i]=0;
    }
    for(i=0;i<=ver;i++){
	gap[i]=0;
    }
    
    flow=0LL;
    pf[0]=3223372036854775807LL;
    now=0;

    while(h[0]<ver){
	if(now==1){
	    flow+=pf[1];

	    u=path[now];
	    while(u!=now){
		scanlog[now]=0;

		v=pedge[now];

		fgra[u][v]-=pf[1];
		fgra[now][tgra[u][v]]+=pf[1];

		now=u;
		u=path[u];
	    }
	    scanlog[now]=0;

	    continue;
	}

	u=gra[now].size();
	for(i=scanlog[now];i<u;i++){
	    v=gra[now][i];
	    if((h[v]+1)==h[now] && fgra[now][i]>0LL){
		scanlog[now]=i+1;

		pf[v]=min(pf[now],fgra[now][i]);	
		path[v]=now;
		pedge[v]=i;

		now=v;
		break;
	    }
	}
	if(i==u){
	    scanlog[now]=0;

	    if(gap[h[now]]==1){
		break;
	    }
	    gap[h[now]]--;

	    h[now]++; 
	    gap[h[now]]++;

	    now=path[now];
	}
    }

    return flow;	
}

int main(){
    int m;
    int i,j;
    int u,v;
    int a,b,c;

    while(scanf("%d",&n)!=EOF){
	u=(n+1)*2;
	for(i=0;i<u;i++){
	    gra[i].clear();
	    fgra[i].clear();
	    tgra[i].clear();
	}

	for(i=1;i<=n;i++){
	    scanf("%d",&c);	    

	    tgra[i*2].push_back(gra[i*2+1].size());
	    tgra[i*2+1].push_back(gra[i*2].size());

	    gra[i*2].push_back(i*2+1);
	    fgra[i*2].push_back(c);

	    gra[i*2+1].push_back(i*2);
	    fgra[i*2+1].push_back(0LL);
	}

	scanf("%d",&m);
	for(i=0;i<m;i++){
	    scanf("%d %d %d",&a,&b,&c);

	    tgra[a*2+1].push_back(gra[b*2].size());
	    tgra[b*2].push_back(gra[a*2+1].size());

	    gra[a*2+1].push_back(b*2);
	    fgra[a*2+1].push_back(c);

	    gra[b*2].push_back(a*2+1);
	    fgra[b*2].push_back(0LL);
	}

	scanf("%d %d",&a,&b);
	for(i=0;i<a;i++){
	    scanf("%d",&c);

	    tgra[0].push_back(gra[c*2].size());
	    tgra[c*2].push_back(gra[0].size());

	    gra[0].push_back(c*2);
	    fgra[0].push_back(3223372036854775807LL);

	    gra[c*2].push_back(0);
	    fgra[c*2].push_back(0LL);
	}
	for(i=0;i<b;i++){
	    scanf("%d",&c);

	    tgra[c*2+1].push_back(gra[1].size());
	    tgra[1].push_back(gra[c*2+1].size());

	    gra[c*2+1].push_back(1);
	    fgra[c*2+1].push_back(3223372036854775807LL);

	    gra[1].push_back(c*2+1);
	    fgra[1].push_back(0LL);
	}

	printf("%lld\n",isap());
    }

    return 0;
}
