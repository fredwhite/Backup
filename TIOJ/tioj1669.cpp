#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

struct node{
    node *prev;
    node *next;

    int idx;
    int value;
    int l;
};

int map[600][600];
int q[600];
node pool[1200];
int ps,pe;

int main(){
    int h,w,k;
    int i,j,o;

    node nn,cn;

    int u,v;
    int a,b;
    int mi;
    int count;

    char str[600];

    scanf("%d %d %d",&h,&w,&k);
    for(i=0;i<h;i++){
	scanf("%s",str);
	for(j=0;j<w;j++){
	    if(str[j]=='+'){
		map[i][j]=1;
	    }else if(str[j]=='-'){
		map[i][j]=-1;
	    }else{
		map[i][j]=0;
	    }
	}
    }

    mi=2147483647;
    for(i=0;i<h;i++){
	for(j=0;j<w;j++){
	    q[j]=0;
	}

	for(j=i;j<h;j++){
	    for(o=0;o<w;o++){
		q[o]+=map[j][o];
	    }
	    
	    ps=1;
	    pe=0;
	    u=0;
	    v=0;
	    count=0;
	    for(o=0;o<w;o++){
		a=q[o];
		b=1;
		while(count>0){
		    if(a>0){
			break;
		    }
		    a+=pool[pe].value;
		    b+=pool[pe].l;
		    pe--;
		    count--;
		}

		if(a>0){
		    pe++;
		    pool[pe].idx=o;
		    pool[pe].value=a;
		    pool[pe].l=b;
		    count++;

		    u=u+q[o];
		    v=v+1;
		}else{
		    u=0;
		    v=0;
		}

		while(u>=k){
		    mi=min(mi,v*(j-i+1)); 

		    if(count==0){
			break;
		    }

		    u-=pool[ps].value;
		    v-=pool[ps].l;
		    ps++;
		    count--;
		}
	    }
	}
    }

    if(mi==2147483647){
	printf("-1\n");
    }else{
	printf("%d\n",mi);
    }

    return 0;
}
