#include<stdio.h>
#include<stdlib.h>
#include<deque>
#include<algorithm>

using namespace std;

struct node{
    long long int x;
    int v;
};

node l[3010];
deque<node> q[3010];
int dp[3010][3010];

bool cmp(node a,node b){
    return a.x<b.x;
}

int insert(int idx,long long int x,int v){
    node nn;

    while(!q[idx].empty()){
	if(q[idx].back().v<v){
	    q[idx].pop_back();
	}else{
	    break;
	}
    }
    nn.x=x;
    nn.v=v;
    q[idx].push_back(nn);

    return 0;
}

int remove(int idx,long long int x){
    
    while(!q[idx].empty()){
	if(q[idx].front().x<x){
	    q[idx].pop_front();
	}else{
	    break;
	}
    }

    return 0;
}

int main(){
    int n,k;
    long long int x,d;

    int i,j;
    int ma;

    scanf("%d %d %I64d %I64d",&n,&k,&x,&d);

    for(i=0;i<n;i++){
	scanf("%I64d %d",&l[i].x,&l[i].v);
    }
    sort(l,l+n,cmp);

    insert(0,0,0);
    for(i=1;i<=k;i++){
	insert(i,0,-2147483647);
    }

    for(i=0;i<n;i++){
	for(j=0;j<=k;j++){
	    remove(j,l[i].x-d);
	}
	for(j=1;j<=k;j++){
	    dp[i][j]=q[j-1].front().v+l[i].v;
	}
	for(j=0;j<=k;j++){
	    insert(j,l[i].x,dp[i][j]);
	}
    }
    ma=-2147483647;
    for(i=0;i<n;i++){
	if((l[i].x+d)>=x){
	    if(ma<dp[i][k]){
		ma=dp[i][k];
	    }
	}
    }
    printf("%d\n",ma);

    return 0;
}
