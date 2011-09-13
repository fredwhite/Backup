#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct node{
    unsigned long long int sq;
    unsigned long long int ab;
    unsigned long long int n;
};
struct data{
    int head;
    int w;
};

vector<int> map[1000010];
node tree[1000010];
int decount[1000010];
queue<int> qa;
char lmap[1000010];

vector<int> lastarray;
int father[1000010];

vector<data> o;

bool cmp(data a,data b){
    return a.head<b.head;
}

int main(){
    int i,j;

    int n,m;
    int a,b;
    int u,v;

    int last;

    unsigned long long sq,ab,num;

    unsigned long long mi;
    int miidx;

    data d;

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
	map[i].clear();
    }
    for(i=0;i<m;i++){
	scanf("%d %d",&a,&b);
	map[a].push_back(b);
	map[b].push_back(a);
    }

    lastarray.clear();
    for(i=0;i<n;i++){
	decount[i]=map[i].size();
	lmap[i]=0;
	if(decount[i]==1){
	    qa.push(i);
	}else if(decount[i]==0){
	    lastarray.push_back(i);
	}

	tree[i].sq=0;
	tree[i].ab=0;
	tree[i].n=0;
    }

    while(!qa.empty()){
	a=qa.front();
	qa.pop();

	lmap[a]=1;

	if(decount[a]==0){
	    lastarray.push_back(a);
	}

	u=map[a].size();
	for(i=0;i<u;i++){
	    v=map[a][i];
	    if(lmap[v]==0){
		tree[v].n+=(tree[a].n+1ULL);
		tree[v].ab+=(tree[a].ab+tree[a].n+1ULL);
		tree[v].sq+=(tree[a].sq+2ULL*tree[a].ab+tree[a].n+1ULL);

		decount[v]--;
		if(decount[v]==1){
		    qa.push(v);	
		}
	    }
	}
    }

    o.clear();
    while(!lastarray.empty()){
	last=lastarray.back();
	lastarray.pop_back();

	while(!qa.empty()){
	    qa.pop();
	}

	mi=tree[last].sq;
	miidx=last;
	d.w=1;

	u=map[last].size();
	for(i=0;i<u;i++){
	    v=map[last][i];
	    father[v]=last;
	    qa.push(v);
	}

	while(!qa.empty()){
	    a=qa.front();
	    qa.pop();

	    d.w++;

	    b=father[a];	
	    sq=tree[b].sq-(tree[a].sq+2ULL*tree[a].ab+tree[a].n+1ULL);
	    ab=tree[b].ab-(tree[a].ab+tree[a].n+1ULL);
	    num=tree[b].n-(tree[a].n+1ULL);

	    tree[a].n=tree[a].n+num+1ULL;
	    tree[a].ab=tree[a].ab+ab+num+1ULL;
	    tree[a].sq=tree[a].sq+(sq+2ULL*ab+num+1ULL);

	    if(tree[a].sq<mi){
		mi=tree[a].sq;
		miidx=a;
	    }else if(tree[a].sq==mi && a<miidx){
		miidx=a;
	    }

	    u=map[a].size();
	    for(i=0;i<u;i++){
		v=map[a][i];
		if(v!=b){
		    father[v]=a;
		    qa.push(v);
		}
	    }
	}

	d.head=miidx;
	o.push_back(d);
    }
    sort(o.begin(),o.end(),cmp);

    u=o.size();
    for(i=0;i<u;i++){
	printf("%d %d\n",o[i].head,o[i].w);
    }
	
    return 0;
}
