#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int lw[105];
char dp[105][5110][52];

int main(){
    int n,m;
    int i,j,k;
    int u,v;
    int s;
    int ma,mi;

    int r,l;

    while(scanf("%d %d",&n,&m)!=EOF){
	u=n+m;
	s=0;
	r=2550;
	l=2550;
	for(i=0;i<u;i++){
	    scanf("%d",&lw[i]);
	    s+=lw[i];
	    if(lw[i]>=0){
		l+=lw[i];
	    }else{
		r+=lw[i];
	    }
	}
	for(i=0;i<u;i++){
	    for(j=r;j<=l;j++){
		for(k=0;k<=n;k++){
		    dp[i][j][k]=0; 
		}
	    }
	    dp[i][2550][0]=1;
	}
	dp[0][lw[0]+2550][1]=1;
	for(i=1;i<u;i++){
	    if(lw[i]>=0){
		v=r+lw[i];
		for(j=r;j<v;j++){
		    for(k=0;k<=n;k++){
			dp[i][j][k]=dp[i-1][j][k];
		    }
		}
		for(j=r+lw[i];j<=l;j++){
		    dp[i][j][0]=dp[i-1][j][0];
		    for(k=1;k<=n;k++){
			dp[i][j][k]=dp[i-1][j][k] | dp[i-1][j-lw[i]][k-1];
		    }
		}
	    }else{
		for(j=l+lw[i];j<=l;j++){
		    for(k=0;k<=n;k++){
			dp[i][j][k]=dp[i-1][j][k];
		    }
		}
		for(j=l+lw[i];j>=r;j--){
		    dp[i][j][0]=dp[i-1][j][0];
		    for(k=1;k<=n;k++){
			dp[i][j][k]=dp[i-1][j][k] | dp[i-1][j-lw[i]][k-1];
		    }
		}
	    }
	}
	ma=-2147483640;
	mi=2147483640;
	for(i=r;i<=l;i++){
	    if(dp[u-1][i][n]==1){
		v=i-2550;
		v=(s-v)*v;
		ma=max(ma,v);
		mi=min(mi,v);
	    }
	}
	printf("%d %d\n",ma,mi);
    }

    return 0;
}
