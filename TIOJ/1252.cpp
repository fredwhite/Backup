#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

struct node{
    node *lt,*rt;
    long long int l,r;

    long long int sum;
    long long int tmp;
};

node root;
node pool[12582864];
int pp;

int insert(node* root,long long int x){
    node *nn;
    long long int tmp;

    if(root->l==root->r){
	root->sum+=1LL;
	return 0;
    }

    tmp=root->tmp;
    if(x<=tmp){
	if(root->lt==NULL){
	    nn=&pool[pp];
	    pp++;

	    nn->lt=NULL;
	    nn->rt=NULL;
	    nn->l=root->l;
	    nn->r=tmp;
	    nn->sum=0LL;
	    nn->tmp=(nn->l+nn->r)/2LL;

	    root->lt=nn;
	}

	insert(root->lt,x);
    }else{
	if(root->rt==NULL){
	    nn=&pool[pp];
	    pp++;

	    nn->lt=NULL;
	    nn->rt=NULL;
	    nn->l=tmp+1LL;
	    nn->r=root->r;
	    nn->sum=0LL;
	    nn->tmp=(nn->l+nn->r)/2LL;

	    root->rt=nn;
	}

	insert(root->rt,x);
    }

    root->sum+=1LL;
    return 0;
}
long long int query(node* root,long long int l,long long int r){
    long long int tmp;
    long long int sum;

    if(root->l==l && root->r==r){
	
	return root->sum;
    }

    tmp=root->tmp;

    sum=0;
    if(l<=tmp && root->lt!=NULL){
	sum+=query(root->lt,l,min(tmp,r));
    }
    if(r>tmp && root->rt!=NULL){
	sum+=query(root->rt,max(tmp+1LL,l),r);
    }

    return sum;
}

int main(){
    int n;
    long long int a;
    char str[200];
    int i;

    long long int sum;
    long long int offset;
    long long int ma,u;
    
    root.lt=NULL;
    root.rt=NULL;

    while(scanf("%d",&n)!=EOF){
	if(n==0){
	    break;
	}

	pp=0;
	root.lt=NULL;
	root.rt=NULL;
	root.l=0;
	root.r=20000000010LL;
	root.sum=0;

	ma=0;
	u=0;
	sum=0;
	offset=0;
	for(i=0;i<n;i++){
	    scanf("%s %I64d",str,&a);
	    if(str[0]=='w'){
		a=-a;
	    }

	    if((u+a)>0){
		u+=a;
	    }else{
		u=0;
	    }
	    if(u>ma){
		ma=u;
	    }

	    if(a>0){
		sum++;
	    }

	    sum+=query(&root,(10000000000LL-a-offset+1LL),20000000010LL);
	    offset+=a;
	    insert(&root,(10000000000LL+a-offset));
	}

	printf("%I64d %I64d\n",sum,ma);
    }

    return 0;
}
