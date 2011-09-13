#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>

using namespace std;

vector<int> map[10010];
char lmap[10010];
int top[10010];
int ti;

char amap[10010];
int s;

int ru(int a){
    int i;
    int ct;
    int u,v;
    int mi;
    int flag;
    int tmp;
    int state;

    lmap[a]=1;
    ct=ti;
    top[a]=ti;
    ti++;

    state=0;
    flag=0;
    if(a==0){
	flag=1;
    }
    mi=ct;
    u=map[a].size();
    for(i=0;i<u;i++){
	v=map[a][i];
	if(lmap[v]==0){
	    if(a==0 && state==1){
		flag=0;
	    }

	    state=1;
	    tmp=ru(v);
	    if(a!=0 && tmp<ct){
		flag=1;	
	    }

	    mi=min(mi,tmp);
	}else{
	    mi=min(mi,top[v]); 
	}
    }

    if(flag==0 && state==1){
	s+=1;
	amap[a]=1; 
    }

    return mi;
}

int main(){
    int t;
    int n,m;
    int i,j;
    int u,v;
    int a,b;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d %d",&n,&m);

	for(i=0;i<n;i++){
	    map[i].clear();
	    lmap[i]=0;
	    amap[i]=0;
	}
	s=0;

	for(i=0;i<m;i++){
	    scanf("%d %d",&a,&b);
	    a--;
	    b--;
	    map[a].push_back(b);
	    map[b].push_back(a);
	}

	ru(0);

	printf("%d\n",s);
	if(s==0){
	    printf("0\n");
	}else{
	    u=0;
	    for(i=0;i<n;i++){
		if(amap[i]==1){
		    if(u!=0){
			printf(" ");
		    }
		    u=1;
		    printf("%d",i+1);
		}
	    }
	    printf("\n");
	}
    }

    return 0;
}   
