/*
PROG: profits
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int dp[100005];

int main(){
	freopen("profits.in","r",stdin);
	freopen("profits.out","w",stdout);

	int n;
	int i,j,k;
	int u;
	int ma,mai;

	ma=-2147483640;
	mai=-2147483640;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		scanf("%d",&u);
		if(k==0){
			dp[k]=max(0,u);
		}else{
			if(u+dp[k-1]>=0){
				dp[k]=u+dp[k-1];
			}else{
				dp[k]=0;
			}
		}
		ma=max(dp[k],ma);
		mai=max(mai,u);
	}
	if(ma==0){
		printf("%d\n",mai);
	}else{
		printf("%d\n",ma);
	}

	return 0;
}

