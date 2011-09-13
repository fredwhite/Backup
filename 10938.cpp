#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

vector<int> gra[5005];
int lmap[5005];
int parent[5005];
queue<int> q,tq;

int bfs(int s){
    int i;

    int a;
    int u,v;
    int count;

    while(!q.empty()){
	q.pop();
    }
    while(!tq.empty()){
	tq.pop();
    }
    q.push(s);
    count=0;
    parent[s]=-100;
    while(true){
	while(!q.empty()){
	    a=q.front();
	    q.pop();

	    if(count==lmap[a]){
		return 100000+a;
	    }else if(count==lmap[a]+1){
		return 300000+a;
	    }
	    lmap[a]=count;

	    u=gra[a].size();
	    for(i=0;i<u;i++){
		v=gra[a][i];

		if(v!=parent[a]){
		    parent[v]=a;
		    tq.push(v);
		}
	    }
	}
	if(tq.size()==0){
	    break;
	}
	while(!tq.empty()){
	    q.push(tq.front());
	    tq.pop();
	}
	count++;
    }

    return 0;
}

int main(){
    int n,l;

    int i,j;
    int a,b;
    int u;

    while(scanf("%d",&n)!=EOF){
	if(n==0){
	    break;
	}
	for(i=0;i<n;i++){
	    gra[i].clear();
	}
	for(i=1;i<n;i++){
	    scanf("%d %d",&a,&b);
	    a--;
	    b--;

	    gra[a].push_back(b);
	    gra[b].push_back(a);
	}
	scanf("%d",&l);
	for(i=0;i<l;i++){
	    scanf("%d %d",&a,&b);
	    a--;
	    b--;

	    for(j=0;j<n;j++){
		lmap[j]=-100;
	    }
	    bfs(a);
	    u=bfs(b);
	    if(u<200000){
		printf("The fleas meet at %d.\n",u-100000+1);
	    }else{
		u-=300000;
		if(u<0){
		    printf("The fleas jump forever between %d and %d.\n",min(a,b)+1,max(a,b)+1);
		}else{
		    printf("The fleas jump forever between %d and %d.\n",min(u,parent[u])+1,max(u,parent[u])+1);
		}
	    }
	}
    }

    return 0;
}
