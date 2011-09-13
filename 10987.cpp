#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

struct edge{
    int ia;
    int ib;
    int l;
};
struct node{
    int idx;
    int cost;
};

int n;
vector<edge> e;
vector<int> gra[105];
vector<int> cgra[105];
vector<edge> o;

char lmap[105];
int cmap[105];

bool cmp(edge a,edge b){
    return a.l<b.l;
}
bool cmpb(node a,node b){
    return a.cost>b.cost;
}
bool cmpc(edge a,edge b){
    if(a.ia==b.ia){
	return a.ib<b.ib;
    }
    return a.ia<b.ia;
}
int sp(int s,int t){
    int i;
    int u,v;

    int ret;
    vector<node> q;
    node nn,cn;

    for(i=0;i<n;i++){
	lmap[i]=0;
	cmap[i]=2147483647;
    }

    ret=-2147483647;
    nn.idx=s;
    nn.cost=0;
    q.clear();
    q.push_back(nn);
    while(!q.empty()){
	pop_heap(q.begin(),q.end(),cmpb);
	cn=q.back();
	q.pop_back();

	if(lmap[cn.idx]==0){
	    lmap[cn.idx]=1;

	    if(cn.idx==t){
		ret=cn.cost;
		break;
	    }

	    u=gra[cn.idx].size();
	    for(i=0;i<u;i++){
		v=gra[cn.idx][i];
		if(lmap[v]==0 && (cn.cost+cgra[cn.idx][i])<cmap[v]){
		    cmap[v]=cn.cost+cgra[cn.idx][i];
		    nn.idx=v;
		    nn.cost=cmap[v];
		    q.push_back(nn);
		    push_heap(q.begin(),q.end(),cmpb);
		}
	    }
	}
    }

    return ret;
}

int main(){
    int t;
    int i,j;
    int u,v;
    int a,b;
    int flag;
    int count;

    edge ne,ce;

    count=1;
    scanf("%d",&t);
    for(;t>0;t--){
	printf("Case #%d:\n",count);
	count++;

	e.clear();
	o.clear();
	scanf("%d",&n);
	for(i=1;i<n;i++){
	    for(j=0;j<i;j++){
		ne.ia=j;
		ne.ib=i;
		scanf("%d",&ne.l);
		e.push_back(ne);
	    }
	}
	sort(e.begin(),e.end(),cmp);

	for(i=0;i<n;i++){
	    gra[i].clear();
	    cgra[i].clear();
	}

	flag=0;
	u=e.size();
	for(i=0;i<u;i++){
	    a=e[i].ia;
	    b=e[i].ib;

	    v=sp(a,b);
	    if(v==-2147483647){
		gra[a].push_back(b);
		gra[b].push_back(a);
		cgra[a].push_back(e[i].l);
		cgra[b].push_back(e[i].l);

		o.push_back(e[i]);
	    }else{
		if(v<e[i].l){
		    printf("Need better measurements.\n"); 
		    flag=1;
		    break;
		}else if(v>e[i].l){
		    gra[a].push_back(b);
		    gra[b].push_back(a);
		    cgra[a].push_back(e[i].l);
		    cgra[b].push_back(e[i].l); 	

		    o.push_back(e[i]);
		}
	    }
	}

	if(flag==0){
	    sort(o.begin(),o.end(),cmpc);
	    u=o.size();
	    printf("%d\n",u);
	    for(i=0;i<u;i++){
		printf("%d %d %d\n",o[i].ia+1,o[i].ib+1,o[i].l);
	    }
	}
	printf("\n");
    }

    return 0;
}
