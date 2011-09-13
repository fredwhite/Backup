#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>

using namespace std;

vector<int> map[30010];
int low[30010];
int lmap[30010];
int st;
int ma;
int ans;

int t;
int ru(int a){
    int i,j;
    int u,v;
    int now;
    int s,c;
    int tmp;

    lmap[a]=t;
    now=t;
    low[a]=t;
    s=1;
    c=0;

    u=map[a].size();
    for(i=0;i<u;i++){
	v=map[a][i];
	if(lmap[v]==0){
	    t++;
	    tmp=ru(v);
	    s+=tmp;
	    if(low[v]==now){
		c+=tmp;
	    }
	    low[a]=min(low[a],low[v]);
	}else if(lmap[v]>0){
	    low[a]=min(low[a],lmap[v]);
	}
    }
    if(a!=st){
	if(c>ma){
	    ma=c;
	    ans=a;
	}else if(c==ma && a<ans){
	    ans=a;
	}
    }
    lmap[a]=-1;

    return s;
}

int main(){
    int n,m;
    int i,j,k;
    int a,b;
    int s;

    while(scanf("%d %d",&n,&m)!=EOF){
	for(i=0;i<n;i++){
	    map[i].clear();
	    lmap[i]=0;
	}
	for(i=0;i<m;i++){
	    scanf("%d %d",&a,&b);
	    a--;
	    b--;
	    map[a].push_back(b);
	    map[b].push_back(a);
	}
	scanf("%d",&st);
	st--;

	t=1;
	ma=0;
	ans=st;
	s=ru(st);
	if(ma==0){
	    printf("0\n");
	}else{
	    printf("%d %d\n",ans+1,s-ma);
	}
    }

    return 0;
}
