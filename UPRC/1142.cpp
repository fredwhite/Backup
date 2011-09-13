#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int lw[100010];
int fc[1000010];
int bc[1000010];
int ma;

long long int lowbit(long long int x){
    return (-x)&x;
}

int query(int c[],int a){
    long long int u;
    int sum;

    u=a;
    sum=0;
    while(u>0){
	sum+=c[u];
	u-=lowbit(u);
    }

    return sum;
}
int mo(int c[],int a,int v){
    long long int u;
    
    u=a;
    while(u<=ma){
	c[u]+=v;
	u+=lowbit(u);
    }

    return 0;
}

int main(){
    int i;
    int n;
    int t;
    long long int count,u,v;
    long long int sum;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d",&n);
	ma=0;
	for(i=0;i<n;i++){
	    scanf("%d",&lw[i]);
	    ma=max(ma,lw[i]);
	}
	for(i=1;i<=ma;i++){
	    fc[i]=0;
	    bc[i]=0;
	}
	for(i=1;i<n;i++){
	    mo(bc,lw[i],1);
	}
	mo(fc,lw[0],1);

	sum=0;
	count=n-1;
	for(i=1;i<n;i++){
	    if(lw[i]>1 && lw[i]<1000000){
		u=query(fc,lw[i]-1);
		v=query(bc,lw[i]-1);
		sum+=u*(count-v-1);
		sum+=(i-u)*v;
	    }
	    mo(fc,lw[i],1);
	    mo(bc,lw[i],-1);
	    count--;
	}
	printf("%I64d\n",sum);
    }

    return 0;
}
