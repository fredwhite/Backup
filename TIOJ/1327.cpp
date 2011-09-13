#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;

struct node{
    long long int x;
    long long int y;
    int idx;
};
struct edge{
    int s;
    int d;
    long long int cost;
};

node map[100010];
vector<edge> es;
int link[100010];

bool cmpx(node a,node b){
    if(a.x==b.x){
	return a.y<b.y;
    }

    return a.x<b.x;
}
bool cmpy(node a,node b){
    if(a.y==b.y){
	return a.x<b.x;
    }

    return a.y<b.y;
}
bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

int dis(int a){
    if(link[a]==a){
	return a;
    }
    return link[a]=dis(link[a]);
}

int main(){
    int t,n;
    int i,j;
    int u,v;
    long long int tmp;
    long long int flag;
    int a,b;
    long long int cost;

    edge ne;

    scanf("%d",&t);
    for(;t>0;t--){
	es.clear();

	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("%I64d %I64d",&map[i].x,&map[i].y);
	    map[i].idx=i;
	    link[i]=i;
	}

	sort(map,map+n,cmpx);
	flag=map[0].x;
	tmp=map[0].y;
	for(i=1;i<n;i++){
	    if(map[i].x==flag){
		ne.s=map[i-1].idx;
		ne.d=map[i].idx;
		ne.cost=map[i].y-tmp;
		es.push_back(ne);
	    }
	    flag=map[i].x;
	    tmp=map[i].y;
	}
	sort(map,map+n,cmpy);
	flag=map[0].y;
	tmp=map[0].x;
	for(i=1;i<n;i++){
	    if(map[i].y==flag){
		ne.s=map[i-1].idx;
		ne.d=map[i].idx;
		ne.cost=map[i].x-tmp;
		es.push_back(ne);
	    }
	    flag=map[i].y;
	    tmp=map[i].x;
	}

	sort(es.begin(),es.end(),cmp);
	u=es.size();
	cost=0;
	for(i=0;i<u;i++){
	    a=dis(es[i].s);
	    b=dis(es[i].d);
	    if(a!=b){
		link[b]=a;
		cost+=es[i].cost;
	    }
	}

	printf("%I64d\n",cost);
    }
    return 0;
}
