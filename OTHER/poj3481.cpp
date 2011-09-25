#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    node *pt;
    node *lt;
    node *rt;

    int idx;
    int p;
    int pri;
};

node pool[1000010];
int pp;
node *head;

int insert(int idx,int p){
    int u,v;
    node *ct,*pt;

    if(head==NULL){
	head=&pool[pp];
	pp++;

	head->pt=NULL;
	head->lt=NULL;
	head->rt=NULL;
	head->idx=idx;
	head->p=p;
	head->pri=rand()*rand();

	return 0;
    }

    ct=head;
    while(true){
	if(p<=ct->p){
	    if(ct->lt==NULL){
		ct->lt=&pool[pp];
		pp++;
		ct->lt->pt=ct;	
		ct=ct->lt;

		ct->lt=NULL;
		ct->rt=NULL;
		ct->idx=idx;
		ct->p=p;
		ct->pri=rand()*rand();

		break;
	    }else{
		ct=ct->lt;
	    }
	}else{
	    if(ct->rt==NULL){
		ct->rt=&pool[pp];
		pp++;
		ct->rt->pt=ct;	
		ct=ct->rt;

		ct->lt=NULL;
		ct->rt=NULL;
		ct->idx=idx;
		ct->p=p;
		ct->pri=rand()*rand();
		
		break;
	    }
	    ct=ct->rt;
	}
    }

    while(ct->pt!=NULL){
	u=ct->pri;
	v=ct->pt->pri;
	if(u>v){
	    pt=ct->pt;

	    if(ct->p<=pt->p){
		pt->lt=ct->rt;
		if(ct->rt!=NULL){
		    ct->rt->pt=pt;
		}
		ct->rt=pt;
	    }else{
		pt->rt=ct->lt;
		if(ct->lt!=NULL){
		    ct->lt->pt=pt;
		}
		ct->lt=pt;
	    }
	    if(pt->pt!=NULL){
		if(pt->p<=pt->pt->p){
		    pt->pt->lt=ct;	    
		}else{
		    pt->pt->rt=ct;
		}
	    }
	    ct->pt=pt->pt;
	    pt->pt=ct;
	}else{
	    break;
	}
    }
    if(ct->pt==NULL){
	head=ct;
    }
    return 0;
}
int qmin(){
    int ans;
    node *ct,*tt;

    if(head==NULL){
	return 0;
    }

    ct=head;
    while(ct->lt!=NULL){
	ct=ct->lt;
    }
    ans=ct->idx;

    while(ct->lt!=NULL || ct->rt!=NULL){
	if(ct->lt!=NULL & ct->rt!=NULL){
	    if(ct->lt->pri>ct->rt->pri){
		tt=ct->lt;
		tt->pt=ct->pt;
		ct->pt=tt;
		ct->lt=tt->rt;
		tt->rt=ct;
	    }else{
		tt=ct->rt;
		tt->pt=ct->pt;
		ct->pt=tt;
		ct->rt=tt->lt;
		tt->lt=ct;	
	    }
	}else if(ct->lt!=NULL){
	    tt=ct->lt;
	    tt->pt=ct->pt;
	    ct->pt=tt;
	    ct->lt=tt->rt;
	    tt->rt=ct;
	}else{
	    tt=ct->rt;
	    tt->pt=ct->pt;
	    ct->pt=tt;
	    ct->rt=tt->lt;
	    tt->lt=ct;
	}
	if(tt->pt!=NULL){
	    if(tt->p<=tt->pt->p){
		tt->pt->lt=tt;	    
	    }else{
		tt->pt->rt=tt;
	    }
	}
	if(head==ct){
	    head=ct->pt;
	}
    }
    if(head==ct){
	head=ct->pt;
    }else{
	if(ct->p<=ct->pt->p){
	    ct->pt->lt=NULL;
	}else{
	    ct->pt->rt=NULL;
	}
    }

    return ans;
}
int qmax(){
    int ans;
    node *ct,*tt;

    if(head==NULL){
	return 0;
    }

    ct=head;
    while(ct->rt!=NULL){
	ct=ct->rt;
    }
    ans=ct->idx;

    while(ct->lt!=NULL || ct->rt!=NULL){
	if(ct->lt!=NULL && ct->rt!=NULL){
	    if(ct->lt->pri>ct->rt->pri){
		tt=ct->lt;
		tt->pt=ct->pt;
		ct->pt=tt;
		ct->lt=tt->rt;
		tt->rt=ct;
	    }else{
		tt=ct->rt;
		tt->pt=ct->pt;
		ct->pt=tt;
		ct->rt=tt->lt;
		tt->lt=ct;	
	    }
	}else if(ct->lt!=NULL){
	    tt=ct->lt;
	    tt->pt=ct->pt;
	    ct->pt=tt;
	    ct->lt=tt->rt;
	    tt->rt=ct;
	}else{
	    tt=ct->rt;
	    tt->pt=ct->pt;
	    ct->pt=tt;
	    ct->rt=tt->lt;
	    tt->lt=ct;
	}
	if(tt->pt!=NULL){
	    if(tt->p<=tt->pt->p){
		tt->pt->lt=tt;	    
	    }else{
		tt->pt->rt=tt;
	    }
	}
	if(head==ct){
	    head=ct->pt;
	}
    }
    if(head==ct){
	head=ct->pt;
    }else{
	if(ct->p<=ct->pt->p){
	    ct->pt->lt=NULL;
	}else{
	    ct->pt->rt=NULL;
	}
    }

    return ans;
}

int main(){
    int n;
    int type;
    int idx,p;

    int i;
    int u,v;

    head=NULL;
    while(scanf("%d",&type)!=EOF){
	if(type==0){
	    break;
	}else if(type==1){
	    scanf("%d %d",&idx,&p);
	    insert(idx,p);
	}else if(type==2){
	    printf("%d\n",qmax());
	}else{
	    printf("%d\n",qmin());
	}
    }

    return 0;
}
