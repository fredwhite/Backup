#include<stdio.h>
#include<stdlib.h>

long long int dp[760][760];

long long int ru(int a,int b){
    int i;

    if(dp[a][b]!=-1){
	return dp[a][b];
    }

    dp[a][b]=0;
    for(i=b;i<=a;i+=2){
	dp[a][b]+=ru(a-i,i);
    }

    return dp[a][b];
}

int main(){
    int m,n;
    int i,j;

    while(scanf("%d",&m)!=EOF){
    for(;m>0;m--){
	scanf("%d",&n);
	for(i=0;i<=n;i++){
	    for(j=0;j<=n;j++){
		dp[i][j]=-1;
	    }
	}
	for(i=0;i<=n;i++){
	    dp[0][i]=1;
	}
	printf("%lld\n",ru(n,1));
    }
    }

    return 0;
}
