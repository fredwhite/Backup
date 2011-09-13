#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;

struct node{
    int idx;
    int type;

    int x;
    int h;
};

vector<node> house;
vector<node> q;
char lmap[30010];

bool cmpa(node a,node b){
    if(a.x==b.x){
	return a.type<b.type;
    }

    return a.x<b.x;
}
bool cmpb(node a,node b){
    return a.h<b.h;
}

node get(){
    node cn;

    cn=q.front();
    while(lmap[cn.idx]==1){
	pop_heap(q.begin(),q.end(),cmpb);
	q.pop_back();

	if(q.empty()){
	    cn.x=-1;
	    return cn;
	}

	cn=q.front();
    }

    return cn;
}

int main(){
    int n;
    int i,j;
    int l,h,r;
    int u;

    int ma;
    int now;

    node cn,nn;

    while(scanf("%d",&n)!=EOF){
	if(n==0){
	    break;
	}

	house.clear();

	for(i=0;i<n;i++){
	    scanf("%d %d %d",&l,&h,&r);
	    nn.idx=i;
	    nn.type=0;
	    nn.x=l;
	    nn.h=h;
	    house.push_back(nn);

	    nn.idx=i;
	    nn.type=1;
	    nn.x=r;
	    nn.h=h;
	    house.push_back(nn);

	    lmap[i]=0;
	}	
	sort(house.begin(),house.end(),cmpa);

	q.clear();
	q.push_back(house[0]);
	push_heap(q.begin(),q.end(),cmpb);

	printf("%d %d",house[0].x,house[0].h);
	ma=house[0].h;
	now=house[0].idx;
	u=house.size();
	for(i=1;i<u;i++){
	    if(house[i].type==0){
		q.push_back(house[i]);
		push_heap(q.begin(),q.end(),cmpb);

		if(house[i].h>ma){
		    ma=house[i].h;
		    now=house[i].idx;
		    printf(" %d %d",house[i].x,house[i].h);
		}
	    }else{
		lmap[house[i].idx]=1;
		if(house[i].idx==now){
		    cn=get();
		    if(cn.x==-1){
			printf(" %d 0",house[i].x);
			ma=0;
			now=-1;
		    }else{
			if(cn.h!=ma){
			    printf(" %d %d",house[i].x,cn.h);
			}
			ma=cn.h;
			now=cn.idx;
		    }
		}
	    }
	}
	printf("\n");
    }
    return 0;
}
