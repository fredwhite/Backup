#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

char map[105][105];
int dp[105][105][256];

int main(){
    int t,m,n,q;
    int i,j,k;
    char c;
    int a,b;
    int ma;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d %d %d",&m,&n,&q);

	for(i=0;i<m;i++){
	    scanf("%c",&c);
	    for(j=0;j<n;j++){
		scanf("%c",&map[i][j]);
		for(k=0;k<256;k++){
		    dp[i][j][k]=0;
		}
		dp[i][j][map[i][j]]=1;
	    }
	}
	for(i=1;i<m;i++){
	    for(j=1;j<n;j++){
		c=map[i][j];
		dp[i][j][c]=min(min(dp[i-1][j][c],dp[i][j-1][c]),dp[i-1][j-1][c])+1;	
	    }
	}

	printf("%d %d %d\n",m,n,q);

	for(k=0;k<q;k++){
	    scanf("%d %d",&a,&b);
	    c=map[a][b];
	    ma=1;
	    a++;
	    b++;
	    while(a<m && b<n){
		if(dp[a][b][c]<(ma+2)){
		    break;
		}

		ma+=2;
		a++;
		b++;
	    }
	    printf("%d\n",ma);
	}   
    }

    return 0;
}
