#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

struct node{
    int idx;
    int cost;
};

int n;

int l[25];

vector<int> gra[25];
vector<int> cgra[25];
int cmap[25];
char lmap[25];
vector<node> q;

vector<int> wl;
char dpa[1300][1300],dpb[1300][1300];

bool cmp(node a,node b){
    return a.cost>b.cost;
}

int dij(){
    node nn,cn;
    int i;
    int u,v;

    q.clear();
    for(i=0;i<n;i++){
	lmap[i]=0;
	cmap[i]=2147483647;
    }

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

	    u=gra[cn.idx].size();
	    for(i=0;i<u;i++){
		v=gra[cn.idx][i];
		if(lmap[v]==0 && cmap[v]>(cmap[cn.idx]+cgra[cn.idx][i])){
		    cmap[v]=cmap[cn.idx]+cgra[cn.idx][i];
		    
		    nn.idx=v;
		    nn.cost=cmap[v];
		    q.push_back(nn);
		    push_heap(q.begin(),q.end(),cmp);
		}
	    }
	}
    }

    return 0;
}
    
int main(){
    int t;
    int count;
    int flag;

    int i,j,k;
    int u,v;
    int a,b,c;

    int sum;
    int mi;
    int ma;

    count=1;
    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d",&n);

	l[0]=0;
	for(i=1;i<n;i++){
	    scanf("%d",&l[i]);
	}
	for(i=0;i<n;i++){
	    gra[i].clear();
	    cgra[i].clear();
	}
	while(true){
	    scanf("%d %d %d",&a,&b,&c);
	    if(a==0 && b==0 && c==0){
		break;
	    }
	    a--;
	    b--;

	    gra[a].push_back(b);
	    gra[b].push_back(a);
	    cgra[a].push_back(c);
	    cgra[b].push_back(c);
	}   

	printf("Test Case #: %d\n",count);
	count++;	

	dij();

	flag=0;
	for(i=0;i<n;i++){
	    if(lmap[i]==0){
		flag=1;
		break;
	    }
	}
	if(flag==1){
	    printf("Too few trucks\n");
	    continue;
	}

	ma=0;
	sum=0;
	wl.clear();
	for(i=1;i<n;i++){
	    for(j=0;j<l[i];j++){
		v=cmap[i]*2;
		wl.push_back(v);
		sum+=v;
		ma=max(ma,v);
	    }
	}
	/*for(i=1;i<n;i++){
	    b=0;
	    u=cmap[i];
	    v=l[i]*cmap[i]*2;
	    sum+=v;
	    ma=max(ma,v);
	    while(true){
		if(b+u>v){
		    if(v-b>0){
			wl.push_back(v-b);
		    }
		    break;
		}

		b+=u;
		wl.push_back(u);
		u=u*2;
	    }
	}*/

	a=min(1200,sum/3+ma);

	for(i=0;i<=a;i++){
	    for(j=0;j<=a;j++){
		dpa[i][j]=0;
		dpb[i][j]=0;
	    }
	}

	u=wl.size();
	dpa[0][0]=1;
	dpb[0][0]=1;
	for(k=0;k<u;k++){
	    for(i=0;i<=a;i++){
		for(j=0;j<=a;j++){
		    if(dpa[i][j]==1){
			if(i+wl[k]<=a){
			    dpb[i+wl[k]][j]=1;
			}
			if(j+wl[k]<=a){
			    dpb[i][j+wl[k]]=1;
			}
		    }
		}
	    }

	    for(i=0;i<=a;i++){
		for(j=0;j<=a;j++){
		    dpa[i][j]=dpb[i][j];
		}
	    }
	}

	mi=2147483647;
	for(i=0;i<=a;i++){
	    for(j=0;j<=a;j++){
		if(dpb[i][j]==1){
		    v=i;
		    v=max(v,j);
		    v=max(v,sum-(i+j));
		    mi=min(mi,v);
		}
	    }
	}
	
	if(mi>1200){
	    printf("Too few trucks\n");
	}else{
	    printf("%d mins\n",mi);
	}
    }

    return 0;
}
