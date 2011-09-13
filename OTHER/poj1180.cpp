#include<stdio.h>
#include<stdlib.h>
#include<deque>
#include<iostream>

using namespace std;

long long int dp[10010];
int tl[10010];
int fl[10010];

deque<int> q;

long long int fa(int a,int b){
    return dp[a]-dp[b];
}
long long int ga(int a,int b){
    return tl[a]-tl[b];
}

int main(){
    int n;
    int s;
    int i,j;
    int t,f;
    int u,v;

    scanf("%d",&n);
    scanf("%d",&s);

    u=0;
    v=0;
    for(i=0;i<n;i++){
	scanf("%d %d",&tl[i],&fl[i]);
	dp[i]=4223372036854775807LL;
    }
    for(i=n-2;i>=0;i--){
	tl[i]=tl[i]+tl[i+1];
	fl[i]=fl[i]+fl[i+1];
    }

    tl[n]=0;
    dp[n]=0LL;

    q.clear();

    q.push_back(n);

    for(i=n-1;i>=0;i--){
	u=q.size();
	while(u>1){
	    if(fa(q[1],q[0])<=(long long int)fl[i]*ga(q[1],q[0])){
		q.pop_front();
	    }else{
		break;
	    }
	    u--;
	}

	dp[i]=dp[q[0]]+(long long int)(s+tl[i]-tl[q[0]])*(long long int)fl[i];

	u=q.size();
	while(u>0){
	    if(fa(i,q[u-1])<=(long long int)fl[i]*ga(i,q[u-1])){
		q.pop_back();
	    }else if(u>1 && fa(q[u-1],q[u-2])*ga(i,q[u-1])>=fa(i,q[u-1])*ga(q[u-1],q[u-2])){
		q.pop_back();
	    }else{
		break;
	    }
	    u--;
	}

	q.push_back(i);
    }

    /*for(i=n-1;i>=0;i--){
	for(j=n;j>i;j--){
	    dp[i]=min(dp[i],dp[j]+(long long int)(s+tl[i]-tl[j])*(long long int)fl[i]); 
	}
    }*/

    printf("%I64d\n",dp[0]);

    return 0;
}
