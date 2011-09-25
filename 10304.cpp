#include<stdio.h>
#include<stdlib.h>

int li[300];
int c[300];
int dp[300][300];
int s[300][300];

int ru(int l,int r){
    int i;
    int u,v;

    if(dp[l][r]!=-1){
	return dp[l][r];
    }

    ru(l,r-1);
    ru(l+1,r);

    dp[l][r]=2147483647;
    for(i=s[l][r-1];i<=s[l+1][r];i++){
	u=c[r+1]-c[l]-li[i];
	if(i>l){
	    u+=ru(l,i-1);
	}
	if(i<r){
	    u+=ru(i+1,r);
	}
	if(u<dp[l][r]){
	    dp[l][r]=u;
	    s[l][r]=i;
	}
    }

    return dp[l][r];
}

int main(){
    int n;
    int i,j;

    while(scanf("%d",&n)!=EOF){
	c[0]=0;
	for(i=0;i<n;i++){
	    scanf("%d",&li[i]);
	    c[i+1]=c[i]+li[i];
	}
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		dp[i][j]=-1;
	    }
	    dp[i][i]=0;
	    s[i][i]=i;
	}

	printf("%d\n",ru(0,n-1));
    }

    return 0;   
}
