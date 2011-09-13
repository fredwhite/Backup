#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int l[105]; 
int dp[105][105];
int table[210];

int ru(int l,int r){
    int sum;
    int i;
    
    if(dp[l][r]!=-1){
	return dp[l][r];
    }

    sum=-1;
    if(table[r-l+1]==0){
	for(i=l;i<r;i++){
	    sum=max(sum,ru(l,i)+ru(i+1,r));	
	}
    }else{
	for(i=l;i<r;i++){
	    sum=max(sum,ru(l,i)*ru(i+1,r));
	}
    }

    dp[l][r]=sum;

    return dp[l][r];
}

int main(){
    int n;
    int i,j;
    int u,v;

    while(scanf("%d",&n)!=EOF){
	for(i=0;i<n;i++){
	    scanf("%d",&l[i]);
	}
    
	u=i*2+5;
	v=0;
	for(i=0;i<u;i++){
	    table[i]=v;
	    if(v==0){
		v=1;
	    }else{
		v=0;
	    }
	}

	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		dp[i][j]=-1;
	    }
	    dp[i][i]=l[i];
	}
	printf("%d\n",ru(0,n-1));
    }

    return 0;
}
