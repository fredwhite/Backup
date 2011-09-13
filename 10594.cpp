#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct node{
    int idx;
    long long int cost;
};

int l[5010][3];

vector<int> gra[150];
vector<int> fgra[150];
vector<int> cgra[150];
vector<int> tgra[150];

queue<node> q;
int path[150];
int pe[150];
long long int cmap[150];

int main(){
    int n,m;
    int i,j;
    int a,b,c;

    int u,v;

    int flow;
    long long int cost;
    int tf;
    node nn,cn;

    while(scanf("%d %d",&n,&m)!=EOF){
	for(i=0;i<n;i++){
	    gra[i].clear();
	    fgra[i].clear();
	    cgra[i].clear();
	    tgra[i].clear();
	}
	for(i=0;i<m;i++){
	    scanf("%d %d %d",&l[i][0],&l[i][1],&l[i][2]);
	    l[i][0]--;
	    l[i][1]--;
	}
	scanf("%d %d",&a,&b);
	for(i=0;i<m;i++){
	    u=l[i][0];
	    v=l[i][1];
	    c=l[i][2];

	    tgra[u].push_back(gra[v].size());
	    tgra[v].push_back(gra[u].size());

	    gra[u].push_back(v);
	    fgra[u].push_back(b);
	    cgra[u].push_back(c);

	    gra[v].push_back(u);
	    fgra[v].push_back(b);
	    cgra[v].push_back(c);
	}

	flow=a;
	cost=0LL;
	while(flow>0){
	    while(!q.empty()){
		q.pop();
	    }

	    for(i=0;i<n;i++){
		path[i]=i;
		pe[i]=-1;
		cmap[i]=10000000000000000LL;
	    }

	    cmap[0]=0LL;
	    nn.idx=0;
	    nn.cost=0LL;
	    q.push(nn);

	    while(!q.empty()){
		cn=q.front();
		q.pop();

		if(cn.cost==cmap[cn.idx]){
		    u=gra[cn.idx].size();
		    for(i=0;i<u;i++){
			v=gra[cn.idx][i];
			if(fgra[cn.idx][i]>0){
			    if(fgra[cn.idx][i]>b){
				if((cmap[cn.idx]-(long long int)cgra[cn.idx][i])<cmap[v]){
				    cmap[v]=cmap[cn.idx]-(long long int)cgra[cn.idx][i];
				    path[v]=cn.idx;
				    pe[v]=i;
				    nn.idx=v;
				    nn.cost=cmap[v];
				    q.push(nn);
				}
			    }else if(fgra[cn.idx][i]>0){
				if((cmap[cn.idx]+(long long int)cgra[cn.idx][i])<cmap[v]){
				    cmap[v]=cmap[cn.idx]+(long long int)cgra[cn.idx][i];
				    path[v]=cn.idx;
				    pe[v]=i;
				    nn.idx=v;
				    nn.cost=cmap[v];
				    q.push(nn);
				}
			    }
			}
		    }
		}
	    }
	    if(cmap[n-1]==10000000000000000LL){
		break;
	    }

	    tf=flow;
	    v=n-1;
	    u=path[v];
	    while(u!=v){
		if(fgra[u][pe[v]]>b){
		    tf=min(tf,fgra[u][pe[v]]-b);
		}else{
		    tf=min(tf,fgra[u][pe[v]]);
		}

		v=u;
		u=path[u];
	    }

	    v=n-1;
	    u=path[v];
	    while(u!=v){
		if(fgra[u][pe[v]]>b){
		    cost-=cgra[u][pe[v]]*(long long int)tf;
		}else{
		    cost+=cgra[u][pe[v]]*(long long int)tf;
		}

		fgra[u][pe[v]]-=tf;
		fgra[v][tgra[u][pe[v]]]+=tf;

		v=u;
		u=path[u];
	    }

	    flow-=tf;
	}

	if(flow==0){
	    printf("%lld\n",cost);
	}else{
	    printf("Impossible.\n");
	}
    }

    return 0;
}
