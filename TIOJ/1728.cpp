#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct li{
    li *next;    
    int num;
};

struct node{
    node *lt;
    node *rt;
    int l;
    int r;

    int num;
    int count;

    int mid;
};

char lmap[10000010];
int log[10000010][2];

li lpool[10000010];
li head;

int dp[10000010][2];

node pool[40001000];
int poolptr;

node* query(node *root,int l,int r){
    int mid;
    int ma;

    node *a;
    node *b;

    if(root->l==l && root->r==r){
	return root;
    }

    a=NULL;
    b=NULL;

    mid=root->mid;
    if(l<=mid){
	a=query(root->lt,l,min(mid,r));
    }
    if(r>mid){
	b=query(root->rt,max(mid+1,l),r);
    }

    if(b==NULL){
	return a;
    }else if(a==NULL){
	return b;
    }else{

	if(a->count>b->count){
	    return a;
	}else if(a->count<b->count){
	    return b;
	}else{
	    if(a->num>b->num){
		return a;
	    }else{
		return b;
	    }
	}
    }
    return NULL;
}
node* build(int l,int r){
    int mid;
    node *nn;

    nn=&pool[poolptr];
    poolptr++;
    if(l==r){
	nn->lt=NULL;
	nn->rt=NULL;
	nn->l=l;
	nn->r=r;
	nn->mid=l;

	nn->num=l;
	nn->count=dp[l][1];

	return nn;
    }

    mid=(l+r)/2;
    nn->lt=build(l,mid);
    nn->rt=build(mid+1,r);
    nn->l=l;
    nn->r=r;
    nn->mid=mid;

    if(nn->lt->count>nn->rt->count){
	nn->num=nn->lt->num;
	nn->count=nn->lt->count;
    }else if(nn->lt->count<nn->rt->count){
	nn->num=nn->rt->num;
	nn->count=nn->rt->count;
    }else{
	if(nn->lt->num>nn->rt->num){
	    nn->num=nn->lt->num;
	    nn->count=nn->lt->count;
	}else{
	    nn->num=nn->rt->num;
	    nn->count=nn->rt->count;
	}
    }

    return nn;
}

int main(){
    int i,j;
    int u,v;

    li *pl,*cl,*hl;

    int a,b;

    head.next=&lpool[0];
    lpool[0].num=2;
    j=1;
    for(i=3;i<=5000000;i++){
	lpool[j].num=i;
	lpool[j-1].next=&lpool[j];
	j++;
    }
    lpool[j-1].next=NULL;

    for(i=0;i<10000010;i++){
	lmap[i]=0;
    }

    log[1][0]=-1;
    log[1][1]=-1;

    hl=head.next;
    while(hl!=NULL){
	u=hl->num;
	pl=&head;
	cl=hl;

	log[u][0]=u;
	log[u][1]=1;
	lmap[u]=1;

	while(cl!=NULL){
	    v=u*(cl->num);
	    if(v>10000000){
		pl->next=NULL;
		break;
	    }

	    log[v][0]=u;
	    log[v][1]=cl->num;
	    lmap[v]=1;

	    if(lmap[cl->num]==1){
		pl->next=cl->next;	
	    }else{
		pl=cl;
	    }
	    cl=cl->next;
	}

	hl=head.next;
    }
    dp[0][0]=2147483647;
    dp[0][1]=2147483647;
    dp[1][0]=1;
    dp[1][1]=1;
    for(i=2;i<=10000000;i++){
	if(lmap[i]==0){
	    log[i][0]=i;
	    log[i][1]=1;
	}

	u=log[i][1];

	if(log[i][0]==log[u][0]){
	    dp[i][0]=dp[u][0];
	    dp[i][1]=dp[u][1]+dp[u][0];
	}else{
	    dp[i][0]=dp[u][1];
	    dp[i][1]=dp[u][1]*2;
	}
    }

    poolptr=0;
    build(0,10000000);

    while(scanf("%d %d",&a,&b)!=EOF){
	printf("%d\n",(query(&pool[0],min(a,b),max(a,b))->num));
    }

    return 0;
}
