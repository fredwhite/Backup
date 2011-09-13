#include<stdio.h>
#include<stdlib.h>

long long int dp[105][105];

int main(){
    int n,m;
    int i,j;

    while(scanf("%d %d",&n,&m)!=EOF){
	if(n==0 && m==0){
	    break;
	}

	for(i=0;i<=n;i++){
	    dp[i][0]=1LL;
	}

	for(i=1;i<=n;i++){
	    for(j=1;j<=i;j++){
		dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
	    }
	}

	printf("%d things taken %d at a time is %lld exactly.\n",n,m,dp[n][m]);
    }

    return 0;
}
