#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>

using namespace std;

struct node{
    int x;
    int v;
};

node l[1000010];
int c[1000010];
int n;
int ma;

int lowbit(int x){
    return x&(-x);
}
int mo(int x){
    int u;

    u=x+1;
    while(u<=ma){
	c[u]+=1;
	u+=lowbit(u);
    }

    return 0;
}
int query(int x){
    int u;
    int sum;

    u=x+1;
    sum=0;
    while(u>0){
	sum+=c[u];
	u-=lowbit(u);
    }

    return sum;
}

bool cmp(node a,node b){
    return a.x<b.x;
}

int main(){
    int i;
    long long int sum;

    while(scanf("%d",&n)!=EOF){
	ma=-1;
	for(i=0;i<n;i++){
	    scanf("%d %d",&l[i].x,&l[i].v);
	    ma=max(ma,l[i].v);
	}
	sort(l,l+n,cmp);
	ma+=1;

	for(i=0;i<=ma;i++){
	    c[i]=0;
	}

	sum=0;
	for(i=n-1;i>=0;i--){
	    sum+=(long long int)query(l[i].v-1);
	    mo(l[i].v);
	}
	printf("%I64d\n",sum);
    }

    return 0;
}
