#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

vector<int> gra[100];
vector<int> cgra[100];

queue<int> q;
int flow[100][100];
int lim[100];
int path[100];
char lmap[100];

int tran(char *str){
    if(str[0]=='X'){
	if(str[1]=='X'){
	    return 2;
	}else if(str[1]=='L'){
	    return 3;
	}else if(str[1]=='S'){
	    return 7;
	}
    }else if(str[0]=='L'){
	return 4;
    }else if(str[0]=='M'){
	return 5;
    }else if(str[0]=='S'){
	return 6;
    }
}

int main(){
    int t;
    int n,m;
    int i,j;
    char stra[100],strb[100];

    int a;
    int u,v;
    int sum;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d %d",&n,&m);
	
	u=10+m;
	for(i=0;i<u;i++){
	    gra[i].clear();
	    cgra[i].clear();

	    for(j=0;j<u;j++){
		flow[i][j]=0;
	    }
	}
	u=n/6;
	for(i=2;i<=7;i++){
	    gra[0].push_back(i);
	    cgra[0].push_back(u);
	    gra[i].push_back(0);
	    cgra[i].push_back(u);
	}

	for(i=0;i<m;i++){
	    scanf("%s %s",stra,strb);
	    
	    u=tran(stra); 	    
	    v=tran(strb);

	    gra[u].push_back(i+8);
	    gra[v].push_back(i+8);
	    cgra[u].push_back(1);
	    cgra[v].push_back(1);

	    gra[i+8].push_back(u);
	    gra[i+8].push_back(v);
	    cgra[i+8].push_back(1);
	    cgra[i+8].push_back(1);

	    gra[i+8].push_back(1);
	    cgra[i+8].push_back(1);
	    gra[1].push_back(i+8);
	    cgra[1].push_back(1);
	}

	sum=0;
	while(true){
	    while(!q.empty()){
		q.pop();
	    }
	    u=m+10;
	    for(i=0;i<u;i++){
		lmap[i]=0;
		path[i]=i;
		lim[i]=2147483647;
	    }
	    
	    q.push(0);
	    lmap[0]=1;
	    while(!q.empty()){
		a=q.front();
		q.pop();

		if(a==1){
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
	    if(a!=1){
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
	    sum+=lim[1];
	}

	if(sum>=m){
	    printf("YES\n");
	}else{
	    printf("NO\n");
	}
    }

    return 0;
}
