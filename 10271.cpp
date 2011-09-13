#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int lw[5010];
int dp[5010][1010];

int main(){
    int t;
    int m,n;
    int i,j,k;
    int u,v;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d %d",&m,&n);
	m+=8;
	for(i=n-1;i>=0;i--){
	    scanf("%d",&lw[i]);
	}

	for(i=0;i<n;i++){
	    for(j=0;j<=m;j++){
		dp[i][j]=1047483640;
	    }
	}
	dp[0][0]=0;
	for(i=1;i<n;i++){
	    for(j=0;j<=m;j++){
		dp[i][j]=min(dp[i][j],dp[i-1][j]);
		if(j>=1 && (i+1)-j*3>=0){
		    u=lw[i]-lw[i-1];
		    u*=u;
		    dp[i][j]=min(dp[i][j],dp[i-2][j-1]+u);
		}
	    }
	}
	printf("%d\n",dp[n-1][m]);
    }

    return 0;
}
