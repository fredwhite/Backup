#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node{
    int idx;
    int num;
};
struct pack{
    int cma;
    long long int kill;
};
struct tn{
    tn *lt;
    tn *rt;
    int l;
    int r;
    int mid;

    pack p;
};

int l[100010];
int lc[100010];

node ls[100010];
node lstmp[100010];

tn ro;
tn pool[200020];
int pp;

pack pl[100010];

int merge(int l,int r){
    int i,j,k;
    int tmp;
    int u,v;

    if(l==r){
	return 0;
    }
    tmp=(l+r)/2;
    merge(l,tmp);
    merge(tmp+1,r);

    i=l;
    j=tmp+1;
    u=0;
    v=tmp-l+1;
    k=0;
    while(i<=tmp && j<=r){
	if(ls[i].num>ls[j].num){
	    lstmp[k]=ls[j];  
	    k++;
	    u++;
	    lc[ls[j].idx]+=v;
	    j++;
	}else{
	    lstmp[k]=ls[i];
	    k++;
	    v--;
	    lc[ls[i].idx]+=u;
	    i++;
	}
    }
    while(i<=tmp){
	lstmp[k]=ls[i];
	k++;
	lc[ls[i].idx]+=u;
	i++;
    }
    while(j<=r){
	lstmp[k]=ls[j];  
	k++;
	lc[ls[j].idx]+=v;
	j++;
    }

    for(i=l;i<=r;i++){
	ls[i]=lstmp[i-l];
    }

    return 0;
}

int ins(tn *root,int x,pack p){
    tn *nn,*cn;
    
    if(root->l==root->r){
	if(p.cma>root->p.cma){
	    root->p=p;
	}else if(p.cma==root->p.cma && p.kill>root->p.kill){
	    root->p=p;
	}
	return 0;
    }
    
    if(x<=root->mid){
	if(root->lt==NULL){
	    nn=&pool[pp];
	    pp++;
	    
	    nn->lt=NULL;
	    nn->rt=NULL;
	    nn->l=root->l;
	    nn->r=root->mid;
	    nn->mid=(nn->l+nn->r)/2;
	    nn->p.cma=0;
	    nn->p.kill=0LL;

	    root->lt=nn;
	}
	cn=root->lt;
    }else{
	if(root->rt==NULL){
	    nn=&pool[pp];
	    pp++;
	    
	    nn->lt=NULL;
	    nn->rt=NULL;
	    nn->l=root->mid+1;
	    nn->r=root->r;
	    nn->mid=(nn->l+nn->r)/2;
	    nn->p.cma=0;
	    nn->p.kill=0LL;

	    root->rt=nn;
	}
	cn=root->rt;
    }

    ins(cn,x,p);

    if(p.cma>root->p.cma){
	root->p=p;
    }else if(p.cma==root->p.cma && p.kill>root->p.kill){
	root->p=p;
    }

    return 0;
}
pack query(tn *root,int l,int r){
    pack p,rp;

    if(root->l==l && root->r==r){
	return root->p;
    }

    p.cma=0;
    p.kill=0LL;

    if(l<=root->mid && root->lt!=NULL){
	rp=query(root->lt,l,min(root->mid,r));

	if(rp.cma>p.cma){
	    p=rp;
	}else if(rp.cma==p.cma && rp.kill>p.kill){
	    p=rp;
	}
    }
    if(r>root->mid && root->rt!=NULL){
	rp=query(root->rt,max(root->mid+1,l),r);

	if(rp.cma>p.cma){
	    p=rp;
	}else if(rp.cma==p.cma && rp.kill>p.kill){
	    p=rp;
	}
    }

    return p;
}

int main(){
    int i;
    int n;
    long long int sum;

    int u,v;
    pack cp,np;
    int cma;
    long long int ma;

    scanf("%d",&n);

    if(n==0){
	printf("0\n");
	return 0;
    }

    for(i=0;i<n;i++){
	scanf("%d",&l[i]);

	ls[i].idx=i;
	ls[i].num=l[i];
	lc[i]=0;
    }

    merge(0,n-1);
    sum=0LL;
    u=-1;
    v=-1;
    for(i=0;i<n;i++){
	sum+=(long long int)lc[i];

	if(u!=ls[i].num){
	    u=ls[i].num;
	    v++;
	    l[ls[i].idx]=v;
	}else{
	    l[ls[i].idx]=v;
	}
    }
    sum/=2LL;

    pp=0;
    ro.lt=NULL;
    ro.rt=NULL;
    ro.l=0;
    ro.r=v;
    ro.p.cma=0;
    ro.p.kill=0;

    pl[0].cma=1;
    pl[0].kill=(long long int)lc[0];

    ins(&ro,l[0],pl[0]); 
    
    for(i=1;i<n;i++){
	cp=query(&ro,0,l[i]);

	pl[i].cma=cp.cma+1;
	pl[i].kill=cp.kill+(long long int)lc[i];

	ins(&ro,l[i],pl[i]);
    }

    cma=0;
    ma=0LL;
    for(i=0;i<n;i++){
	if(pl[i].cma>cma){
	    cma=pl[i].cma;
	    ma=pl[i].kill;
	}else if(pl[i].cma==cma){
	    if(pl[i].kill>ma){
		ma=pl[i].kill;
	    }
	}
    }

    printf("%I64d\n",sum-ma);

    return 0;
}
