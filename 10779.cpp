#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>

using namespace std;

int m;

int ver;
int l[30];
int sock[30];

vector<int> gra[700];
vector<int> fgra[700];
vector<int> tgra[700];

int h[700];
int pf[700];
int path[700];
int pe[700];
int scanlog[700];
int gap[700];

int isap(){
    int flow;
    int i;
    int u,v;
    int now;
	
    for(i=0;i<700;i++){
	h[i]=0;
	pf[i]=0;
	path[i]=i;
	pe[i]=-1;
	gap[i]=0;
	scanlog[i]=0;
    }
    for(i=0;i<700;i++){
	gap[i]=0;
    }

    flow=0;
    pf[0]=2047483647;
    now=0;
    
    while(h[0]<ver){
	if(now==29){
	    flow+=pf[29];

	    u=path[now];
	    while(u!=now){
		scanlog[now]=0;

		v=pe[now];
		
		fgra[u][v]-=pf[29];
		fgra[now][tgra[u][v]]+=pf[29];

		now=u;
		u=path[u];
	    }
	    scanlog[now]=0;

	    continue;
	}
	
	u=gra[now].size();
	for(i=scanlog[now];i<u;i++){
	    v=gra[now][i];
	    if((h[v]+1)==h[now] && fgra[now][i]>0){
		scanlog[now]=i+1;	

		pf[v]=min(pf[now],fgra[now][i]);
		path[v]=now;
		pe[v]=i;

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
    int t;
    int n;
    int i,j,k;
    int u,v;
    int a,b,c;
    int count;

    scanf("%d",&t);
    count=1;
    for(;t>0;t--){
	scanf("%d %d",&n,&m);

	scanf("%d",&a);

	for(i=0;i<700;i++){
	    gra[i].clear();
	    fgra[i].clear();
	    tgra[i].clear();
	}

	for(i=1;i<=m;i++){
	    tgra[29].push_back(gra[i].size());
	    tgra[i].push_back(gra[29].size());

	    gra[29].push_back(i);
	    fgra[29].push_back(0);

	    gra[i].push_back(29);
	    fgra[i].push_back(1);
	}

	for(i=1;i<=m;i++){
	    l[i]=0;
	}
	for(i=0;i<a;i++){
	    scanf("%d",&b);
	    l[b]++;
	}
	for(i=1;i<=m;i++){
	    if(l[i]>0){
		tgra[0].push_back(gra[i].size());
		tgra[i].push_back(gra[0].size());

		gra[0].push_back(i);
		fgra[0].push_back(l[i]);

		gra[i].push_back(0);
		fgra[i].push_back(0);
	    }
	}

	u=30;
	for(i=1;i<n;i++){
	    scanf("%d",&a);
	    for(j=1;j<=m;j++){
		l[j]=0;
		sock[j]=-1;
	    }
	    for(j=0;j<a;j++){
		scanf("%d",&b);
		l[b]++;
	    }
	    for(j=1;j<=m;j++){
		if(l[j]>1){
		    v=-1;
		    for(k=1;k<=m;k++){
			if(l[k]==0){
			    if(sock[k]==-1){
				sock[k]=u;
				u++;

				tgra[k].push_back(gra[sock[k]].size());
				tgra[sock[k]].push_back(gra[k].size());

				gra[k].push_back(sock[k]);
				fgra[k].push_back(1);

				gra[sock[k]].push_back(k);
				fgra[sock[k]].push_back(0);
			    }

			    if(v==-1){
				v=u;
				u++;

				tgra[v].push_back(gra[j].size());
				tgra[j].push_back(gra[v].size());

				gra[v].push_back(j);
				fgra[v].push_back(l[j]-1);

				gra[j].push_back(v);
				fgra[j].push_back(0);
			    }

			    tgra[sock[k]].push_back(gra[v].size());
			    tgra[v].push_back(gra[sock[k]].size());

			    gra[sock[k]].push_back(v);
			    fgra[sock[k]].push_back(1);

			    gra[v].push_back(sock[k]);
			    fgra[v].push_back(0);
			}
		    }
		}
	    }
	}

	ver=m+2+(u-30);

	printf("Case #%d: %d\n",count,isap());
	count++;
    }

    return 0;
}
