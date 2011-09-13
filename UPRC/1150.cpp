#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>

using namespace std;

struct node{
    int a;
    int b;
    int c;
};

node lw[1505];
int cw[10005];

bool cmpa(node a,node b){
    return a.a<b.a;
}
bool cmpb(node a,node b){
    return a.b<b.b;
}

int lowbit(int x){
    return (-x)&x;
}
int mo(int x,int v){
    int u;

    u=x+1;
    while(u<10005){
	cw[u]+=v;
	u+=lowbit(u);
    }

    return 0;
}
int query(int x){
    int u;
    int sum;

    sum=0;
    u=x+1;
    while(u>0){
	sum+=cw[u];
	u-=lowbit(u);
    }

    return sum;
}


int main(){
    int t;
    int n,m;
    int i,j,k;
    int ma;

    int a,b,c;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
	    scanf("%d %d %d",&lw[i].a,&lw[i].b,&lw[i].c);
	}
	sort(lw,lw+n,cmpa);
	ma=0;
	for(i=0;i<n;i++){
	    a=lw[i].a;
	    sort(lw,lw+i+1,cmpb);
	    for(j=0;j<10005;j++){
		cw[j]=0;
	    }
	    for(j=0;j<=i;j++){
		b=lw[j].b;

		c=m-a-b;
		if(c>=0){
		    mo(lw[j].c,1);
		    c=m-a-b;

		    ma=max(ma,query(c));
		}else{
		    break;
		}
	    }
	}

	printf("%d\n",ma);
    }

    return 0;
}
