/*
PROG: ontherun
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int n;
long long int w[1010];
int dp[1010][1010][2];

bool cmp(long long int a,long long int b){
    return a<b;
}

long long int ru(int a,int b,int c,int x){
    long long int u,v;

    if(dp[a][b][c]!=-1LL){
	return dp[a][b][c];
    }

    u=4223372036854775807LL;
    v=(long long int)(a+(n+2-b));
    if(a>0){
	u=min(u,ru(a-1,b,0,a)+v*(w[x]-w[a]));
    }
    if(b<n+2){
	u=min(u,ru(a,b+1,1,b)+v*(w[b]-w[x]));
    }
    dp[a][b][c]=u;
    
    return u;
}

int main(){
    freopen("ontherun.in","r",stdin);
    freopen("ontherun.out","w",stdout);

    int l;
    int i,j;
    int u,v;

    scanf("%d %d",&n,&l);
    for(i=0;i<n;i++){
	scanf("%lld",&w[i+1]);
    }
    w[n+1]=(long long int)l;
    sort(w+1,w+n+2,cmp);

    u=n+2;
    for(i=0;i<=u;i++){
	for(j=0;j<=u;j++){
	    dp[i][j][0]=-1LL;
	    dp[i][j][1]=-1LL;
	}
    }
    dp[0][u][0]=0LL;
    dp[0][u][1]=0LL;

    for(i=1;i<u;i++){
	if(w[i]==(long long int)l){
	    v=i;
	    break;
	}
    }

    printf("%lld\n",ru(v-1,v+1,0,v));

    return 0;
}
