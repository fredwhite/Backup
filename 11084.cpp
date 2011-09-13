#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[30];
char lmap[20];
long long int d;
int l;

int ru(long long int n,int deep){
    int i;
    int s;
    int v;
    char tmp;
    int curr,prev;
    char log[10];

    if(deep==l){
	if(n%d==0){
	    return 1;
	}else{
	    return 0;
	}
    }
    s=0;	
    v=l-deep;
    curr=lmap[15];
    prev=15;
    memset(log,0,10);
    for(i=0;i<v;i++){
	if(log[str[curr]]==0){
	    log[str[curr]]=1;
	    lmap[prev]=lmap[curr];
	    s+=ru(n*10+str[curr],deep+1);
	    lmap[prev]=curr;
	}
	prev=curr;
	curr=lmap[curr];
    }

    return s;
}

int main(){
    int t;
    int i,j,k;
    int u,v;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%s %d",str,&d);
	l=strlen(str);
	for(i=0;i<l;i++){
	    lmap[i]=i+1;
	    str[i]-='0';
	}
	lmap[15]=0;
	printf("%d\n",ru(0,0));
    }

    return 0;
}
