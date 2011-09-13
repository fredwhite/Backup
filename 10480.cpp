#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

vector<long long int> gra[55];
vector<long long int> cgra[55];

queue<int> q;
long long int flow[55][55];
long long int lim[55];
char lmap[55];
int path[55];

int main(){
    int n,m;
    int i,j;
    int u,v;
    int a,b,c;
    int flag;
    long long int tmp;

    while(scanf("%d %d",&n,&m)!=EOF){
	if(n==0 && m==0){
	    break;
	}

	for(i=0;i<n;i++){
	    gra[i].clear();
	    cgra[i].clear();
	}
	for(i=0;i<m;i++){
	    scanf("%d %d %d",&a,&b,&c);
	    a--;
	    b--;

	    gra[a].push_back(b);
	    gra[b].push_back(a);
	    cgra[a].push_back(c);
	    cgra[b].push_back(c);
	}

	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		flow[i][j]=0L;
	    }
	}
	while(true){
	    for(i=0;i<n;i++){
		lmap[i]=0;
		lim[i]=2147483647000000L;
		path[i]=i;
	    }
	    while(!q.empty()){
		q.pop();
	    }

	    q.push(0);
	    lmap[0]=1;
	    flag=0;
	    while(!q.empty()){
		a=q.front();
		q.pop();

		if(a==1){
		    flag=1;
		    break;
		}

		u=gra[a].size();
		for(i=0;i<u;i++){
		    v=gra[a][i];
		    if(lmap[v]==0 && flow[a][v]<cgra[a][i]){
			lmap[v]=1;
			lim[v]=min(lim[a],cgra[a][i]-flow[a][v]);

			path[v]=a;
			q.push(v);
		    }
		}
	    }
	    if(flag==0){
		break;
	    }

	    u=1;
	    v=path[1];
	    while(u!=v){
		flow[v][u]+=lim[1];
		flow[u][v]-=lim[1];
		
		u=v;
		v=path[v];
	    }
	}

	for(i=0;i<n;i++){
	    lmap[i]=0;
	}
	while(!q.empty()){
	    q.pop();
	}

	q.push(0);
	lmap[0]=1;
	while(!q.empty()){
	    a=q.front();
	    q.pop();
	    
	    u=gra[a].size();
	    for(i=0;i<u;i++){
		v=gra[a][i];

		if(flow[a][v]>=cgra[a][i]){
		    if(lmap[v]==0){
			lmap[v]=2;
		    }
		}else{
		    if(lmap[v]==0 || lmap[v]==2){
			lmap[v]=1;

			q.push(v);
		    }
		}
	    }
	}

	for(i=0;i<n;i++){
	    if(lmap[i]==2){
		u=gra[i].size();	
		for(j=0;j<u;j++){
		    v=gra[i][j];

		    if(lmap[v]==1){
			printf("%d %d\n",v+1,i+1);
		    }
		}
	    }
	}

	printf("\n");
    }

    return 0;
}
