#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

unsigned int l[100010];
unsigned int dp[100010][17];
unsigned int dpm[100010][17];
int table[100010];

int main(){
    int n,m;

    int i,j;
    int u,v;
    int a,b;
    int t;

    double tmp;

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
	scanf("%u",&l[i]);
	dp[i][0]=l[i];
	dpm[i][0]=l[i];
    }

    j=1;
    u=1;
    while(u<n){
	for(i=0;(i+u)<n;i++){
	    dp[i][j]=max(dp[i][j-1],dp[i+u][j-1]);
	    dpm[i][j]=min(dpm[i][j-1],dpm[i+u][j-1]);
	}
	u=1<<j;
	j++;
    }

    tmp=log(2.0);
    for(i=0;i<100010;i++){
	table[i]=(int)(log((double)(i))/tmp);
    }

    for(i=0;i<m;i++){
	scanf("%d %d",&u,&v);
	a=min(u,v);
	b=max(u,v);
	a--;
	b--;

	t=table[b-a+1];
	printf("%u\n",max(dp[a][t],dp[b-(1<<t)+1][t])-min(dpm[a][t],dpm[b-(1<<t)+1][t]));
    }

    return 0;
}
