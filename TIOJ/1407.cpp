#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node{
    int w;
    int m;
    int c;
};

long long int dp[1000010];
node l[100010];

int main(){
    int n;
    int w,m,c,t;
    int i,j,k;
    int u,v;
    long long int ma;

    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%d %d %d",&l[i].w,&l[i].m,&l[i].c);	
    }
    scanf("%d",&t);
    for(i=0;i<=t;i++){
	dp[i]=-72057594037927936LL;
    }
    dp[0]=0;

    for(k=0;k<n;k++){
	u=l[k].c;
	v=1;
	while(u>0){
	    w=l[k].w*v;
	    m=l[k].m*v;

	    for(i=t;i>=w;i--){
		dp[i]=max(dp[i-w]+(long long int)m,dp[i]);
	    }

	    u-=v;
	    if(u>v*2){
		v*=2;
	    }else{
		v=u;
	    }
	}
    }

    ma=0;
    for(i=0;i<=t;i++){
	ma=max(ma,dp[i]);
    }
    printf("%I64d\n",ma);

    return 0;
}

