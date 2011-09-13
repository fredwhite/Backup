#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<string.h>

using namespace std;

int s,m,n;
int t;

int cost[130];
vector<int> sub[130];

long long int dp[130][65546];

long long int ru(int deep,int x){
    int i;
    int u,v;
    int o;
    int tmp;

    if(deep>=t){
	if(dp[deep][x]!=-1){
	    return dp[deep][x];
	}
	if(deep==m){
	    return 60000000;
	}

	dp[deep][x]=ru(deep+1,x);
    }else{
	dp[deep][x]=60000000;
    }

    o=x;
    u=sub[deep].size();
    for(i=0;i<u;i++){
	v=sub[deep][i];

	tmp=(1<<v);
	if((x&tmp)==tmp){
	    tmp=(1<<(v+8));
	    if((x&tmp)==0){
		o=o|tmp;
	    }
	}else{
	    o=o|tmp;
	}
    }
    dp[deep][x]=min(dp[deep][x],(long long int)cost[deep]+ru(deep+1,o));

    return dp[deep][x];
}

int main(){
    int i,j;
    long long int u,v;
    char str[500],*pch;
    int a;

    while(true){
	scanf("%d %d %d",&s,&m,&n);
	if(s==0){
	    break;
	}
	gets(str);
	t=m;
	m+=n;

	for(i=0;i<=m;i++){
	    for(j=0;j<65546;j++){
		dp[i][j]=-1;
	    }
	    u=((1<<s)-1)+(((1<<(s+8))-1)&0xFF00);
	    dp[i][u]=0;
	}

	for(i=0;i<m;i++){
	    sub[i].clear();
	}

	for(i=0;i<m;i++){
	    gets(str);
	    pch=strtok(str," ");
	    sscanf(pch,"%d",&cost[i]);
	    pch=strtok(NULL," ");
	    while(pch!=NULL){
		sscanf(pch,"%d",&a);
		a--;
		sub[i].push_back(a);
		pch=strtok(NULL," ");
	    }
	}

	u=ru(0,0);
	if(u>=60000000){
	    while(true);
	}

	printf("%lld\n",u);

    }

    return 0;
}
