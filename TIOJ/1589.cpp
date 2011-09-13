#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>

using namespace std;

vector<int> map[260];
long long int dp[260];
int in[260];
char lmap[260];

queue<int> q;

int main(){
    int i,j;
    int v,e;
    long long int m;
    int a,b;
    int u,tmp;
    int s,t;

    scanf("%d %d %I64d",&v,&e,&m);
    for(i=0;i<v;i++){
	in[i]=0;
	dp[i]=0;
	lmap[i]=0;
    }
    for(i=0;i<e;i++){
	scanf("%d %d",&a,&b);	
	map[a].push_back(b);
    }

    scanf("%d %d",&s,&t);
    while(!q.empty()){
	q.pop();
    }
    q.push(s);
    lmap[s]=1;
    while(!q.empty()){
	a=q.front();
	q.pop();

	u=map[a].size();
	for(i=0;i<u;i++){
	    tmp=map[a][i];
	    in[tmp]++;
	    if(lmap[tmp]==0){
		lmap[tmp]=1;
		q.push(tmp);
	    }
	}
    }

    while(!q.empty()){
	q.pop();
    }
    q.push(s);
    dp[s]=1;
    while(!q.empty()){
	a=q.front();
	q.pop();

	u=map[a].size();	
	for(i=0;i<u;i++){
	    tmp=map[a][i];
	    in[tmp]--;
	    dp[tmp]=(dp[tmp]+dp[a])%m;
	    if(in[tmp]==0){
		q.push(tmp);
	    }
	}
    }
    printf("%I64d\n",dp[t]);

    return 0;
}
