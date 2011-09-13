#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

struct edge{
    int a;
    int b;
};

vector<edge> e;
vector<int> gra[2505];
int count[2505];
int first[2505];
int second[2505];
char lmap[2505];
queue<int> q;

int main(){
    int t,n;
    int i,j;
    int u,v,w;
    int a,b;
    int tmp,ma;

    int flag;
    int ca,cb;
    int ansa,ansb,ansidx;

    edge ne;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    gra[i].clear();
	}
	e.clear();
	for(i=1;i<n;i++){
	    scanf("%d %d",&a,&b);
	    a--;
	    b--;
	    gra[a].push_back(b);
	    gra[b].push_back(a);

	    ne.a=a;
	    ne.b=b;
	    e.push_back(ne);
	}

	ma=2147483647;
	w=e.size();
	for(i=0;i<w;i++){
	    for(j=0;j<n;j++){
		count[j]=0;
		lmap[j]=0;
		first[j]=0;
		second[j]=0;
	    }
	    count[e[i].a]=1;
	    count[e[i].b]=1;
    
	    while(!q.empty()){
		q.pop();
	    }
	    for(j=0;j<n;j++){
		if((gra[j].size()-count[j])<=1){
		    q.push(j);
		}
	    }

	    tmp=0;
	    b=0;
	    flag=0;
	    while(!q.empty()){
		a=q.front();
		q.pop();
		lmap[a]=1;

		if(gra[a].size()-count[a]==0){
		    b+=first[a];
		    tmp=max(tmp,first[a]+second[a]);
		    if(flag==0){
			ca=a;

			flag=1;
		    }else{
			cb=a;
			break;
		    }
		    continue;
		}

		u=gra[a].size();
		for(j=0;j<u;j++){
		    v=gra[a][j];
		    if(lmap[v]==0 && (a!=e[i].a || v!=e[i].b) && (a!=e[i].b || v!=e[i].a)){
			count[v]+=1;

			if(first[a]+1>first[v]){
			    second[v]=first[v];
			    first[v]=first[a]+1;
			}else if(first[a]+1>second[v]){
			    second[v]=first[a]+1;
			}

			if(gra[v].size()-count[v]==1){
			    q.push(v);
			}
			break;
		    }
		}
	    }

	    tmp=max(tmp,b+1);
	    if(tmp<ma){
		ma=tmp;
		ansa=ca;
		ansb=cb;
		ansidx=i;
	    }
	}
	printf("%d\n",ma);
	printf("%d %d\n",min(e[ansidx].a,e[ansidx].b)+1,max(e[ansidx].a,e[ansidx].b)+1);
	printf("%d %d\n",min(ansa,ansb)+1,max(ansa,ansb)+1);
    }

    return 0;
}
