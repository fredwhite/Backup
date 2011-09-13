#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

int n,m;
int map[80][80];
int dp[80][80][3][7];
char ldp[80][80][3];

int ru(int a,int b,int t){
	int i,j;
	int u,v,os;
	int tmp[7];


	if(ldp[a][b][t]==1){
		return 0;
	}
	ldp[a][b][t]=1;
	for(i=0;i<=m;i++){
		dp[a][b][t][i]=-2147483640;
		tmp[i]=-2147483640;
	}
	if(a-1>=0){
		ru(a-1,b,0);
		for(i=0;i<=m;i++){
			tmp[i]=max(tmp[i],dp[a-1][b][0][i]);	
		}
	}	
	if(t!=1 && b-1>=0){
		ru(a,b-1,2);
		for(i=0;i<=m;i++){
			tmp[i]=max(tmp[i],dp[a][b-1][2][i]);	
		}	
	}
	if(t!=2 && b+1<n){
		ru(a,b+1,1);
		for(i=0;i<=m;i++){
			tmp[i]=max(tmp[i],dp[a][b+1][1][i]);	
		}
	}

	if(map[a][b]>=0){
		for(i=0;i<=m;i++){
			if(tmp[i]!=-2147483640){
				dp[a][b][t][i]=tmp[i]+map[a][b];
			}
		}
	}else{
		for(i=1;i<=m;i++){
			if(tmp[i-1]!=-2147483640){
				dp[a][b][t][i]=tmp[i-1]+map[a][b];
			}	
		}
	}

	return 0;
}

int main(){
	int i,j,k,l;
	int c;
	int ma;

	c=1;
	while(true){
		scanf("%d %d",&n,&m);
		if(n==0 && m==0){
			break;
		}
		if(n==0){
			printf("Case %d: impossible\n",c);
			c++;
			continue;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&map[i][j]);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<3;k++){
					ldp[i][j][k]=0;
				}
			}
		}
		ldp[0][0][0]=1;
		ldp[0][0][2]=1;
		for(i=0;i<=m;i++){
			dp[0][0][0][i]=-2147483640;
			dp[0][0][2][i]=-2147483640;
		}

		if(map[0][0]>=0){
			dp[0][0][0][0]=map[0][0];	
			dp[0][0][2][0]=map[0][0];
		}else{
			dp[0][0][0][1]=map[0][0];
			dp[0][0][2][1]=map[0][0];
		}
		ru(n-1,n-1,0);
		ma=-2147483640;
		for(i=0;i<=m;i++){
			ma=max(ma,dp[n-1][n-1][0][i]);
		}
		if(ma==-2147483640){
			printf("Case %d: impossible\n",c);
			c++;
		}else{
			printf("Case %d: %d\n",c,ma);
			c++;
		}
	}

	return 0;
}
