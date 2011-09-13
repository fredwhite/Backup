#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>

using namespace std;

struct edge{
    int a;
    int b;
};
vector<edge> ed;
char lmap[55];
int n,m;
int ans;

int ru(int a,int sum,int count){
    int flag;

    if(count==n){
	ans=min(ans,sum);
	return 0;
    }
    if((sum+1)>=ans){
	return 0;
    }
    if(a>=m){
	return 0;
    }

    ru(a+1,sum,count);

    flag=0;
    if(lmap[ed[a].a]==0){
	flag+=1;
    }
    if(lmap[ed[a].b]==0 && ed[a].a!=ed[a].b){
	flag+=1;
    }
    if(flag>0){
	lmap[ed[a].a]++;
	lmap[ed[a].b]++;

	ru(a+1,sum+1,count+flag);

	lmap[ed[a].a]--;
	lmap[ed[a].b]--;
    }

    return 0;
}

int main(){
    int a,b;
    int i,j;

    edge ne;

    while(scanf("%d %d",&n,&m)!=EOF){
	for(i=0;i<n;i++){
	    lmap[i]=0;
	}
	ed.clear();
	for(i=0;i<m;i++){
	    scanf("%d %d",&ne.a,&ne.b);
	    ed.push_back(ne);
	}

	ans=2147483647;
	ru(0,0,0);
	if(ans==2147483647){
	    printf("-1\n");
	}else{
	    printf("%d\n",ans);
	}
    }

    return 0;
}
