#include<stdio.h>
#include<stdlib.h>
#include<deque>

using namespace std;

long long int w[500010];
long long int dp[500010];
long long int sum[500010];
deque<int> q;

long long int ff(int a,int b){
    return dp[b]-dp[a]+sum[a]-sum[b]+b*w[b+1]-a*w[a+1];
}
long long int fg(int a,int b){
    return w[b+1]-w[a+1];
}

int main(){
    int t;
    int n,m;

    int i,j;
    int u,v;
    long long int f,g;
    int flag;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d %d",&n,&m);

	w[0]=0LL;
	dp[0]=0LL;
	sum[0]=0LL;

	for(i=0;i<n;i++){
	    scanf("%I64d",&w[i+1]);
	    sum[i+1]=sum[i]+w[i+1];
	}

	u=m*2;
	for(i=m;i<u;i++){
	    dp[i]=sum[i]-i*w[1];
	}
	q.clear();
	q.push_back(0);

	for(i=m*2;i<=n;i++){
	    while(q.size()>1){
		if(i*fg(q[0],q[1])>=ff(q[0],q[1])){
		    q.pop_front();
		}else{
		    break;
		}
	    }

	    u=i-m;
	    v=q.size();
	    while(true){
		if(v>0 && i*fg(q[v-1],u)>=ff(q[v-1],u)){
		    q.pop_back();
		    v--;
		}else if(v>1 && ff(q[v-2],q[v-1])*fg(q[v-1],u)>=ff(q[v-1],u)*fg(q[v-2],q[v-1])){
		    q.pop_back();
		    v--;
		}else{
		    break;
		}
	    }
	    q.push_back(u);

	    dp[i]=dp[q[0]]+(sum[i]-sum[q[0]])-(i-q[0])*w[q[0]+1];
	}
	printf("%I64d\n",dp[n]);
    }

    return 0;
}
