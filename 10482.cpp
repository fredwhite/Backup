#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int lw[33];
char dp[33][642][642];

int main(){
    int t,m;
    int n;
    int i,j,k;
    int u,v;
    int s;
    int mi;

    scanf("%d",&t);
    for(m=0;m<t;m++){
	scanf("%d",&n);
	s=0;
	for(i=0;i<n;i++){
	    scanf("%d",&lw[i]);
	    s+=lw[i];
	}
	for(k=0;k<n;k++){
	    for(i=0;i<=s;i++){
		for(j=0;j<=s;j++){
		    dp[k][i][j]=0;
		}
	    }
	}
	dp[0][lw[0]][0]=1;
	dp[0][0][lw[0]]=1;
	for(k=1;k<n;k++){
	    u=lw[k];
	    for(i=0;i<=s;i++){
		for(j=0;j<=s;j++){
		    dp[k][i][j]=dp[k-1][i][j];
		    if(i>=u){
			dp[k][i][j] |= dp[k-1][i-u][j];
		    }
		    if(j>=u){
			dp[k][i][j] |= dp[k-1][i][j-u];
		    }
		}
	    }
	}
	mi=2147483640;
	for(i=0;i<=s;i++){
	    for(j=0;j<=s;j++){
		u=2147483640;	
		v=-1;
		if(dp[n-1][i][j]==1){
		    u=min(u,i);
		    u=min(u,j);
		    u=min(u,s-i-j);
		    v=max(v,i);
		    v=max(v,j);
		    v=max(v,s-i-j);
		    mi=min(mi,v-u);
		}
	    }
	}
	printf("Case %d: %d\n",m+1,mi);
    }

    return 0;
}
