#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<map>
#include<string>

using namespace std;

typedef struct node{
    node* next[26];
    int idx;
}node;

typedef struct block{
    char str[2010];
    int cost;
}block;

node pool[2000010];
int pp;
node *head;
int counta;
map<string,char> log;
queue<block> q;

int clean(node *cn){
    int i;
    for(i=0;i<26;i++){
	cn->next[i]=NULL;
    }
    cn->idx=-1;

    return 0;
}
int add(char *str){
    int i;
    int l;
    char c;
    node *cn,*nn; 
    queue<block> q;

    l=strlen(str);
    cn=head;
    for(i=0;i<l;i++){
	c=str[i]-'a';
	if(cn->next[c]==NULL){
	    cn->next[c]=&pool[pp];
	    pp++;
	    clean(cn->next[c]);
	}
	cn=cn->next[c];
    }
    if(cn->idx==-1){
	cn->idx=counta;
	counta++;
    }

    return 0;
}

block sb;
int find(node *cn,int deep){
    int i;

    for(i=0;i<26;i++){
	if(cn->next[i]!=NULL){
	    sb.str[deep]=i+'a';
	    if(cn->next[i]->idx!=-1){
		sb.str[deep+1]=0;
		if(log.insert(pair<string,char>(sb.str,0)).second==true){
		    q.push(sb);
		}
	    }
	    find(cn->next[i],deep+1);
	}
    }
    return 0;
}

int main(){
    int i,j;
    int la,lb;
    int l;
    int t,n;
    char stra[2010];
    char strb[2010];
    char str[2010];
    char tstr[2010];
    int flag;
    int state;
    int cost;
    char c;

    block cb,nb;
    node *cn;

    scanf("%d",&t);
    for(;t>0;t--){
	head=&pool[0];
	clean(head);
	pp=1;
	counta=0;
	log.clear();

	scanf("%s",stra);
	scanf("%s",strb);

	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("%s",str);
	    add(str);
	}

	la=strlen(stra);
	lb=strlen(strb);
	if(la==lb){
	    if(strcmp(stra,strb)==0){
		printf("0\n");
	    }else{
		printf("-1\n");
	    }
	    continue;
	}
	if(la>lb){
	    if(strncmp(stra,strb,lb)!=0){
		printf("-1\n");
		continue;
	    }

	    for(i=lb,j=0;i<la;i++,j++){
		str[j]=stra[i];
	    }
	    str[j]=0;
	}else{
	    if(strncmp(stra,strb,la)!=0){
		printf("-1\n");
		continue;
	    }

	    for(i=la,j=0;i<lb;i++,j++){
		str[j]=strb[i];
	    }
	    str[j]=0;
	}

	strcpy(nb.str,str);
	nb.cost=0;
	q.push(nb);
	flag=0;
	while(!q.empty()){
	    cb=q.front();
	    q.pop();

	    l=strlen(cb.str);
	    cn=head;
	    state=0;
	    for(i=0;i<l;i++){
		c=cb.str[i]-'a';
		if(cn->next[c]!=NULL){
		    cn=cn->next[c];
		    if(cn->idx!=-1){
			if(i==(l-1)){
			    cost=cb.cost+1;
			    flag=1;
			    break;
			}

			for(j=i+1;j<l;j++){
			    nb.str[j-i-1]=cb.str[j]; 
			}
			nb.str[j-i-1]=0;
			nb.cost=cb.cost+1;

			if(log.insert(pair<string,char>(nb.str,0)).second==true){
			    q.push(nb);
			}
		    }else if(i==(l-1)){
			sb.cost=cb.cost+1;
			find(cn,0);	
		    }
		}else{
		    break;
		}
	    }
	    if(flag==1){
		break;
	    }
	}
	if(flag==1){
	    printf("%d\n",cost);
	}else{
	    printf("-1\n");
	}
    }

    return 0;
}
