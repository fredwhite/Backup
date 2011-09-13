#include<stdio.h>
#include<stdlib.h>

unsigned long long int dp[95][20];

int main(){
    int n,m;
    int i,j;
    unsigned long long int sum;

    while(scanf("%d %d",&n,&m)!=EOF){
	for(i=0;i<=m;i++){
	    for(j=0;j<=n;j++){
		dp[i][j]=0;
	    }
	}

	dp[0][0]=1;
	for(i=1;i<=m;i++){
	    for(j=0;j<=n;j++){
		dp[i][0]+=dp[i-1][j];
	    }
	    for(j=1;j<=n;j++){
		dp[i][j]+=dp[i-1][j-1];
	    }
	}

	sum=0;
	for(i=0;i<=n;i++){
	    sum+=dp[m][i];
	}
	printf("%I64u\n",sum);

    }

    return 0;
}
