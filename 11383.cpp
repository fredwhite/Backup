#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>

using namespace std;

int n;
int lx[505],ly[505];
char vx[505],vy[505];
int mx[505],my[505];
int xmap[505][505];
queue<int> q;
int minl[505];
int minx[505];
int path[505];

int update(){
    int i,j;
    int u;

    for(i=0;i<n;i++){
	if(vx[i]==1){
	    for(j=0;j<n;j++){
		u=lx[i]+ly[j]-xmap[i][j];
		if(u<minl[j]){
		    minl[j]=u;
		    minx[j]=i;
		}
	    }
	}
    }

    return 0;
}
int change(){
    int i;
    int u;

    u=2147483647;
    for(i=0;i<n;i++){
	if(vy[i]==0){
	    u=min(u,minl[i]);
	}
    }
    for(i=0;i<n;i++){
	if(vx[i]==1){
	    lx[i]-=u;
	}
	if(vy[i]==1){
	    ly[i]+=u;
	}else if(vy[i]==0){
	    minl[i]-=u;
	}
    }

    return 0;
}
int track(int x,int y){
    int u,v;
    int tmp;

    u=x;
    v=y;
    while(u!=-1){
	my[v]=u;		
	tmp=mx[u];
	mx[u]=v;
	v=tmp;

	u=path[u];
    }

    return 0;
}

int ru(int a){
    int i,j;
    int u,v;

    for(i=0;i<n;i++){
	vx[i]=0;
	vy[i]=0;
	minl[i]=2147483647;
	minx[i]=-1;
	path[i]=-1;
    }
    while(!q.empty()){
	q.pop();
    }

    q.push(a);
    vx[a]=1;
    update();

    while(!q.empty()){
	while(!q.empty()){
	    u=q.front();
	    q.pop();

	    for(i=0;i<n;i++){
		if(vy[i]==0 && xmap[u][i]==(lx[u]+ly[i])){
		    if(my[i]==-1){
			track(u,i);
			return 1;
		    }

		    v=my[i];
		    vx[v]=1;
		    vy[i]=1;
		    path[v]=u;
		    update();
		    q.push(v);
		}
	    }
	}
	change();
	for(i=0;i<n;i++){
	    if(vy[i]==0 && minl[i]==0){
		if(my[i]==-1){
		    track(minx[i],i);
		    return 1;
		}

		v=my[i];
		vx[v]=1;
		vy[i]=1;
		path[v]=minx[i];
		update();
		q.push(v);
	    }
	}
    }

    return 0;
}

int main(){
    int t;

    int i,j;
    int u,v;

    for(t=0;t<15;t++){
	scanf("%d",&n);

	for(i=0;i<n;i++){
	    u=-2147483647;
	    for(j=0;j<n;j++){
		scanf("%d",&xmap[i][j]);
		xmap[i][j]=xmap[i][j];
		u=max(u,xmap[i][j]);
	    }
	    mx[i]=-1;
	    my[i]=-1;
	    lx[i]=u;
	    ly[i]=0;
	}

	for(i=0;i<n;i++){
	    if(mx[i]==-1){
		ru(i);
	    }
	}

	printf("%d",lx[0]);
	for(i=1;i<n;i++){
	    printf(" %d",lx[i]);
	}
	printf("\n%d",ly[0]);
	for(i=1;i<n;i++){
	    printf(" %d",ly[i]);
	}
	printf("\n");

	u=0;
	for(i=0;i<n;i++){
	    u+=lx[i]+ly[i];
	}
	printf("%d\n",u);
    }

    return 0;
}
