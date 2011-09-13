#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

int dp[5005];
int tdp[5005];
int n,m;

vector<int> q;
vector<int> map[505];

int c[505];
int b[505];

int ru(int a){
    int i;
    int u,v;

    for(i=0;i<=m;i++){
	tdp[i]=dp[i];
    }
    for(i=c[a];i<=m;i++){
	if(tdp[i-c[a]]>-1){
	    dp[i]=tdp[i-c[a]]+b[a];
	}
    }
    u=map[a].size();
    for(i=0;i<u;i++){
	ru(map[a][i]);
    }

    for(i=0;i<=m;i++){
	dp[i]=max(dp[i],tdp[i]);
    }
    
    return 0;
}


int main(){
    int t;
    int i,j;
    int s;
    int u,v;
    int ma;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d %d",&n,&m);
    
	q.clear();
	for(i=0;i<n;i++){
	    map[i].clear();
	}
	for(i=0;i<n;i++){
	    scanf("%d %d %d",&s,&c[i],&b[i]);
	    if(s==0){
		q.push_back(i);
	    }else{
		s--;
		map[s].push_back(i);
	    }
	}

	for(i=0;i<=m;i++){
	    dp[i]=-1;
	}
	dp[0]=0;

	u=q.size();
	for(i=0;i<u;i++){
	    ru(q[i]);
	}
	ma=0;
	for(i=0;i<=m;i++){
	    printf("%d ",dp[i]);
	    ma=max(ma,dp[i]);
	}
	printf("\n");
	printf("%d\n",ma);
    }

    return 0;
}
