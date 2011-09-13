#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;

struct edge{
    int s;
    int d;
    int cost;
};

int map[1010][1010];
vector<edge> es;
int link[1010];

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
    int x,y;
    int c;
    int tmp;
    int u,v;
    int a,b;
    int cost;

    edge ce,ne;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d",&n);

	es.clear();

	for(i=0;i<1010;i++){
	    for(j=0;j<1010;j++){
		map[i][j]=-1;
	    }
	}
	c=0;
	for(i=0;i<n;i++){
	    scanf("%d %d",&x,&y);
	    map[x][y]=c;
	    c++;
	}
	for(i=0;i<c;i++){
	    link[i]=i;
	}

	for(i=0;i<1010;i++){
	    x=-1;
	    y=-1;
	    tmp=-1;
	    for(j=0;j<1010;j++){
		if(map[i][j]!=-1){
		    if(x!=-1 && y!=-1){
			ne.s=tmp;
			ne.d=map[i][j];
			ne.cost=(j-y);
			es.push_back(ne);
		    }
		    x=i;
		    y=j;
		    tmp=map[i][j];
		}
	    }
	}
	for(j=0;j<1010;j++){
	    x=-1;
	    y=-1;
	    tmp=-1;
	    for(i=0;i<1010;i++){
		if(map[i][j]!=-1){
		    if(x!=-1 && y!=-1){
			ne.s=tmp;
			ne.d=map[i][j];
			ne.cost=(i-x);
			es.push_back(ne);
		    }
		    x=i;
		    y=j;
		    tmp=map[i][j];
		}
	    }
	}
	sort(es.begin(),es.end(),cmp);

	cost=0;
	u=es.size();
	for(i=0;i<u;i++){
	    a=dis(es[i].s);
	    b=dis(es[i].d);

	    if(a!=b){
		link[b]=a;
		cost+=es[i].cost;
	    }
	}
	printf("%d\n",cost);

    }

    return 0;
}
