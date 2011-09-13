#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct point{
    int x;
    int y;
};
struct edge{
    point a;
    point b;

    double length;
};
struct node{
    vector<point> v;
    vector<edge> e;

    vector<int> idx;
    vector<double> cost;
};
struct pack{
    int idx;
    double cost;
};

node map[30];
char lmap[30];
double cmap[30];

bool cmp(pack a,pack b){
    return a.cost>b.cost;
}

double length(point a,point b){
    int u,v;

    u=a.x-b.x;
    v=a.y-b.y;
    u=u*u;
    v=v*v;

    return sqrt((double)u+(double)v);
}
int cross(point a,point b,point o){
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
int dot(point a,point b,point o){
    return (a.x-o.x)*(b.x-o.x)+(a.y-o.y)*(b.y-o.y);
}
double dis(point a,edge b){
    if(dot(b.a,a,b.b)>0 && dot(b.b,a,b.a)>0){
	return abs((double)cross(b.a,a,b.b)/b.length);
    }else{
	return min(length(a,b.a),length(a,b.b));
    }

    return -1;
}

int main(){
    int t;
    int ra,rb,n,m;

    int i,j,k,o;
    int u,v;
    point np,lp;
    edge ne;

    double tmp;

    vector<pack> q;
    pack nn,cn;

    scanf("%d",&t);
    for(;t>0;t--){
	for(i=0;i<30;i++){
	    map[i].v.clear();
	    map[i].e.clear();
	    map[i].idx.clear();
	    map[i].cost.clear();
	    cmap[i]=1000000000000000000000.0;
	    lmap[i]=0;
	}

	scanf("%d %d %d",&ra,&rb,&n);
	n+=2;

	scanf("%d %d",&lp.x,&lp.y);
	map[0].v.push_back(lp);
	for(i=1;i<ra;i++){
	    scanf("%d %d",&np.x,&np.y);

	    map[0].v.push_back(np);
	    ne.a=lp;
	    ne.b=np;
	    ne.length=length(ne.a,ne.b);
	    map[0].e.push_back(ne);
	    lp=np;
	}

	scanf("%d %d",&lp.x,&lp.y);
	map[1].v.push_back(lp);
	for(i=1;i<rb;i++){
	    scanf("%d %d",&np.x,&np.y);

	    map[1].v.push_back(np);
	    ne.a=lp;
	    ne.b=np;
	    ne.length=length(ne.a,ne.b);
	    map[1].e.push_back(ne);
	    lp=np;
	}

	for(i=2;i<n;i++){
	    scanf("%d",&m);

	    scanf("%d %d",&lp.x,&lp.y);
	    map[i].v.push_back(lp);
	    for(j=1;j<m;j++){
		scanf("%d %d",&np.x,&np.y);

		map[i].v.push_back(np);
		ne.a=lp;
		ne.b=np;
		ne.length=length(ne.a,ne.b);
		map[i].e.push_back(ne);
		lp=np;
	    }
	    ne.a=lp;
	    ne.b=map[i].v.front();
	    ne.length=length(ne.a,ne.b);
	    map[i].e.push_back(ne);
	}

	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		if(i!=j){
		    u=map[i].v.size();
		    for(k=0;k<u;k++){
			v=map[j].e.size();
			for(o=0;o<v;o++){
			    tmp=dis(map[i].v[k],map[j].e[o]); 
			    map[i].idx.push_back(j);
			    map[i].cost.push_back(tmp);
			    map[j].idx.push_back(i);
			    map[j].cost.push_back(tmp);
			}
		    }
		}
	    }
	}

	q.clear();
	nn.idx=0;	
	nn.cost=0;
	cmap[0]=0;
	q.push_back(nn);
	while(!q.empty()){
	    pop_heap(q.begin(),q.end(),cmp);
	    cn=q.back();
	    q.pop_back();

	    if(lmap[cn.idx]==0){
		lmap[cn.idx]=1;

		if(cn.idx==1){
		    printf("%.3lf\n",cmap[cn.idx]);
		    break;
		}

		u=map[cn.idx].idx.size();
		for(i=0;i<u;i++){
		    v=map[cn.idx].idx[i];
		    if(lmap[v]==0){
			if(cmap[cn.idx]+map[cn.idx].cost[i]<cmap[v]){
			    cmap[v]=cmap[cn.idx]+map[cn.idx].cost[i];
			    nn.idx=v;
			    nn.cost=cmap[v];
			    q.push_back(nn);
			    push_heap(q.begin(),q.end(),cmp);
			}
		    }
		}
	    }
	}
    }

    return 0;
}
