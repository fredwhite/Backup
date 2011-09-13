#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stra[100];
char strb[100];
char strc[100];

int dp[100][100][100];

int main(){
    int t;
    int i,j,k;

    int u,v;
    int la,lb,lc;
    int sum;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%s %s %s",stra,strb,strc);
	
	la=strlen(stra);
	lb=strlen(strb);
	lc=strlen(strc);

	for(k=0;k<lc;k++){
	    for(i=0;i<=la;i++){
		for(j=0;j<=lb;j++){
		    dp[k][i][j]=0;
		}
	    }
	}
	for(i=1;i<=la;i++){
	    if(stra[i-1]==strc[0]){
		dp[0][i][0]=1;
	    }
	}
	for(i=1;i<=lb;i++){
	    if(strb[i-1]==strc[0]){
		dp[0][0][i]=1;
	    }
	}

	for(k=1;k<lc;k++){
	    for(i=0;i<=la;i++){
		u=dp[k-1][i][0];
		for(j=1;j<=lb;j++){
		    if(strb[j-1]==strc[k]){
			dp[k][i][j]+=u;
			dp[k][i][j]%=10007;
		    }
		    u+=dp[k-1][i][j];
		    u%=10007;
		}
	    }
	    for(i=0;i<=lb;i++){
		u=dp[k-1][0][i];
		for(j=1;j<=la;j++){
		    if(stra[j-1]==strc[k]){
			dp[k][j][i]+=u;
			dp[k][j][i]%=10007;
		    }
		    u+=dp[k-1][j][i];
		    u%=10007;
		}   
	    }
	}

	sum=0;
	for(i=0;i<=la;i++){
	    for(j=0;j<=lb;j++){
		sum+=dp[k-1][i][j];
		sum%=10007;
	    }
	}
	printf("%d\n",sum);

    }

    return 0;
}
