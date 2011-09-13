#include<stdio.h>
#include<stdlib.h>
#include<deque>

using namespace std;

struct node{
    int h;
    int idx;
};

deque<node> q;
int hl[500010];
int bl[500010];

int sum;

int insert(node a){
    node cn;

    while(!q.empty()){
	cn=q.back();
	if(a.h>cn.h){
	    sum-=bl[cn.idx];
	    q.pop_back();
	}else{
	    break;
	}
    }
    if(!q.empty()){
	if(q.back().h==a.h){
	    sum-=bl[q.back().idx];
	}
    }
    sum+=bl[a.idx];
    q.push_back(a);

    return 0;
}
int remove(int idx){
    int h,b;

    h=hl[idx];
    b=bl[idx];
    if(!q.empty()){
	if(q.front().h==h){
	    q.pop_front();

	    if(!q.empty()){
		if(q.front().h!=h){
		    sum-=b;
		}
	    }else{
		sum-=b;
	    }
	}
    }

    return 0;
}

int main(){
    int n,m;
    int i,j;

    int ma;
    int maidx;

    node nn;

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
	scanf("%d",&hl[i]);
    }
    for(i=0;i<n;i++){
	scanf("%d",&bl[i]);
    }

    sum=0;
    ma=-1;
    maidx=-1;
    for(i=0;i<m;i++){
	nn.h=hl[i];
	nn.idx=i;
	insert(nn);
	if(sum>ma){
	    ma=sum;
	    maidx=i;
	}
    }
    for(i=m;i<n;i++){
	remove(i-m);
	nn.h=hl[i];
	nn.idx=i;
	insert(nn);

	if(sum>ma){
	    ma=sum;
	    maidx=i;
	}
    }
    printf("%d %d\n",maidx+1,ma);

    return 0;
}
