#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

struct node{
    int i;
    int j;
    int num;
};

int n;
vector<node> l;
char lmap[160][160];
char cmap[160][160];
queue<node> q;

bool cmp(node a,node b){
    return a.num<b.num;
}

int check(){
    int i,j;

    node nn,cn;

    if(lmap[0][0]==0){
	return 0;
    }

    while(!q.empty()){
	q.pop();
    }
    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	    cmap[i][j]=0;
	}
    }

    nn.i=0;
    nn.j=0;
    q.push(nn);
    cmap[0][0]=1;
    while(!q.empty()){
	cn=q.front();
	q.pop();

	if((cn.i-1)>=0){
	    i=cn.i-1;
	    j=cn.j;

	    if(cmap[i][j]==0 && lmap[i][j]==1){
		if(i==(n-1) && j==(n-1)){
		    return 1;
		}

		cmap[i][j]=1;
		nn.i=i;
		nn.j=j;
		q.push(nn);
	    }
	}
	if((cn.j+1)<n){
	    i=cn.i;
	    j=cn.j+1;

	    if(cmap[i][j]==0 && lmap[i][j]==1){
		if(i==(n-1) && j==(n-1)){
		    return 1;
		}

		cmap[i][j]=1;
		nn.i=i;
		nn.j=j;
		q.push(nn);
	    }
	}
	if((cn.i+1)<n){
	    i=cn.i+1;
	    j=cn.j;

	    if(cmap[i][j]==0 && lmap[i][j]==1){
		if(i==(n-1) && j==(n-1)){
		    return 1;
		}

		cmap[i][j]=1;
		nn.i=i;
		nn.j=j;
		q.push(nn);
	    }
	}
	if((cn.j-1)>=0){
	    i=cn.i;
	    j=cn.j-1;

	    if(cmap[i][j]==0 && lmap[i][j]==1){
		if(i==(n-1) && j==(n-1)){
		    return 1;
		}

		cmap[i][j]=1;
		nn.i=i;
		nn.j=j;
		q.push(nn);
	    }
	}
    }

    return 0;
}

int main(){
    int i,j;
    int u,v;

    int a,b;
    int mi;

    node nn;

    l.clear();

    scanf("%d",&n);

    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	    nn.i=i;
	    nn.j=j;

	    scanf("%d",&nn.num);
	    l.push_back(nn);

	    lmap[i][j]=0;
	}
    }

    if(n==1){
	printf("0\n");
	return 0;
    }

    sort(l.begin(),l.end(),cmp);

    mi=2147483647;

    u=l.size();

    j=0;
    a=l[0].num;
    b=l[0].num;
    for(i=0;i<u;i++){
	if(a!=l[i].num){
	    while(check()==1){
		mi=min(mi,l[i-1].num-l[j].num);

		while(b==l[j].num && j<i){
		    lmap[l[j].i][l[j].j]=0;
		    j++;
		}
		b=l[j].num;
	    }
	    a=l[i].num;
	}
	lmap[l[i].i][l[i].j]=1;
    }
    while(check()==1){
	mi=min(mi,l[i-1].num-l[j].num);

	while(b==l[j].num && j<i){
	    lmap[l[j].i][l[j].j]=0;
	    j++;
	}
	b=l[j].num;
    }

    printf("%d\n",mi);

    return 0;
}
