#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

struct edge{
    int a;
    int b;
    int cost;
};

int pt[505][2];
int map[505][505];
vector<edge> q;

int link[505];

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
    int t,n,m;
    int i,j;
    int u,v;
    int a,b;
    int ma;

    edge ne;

    scanf("%d",&t);
    for(;t>0;t--){
	q.clear();
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
	    scanf("%d %d",&pt[i][0],&pt[i][1]);
	}
	for(i=0;i<n;i++){
	    for(j=i+1;j<n;j++){
		u=pt[i][0]-pt[j][0];
		v=pt[i][1]-pt[j][1];
		u*=u;
		v*=v;
		map[i][j]=u+v;

		ne.a=i;
		ne.b=j;
		ne.cost=u+v;
		q.push_back(ne);
	    }
	    link[i]=i;
	}
	sort(q.begin(),q.end(),cmp);
	u=q.size();
	m-=1;
	j=0;
	ma=0;
	for(i=0;i<u;i++){
	    a=dis(q[i].a);
	    b=dis(q[i].b);
	    if(a!=b){
		link[b]=a;
		
		if(((n-1)-j)>m){
		    ma=q[i].cost;
		}

		j++;
		if(j==n-1){
		    break;
		}
	    }
	}
	printf("%.2lf\n",sqrt(ma));
    }

    return 0;
}
