#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

int map[205][205];
int l[1010];

long long int dp[2][205][205];

int main(){
    int n,m;
    int u,v;

    int i,j,k;
    int a,b,c;

    long long int mi;

    scanf("%d",&m);
    for(i=0;i<m;i++){
	for(j=0;j<m;j++){
	    scanf("%d",&map[i][j]);
	}
    }
    n=0;
    while(scanf("%d",&l[n])!=EOF){
	l[n]--;
	n++;
    }

    for(i=0;i<m;i++){
	for(j=0;j<m;j++){
	    dp[0][i][j]=1223372036854775807LL;
	    dp[1][i][j]=1223372036854775807LL;
	}
    }

    if(l[0]!=0){
	dp[0][1][2]=min(dp[0][1][2],(long long int)map[0][l[0]]);	
    }else{
	dp[0][1][2]=0LL;
    }
    if(l[0]!=1){
	dp[0][0][2]=min(dp[0][0][2],(long long int)map[1][l[0]]);
    }else{
	dp[0][0][2]=0LL;
    }
    if(l[0]!=2){
	dp[0][0][1]=min(dp[0][0][1],(long long int)map[2][l[0]]);
    }else{
	dp[0][0][1]=0LL;
    }

    for(k=1;k<n;k++){
	u=l[k-1];
	for(i=0;i<m;i++){
	    for(j=i;j<m;j++){

		a=min(i,u);
		b=max(i,u);
		if(j!=l[k]){
		    dp[1][a][b]=min(dp[1][a][b],dp[0][i][j]+(long long int)map[j][l[k]]);
		}else{
		    dp[1][a][b]=min(dp[1][a][b],dp[0][i][j]);
		}

		a=min(j,u);
		b=max(j,u);
		if(i!=l[k]){
		    dp[1][a][b]=min(dp[1][a][b],dp[0][i][j]+(long long int)map[i][l[k]]);
		}else{
		    dp[1][a][b]=min(dp[1][a][b],dp[0][i][j]);
		}

		if(u!=l[k]){
		    dp[1][i][j]=min(dp[1][i][j],dp[0][i][j]+(long long int)map[u][l[k]]);
		}else{
		    dp[1][i][j]=min(dp[1][i][j],dp[0][i][j]);
		}
	    }
	}
	for(i=0;i<m;i++){
	    for(j=0;j<m;j++){
		dp[0][i][j]=dp[1][i][j];
		dp[1][i][j]=1223372036854775807LL;
	    }
	}
    }

    mi=1223372036854775807LL;
    for(i=0;i<m;i++){
	for(j=0;j<m;j++){
	    mi=min(mi,dp[0][i][j]);
	}
    }
    printf("%I64d\n",mi);

    return 0;
}
