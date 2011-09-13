/*
PROG: divgold
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>

int dp[2][250005];
int l[251];
char lmap[251][251];

int main(){
	freopen("divgold.in","r",stdin);
	freopen("divgold.out","w",stdout);

	int n;
	int i,j;
	int u,v;
	int s,sum;

	scanf("%d",&n);
	s=0;
	for(i=0;i<n;i++){
		scanf("%d",&l[i+1]);
		s+=l[i+1];
	}
	sum=s;
	s=s/2;

	for(i=0;i<=n;i++){
		for(j=0;j<=s;j++){
			lmap[i][j]=0;
		}
		lmap[i][0]=1;
	}
	for(j=0;j<=s;j++){
		dp[0][j]=0;	
	}
	dp[0][0]=1;

	for(i=1;i<=n;i++){
		u=l[i];
		for(j=0;j<u;j++){
			dp[1][j]=dp[0][j];
			lmap[i][j]=lmap[i-1][j];
		}
		for(j=u;j<=s;j++){
			v=dp[0][j-u]+dp[0][j];
			lmap[i][j]=lmap[i-1][j-u] | lmap[i-1][j];
			if(v>=1000000){
				v=v%1000000;
			}
			dp[1][j]=v;
		}
		for(j=0;j<=s;j++){
			dp[0][j]=dp[1][j];	
		}
	}

	for(i=s;i>=0;i--){
		if(lmap[n][i]!=0){
			printf("%d\n%d\n",(sum-i*2),dp[1][i]);
			break;
		}
	}

	return 0;
}
