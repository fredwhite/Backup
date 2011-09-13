#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>

using namespace std;

struct node{
    char c;
    int flag;
    node *link[52];

    node *fail;
    node *prev;
};

char t[100010];
char p[1010];
char log[1010];
int map[1010];

node pool[1000000];
int pp;

queue<node*> qu;

int tran(char c){
    if(c>='A' && c<='Z'){
	return c-'A';
    }	
    return c-'a'+26;
}

int add(char *str,int index){
    int i,j;
    int l;
    int u,v;

    node *cn,*nn;

    l=strlen(str);
    cn=&pool[0];
    for(i=0;i<l;i++){
	u=tran(str[i]);

	if(cn->link[u]==NULL){
	    nn=&pool[pp];
	    pp++;

	    nn->c=str[i];
	    nn->flag=-1;
	    for(j=0;j<52;j++){
		nn->link[j]=NULL;
	    }

	    cn->link[u]=nn;
	    nn->prev=cn;
	    nn->fail=NULL;
	}
	cn=cn->link[u];
    }

    if(cn->flag>=0){
	map[index]=cn->flag;
    }else{
	cn->flag=index;
    }

    return 0;
}
int build(){
    int i;
    int u;
    node *pn,*cn;

    while(!qu.empty()){
	qu.pop();
    }

    for(i=0;i<52;i++){
	if(pool[0].link[i]!=NULL){
	    qu.push(pool[0].link[i]);
	}
    }

    while(!qu.empty()){
	cn=qu.front();
	qu.pop();
	
	u=tran(cn->c);

	pn=cn->prev;
	while(true){
	    if(pn->flag==-2){
		cn->fail=pn;

		break;
	    }
	    if(pn->fail->link[u]!=NULL){
		cn->fail=pn->fail->link[u];

		break;
	    }
	    pn=pn->fail;
	}

	for(i=0;i<52;i++){
	    if(cn->link[i]!=NULL){
		qu.push(cn->link[i]);
	    }
	}
    }
    
    return 0;
}

int main(){
    int k;
    int q;
    int i,j;
    int l;
    int u;

    node *cn,*tn;

    scanf("%d",&k);
    for(;k>0;k--){
	pool[0].flag=-2;
	for(i=0;i<52;i++){
	    pool[0].link[i]=NULL;
	}
	pp=1;

	scanf("%s",t);
	scanf("%d",&q);
	for(i=0;i<q;i++){
	    scanf("%s",p);

	    map[i]=i;

	    add(p,i);
	    log[i]='n';
	}
	build();

	l=strlen(t);
	cn=&pool[0];
	for(i=0;i<l;i++){
	    u=tran(t[i]);

	    while(cn->flag!=-2 && cn->link[u]==NULL){
		cn=cn->fail;
	    }

	    if(cn->link[u]!=NULL){
		cn=cn->link[u];

		if(cn->flag>=0){
		    log[cn->flag]='y';
		}
		tn=cn->fail;
		while(tn->flag>=0){
		    log[tn->flag]='y';
		    tn=tn->fail;
		}
	    }
	}
	for(i=0;i<q;i++){
	    printf("%c\n",log[map[i]]);
	}
    }

    return 0;
}
