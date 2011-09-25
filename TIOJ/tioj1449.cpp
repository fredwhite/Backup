#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;

using namespace std;

long long int l[1010];
long long int c[1010][1010];
long long int dp[1010][1010];
int s[1010][1010];

bool cmp(long long int a,long long int b){
    return a<b;
}

int main(){
    int n,m;
    int i,j,k;
    int u,v;

    long long int sum;

    while(scanf("%d %d",&n,&m)!=EOF){
	l[n]=0LL;
	for(i=1;i<n;i++){
	    scanf("%I64d",&l[i]);
	}
	sort(l,l+n,cmp);
	for(i=0;i<n;i++){
	    sum=0LL;
	    c[i][i]=0LL;
	    for(j=i+1;j<n;j++){
		u=(i+j)/2;
		sum+=(l[j]-l[u]);
		c[i][j]=sum;
	    }
	}
	for(i=0;i<n;i++){
	    dp[1][i]=c[0][i];
	    s[1][i]=0;
	}
	for(i=0;i<=m;i++){
	    s[i][n]=n-2;
	}
	
	for(i=2;i<=m;i++){
	    for(j=n-1;j>=0;j--){
		dp[i][j]=3223372036854775807LL;
		for(k=s[i-1][j];k<=s[i][j+1];k++){
		    if(dp[i][j]>dp[i-1][k]+c[k+1][j]){
			dp[i][j]=dp[i-1][k]+c[k+1][j];
			s[i][j]=k;
		    }
		}
	    }
	}

	printf("%I64d\n",dp[m][n-1]);
    }

    return 0;
}
