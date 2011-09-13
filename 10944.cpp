#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<iostream>

using namespace std;

struct point{
    int x;
    int y;
};

int cmap[22][22];
int lmap[22];
vector<point> q;
int num;
int src;
int dp[18][131072];

int ru(int a,int s){
    int i;
    int u;

    if(dp[a][s]!=-1){
	return dp[a][s];
    }

    if(s==((1<<num)-1)){
	return dp[a][s]=cmap[a][src];
    }

    dp[a][s]=1147483640;
    for(i=0;i<num;i++){
	if(a!=i && lmap[i]==0){
	    u=s;
	    u=u | 1<<i;
	    lmap[i]=1;
	    dp[a][s]=min(dp[a][s],cmap[a][i]+ru(i,u));
	    lmap[i]=0;
	}
    }

    return dp[a][s];
}

int main(){
    int xn,yn;
    int i,j,k,o;
    int u,v;
    int a,b;
    char c;
    point np,cp;

    while(scanf("%d %d",&yn,&xn)!=EOF){
	num=0;
	src=-1;
	q.clear();
	for(i=0;i<yn;i++){
	    scanf("%c",&c);
	    for(j=0;j<xn;j++){
		scanf("%c",&c);
		if(c=='L'){
		    src=num;
		    num++;
		    np.x=j;
		    np.y=i;
		    q.push_back(np);
		}else if(c=='#'){
		    num++;
		    np.x=j;
		    np.y=i;
		    q.push_back(np);
		}
	    }
	}
	if(src==-1){
	    printf("0\n");
	    continue;
	}
	for(i=0;i<num;i++){
	    for(j=0;j<num;j++){
		cmap[i][j]=-1;
	    }
	}
	for(o=0;o<num;o++){
	    cp=q[o];
	    for(i=0;i<num;i++){
		if(i!=o){
		    a=abs(q[i].x-cp.x);
		    b=abs(q[i].y-cp.y);
		    v=a;
		    if(a<b){
			v=v+b-a;	
		    }
		    cmap[o][i]=v;
		}
	    }
	}
	for(i=0;i<num;i++){
	    for(j=0;j<131072;j++){
		dp[i][j]=-1;
	    }
	    lmap[i]=0;
	}
	lmap[src]=1;
	u=ru(src,1<<src);
	if(u==-1){
	    printf("0\n");
	}else{
	    printf("%d\n",u);
	}
    }

    return 0;
}
