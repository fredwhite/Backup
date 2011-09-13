#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct edge{
    int a;
    int b;
    int mi;
};

int n,m;
vector<int> gra[30];
vector<edge> ed;
queue<int> q;
int cmap[30][30];
vector<int> sc[30];
int lmap[30][30];

int bfs(int s,int ss,int flag){
    int i;
    int a;
    int u,v;

    while(!q.empty()){
	q.pop();
    }
    for(i=0;i<n;i++){
	cmap[s][i]=2147483647;
    }
    sc[s].clear();

    if(flag==0){
        q.push(s);
	cmap[s][s]=0;
    }else{
	q.push(s);
	cmap[s][s]=0;
	q.push(ss);
	cmap[s][ss]=0;

	lmap[s][ss]=1;
	lmap[ss][s]=1;
    }
    while(!q.empty()){
	a=q.front();
	q.pop();

	u=gra[a].size();
	for(i=0;i<u;i++){
	    v=gra[a][i];
	    if(cmap[s][v]==2147483647){
		lmap[a][v]=1;
		lmap[v][a]=1;

		cmap[s][v]=cmap[s][a]+1;
		sc[s].push_back(v);
		q.push(v);
	    }
	}
    }

    return 0;
}
int cen(int index){
    edge ce;

    int i,j;
    int a,b;
    int u,v;

    ce=ed[index];
    
    u=sc[ce.a].size();
    i=u-1;
    j=u-2;
    while(i>=0 && j>=0){
	a=sc[ce.a][i];
	b=sc[ce.a][j];

	if(cmap[ce.b][a]<cmap[ce.b][b]){
	    ce.mi=min(ce.mi,(1+cmap[ce.a][b]+cmap[ce.b][a]));

	    i=j;
	}

	j--;
    }

    ed[index].mi=ce.mi;
    return 0;
}

int main(){
    int t;

    int i,j;
    int count;
    int a,b;
    edge ne;

    int mi,miidx;
    int ma;

    count=1;
    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d %d",&n,&m);

	if(n==0){
	    printf("Case #%d:\n",count);
	    count++;
	    printf("0\n\n");

	    continue;
	}

	for(i=0;i<n;i++){
	    gra[i].clear();
	}
	ed.clear();

	for(i=0;i<m;i++){
	    scanf("%d %d",&a,&b);
	    gra[a].push_back(b);
	    gra[b].push_back(a);

	    ne.a=a;
	    ne.b=b;
	    ne.mi=2147483647;
	    ed.push_back(ne);
	}

	for(i=0;i<n;i++){
	    bfs(i,0,0);
	}
	mi=2147483647;
	miidx=0;
	for(i=0;i<m;i++){
	    cen(i);
	    if(ed[i].mi<mi){
		mi=ed[i].mi;
		miidx=i;
	    }
	}

	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		lmap[i][j]=0;
	    }
	}
	bfs(ed[miidx].a,ed[miidx].b,1);

	for(i=0;i<n;i++){
	    gra[i].clear();
	}
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		if(lmap[i][j]==1){
		    gra[i].push_back(j);
		}
	    }
	}
	for(i=0;i<n;i++){
	    bfs(i,0,0);
	}

	ma=-1;
	for(i=0;i<n;i++){
	    for(j=i+1;j<n;j++){
		ma=max(ma,cmap[i][j]);
	    }
	}

	printf("Case #%d:\n",count);
	count++;
	printf("%d\n\n",ma);
    }

    return 0;
}
