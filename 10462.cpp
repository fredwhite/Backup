#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct edge{
    int a;
    int b;
    
    int cost;
    int flag;
};

vector<edge> ed;
vector<int> gra[105];
vector<int> cgra[105];
int li[105];
char log[105];
int map[105][105];
int co;
int root;

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}
int dis(int a){
    if(li[a]==a){
	return a;
    }
    return li[a]=dis(li[a]);
}

int tra(int a){
    int i;
    int u,v;

    log[a]=1;

    co++;

    u=gra[a].size();
    for(i=0;i<u;i++){
	v=gra[a][i];
	
	if(log[v]==0){
	    map[root][v]=max(map[root][a],cgra[a][i]);
	    tra(v); 
	}
    }

    return 0;
}

int main(){
    int t;
    int d,e;

    int i,j;
    int a,b,c;
    int u,v;
    int count;
    long long int mi,org;

    edge ne,cn;

    count=1;
    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d %d",&d,&e);
	for(i=0;i<d;i++){
	    gra[i].clear();
	    cgra[i].clear();
	    li[i]=i;
	}
	ed.clear();

	printf("Case #%d : ",count);
	count++;

	for(i=0;i<e;i++){
	    scanf("%d %d %d",&a,&b,&c);
	    a--;
	    b--;

	    ne.a=a;
	    ne.b=b;
	    ne.cost=c;
	    ne.flag=0;
	    ed.push_back(ne);
	}
	sort(ed.begin(),ed.end(),cmp);
	    
	org=0L;
	for(i=0;i<e;i++){
	    cn=ed[i];
	    u=dis(cn.a);
	    v=dis(cn.b);

	    if(u!=v){
		li[v]=u;
		ed[i].flag=1;

		org+=(long long int)cn.cost;

		gra[cn.a].push_back(cn.b);
		gra[cn.b].push_back(cn.a);
		cgra[cn.a].push_back(cn.cost);
		cgra[cn.b].push_back(cn.cost);
	    }
	}

	for(i=0;i<d;i++){
	    for(j=0;j<d;j++){
		log[j]=0;
	    }
	    root=i;
	    co=0;
	    map[i][i]=0;
	    tra(i);

	    if(co!=d){
		break;
	    }
	}
	if(co!=d){
	    printf("No way\n");
	    continue;
	}

	mi=1099511627776L;
	for(i=0;i<e;i++){
	    cn=ed[i];
	    if(cn.flag==0){
		mi=min(mi,org+(long long int)(cn.cost-map[cn.a][cn.b]));
	    }
	}
	if(mi==1099511627776L){
	    printf("No second way\n");
	}else{
	    printf("%lld\n",mi);
	}
    }

    return 0;
}
