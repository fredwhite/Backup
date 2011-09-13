#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;

struct node{
    int ci;
    int ai;
    int pi;
};

node l[5010];
int dp[2][5010];

bool cmp(node a,node b){
    return a.ci<b.ci;
}

int main(){
    int n,c,p;
    int i,j;

    int ci,ai,pi;
    int ma;

    int *dpa,*dpb,*dptmp;

    while(scanf("%d %d %d",&n,&c,&p)!=EOF){
	for(i=1;i<=n;i++){
	    scanf("%d %d %d",&l[i].ci,&l[i].ai,&l[i].pi);
	}   
	sort(l+1,l+n+1,cmp);

	dpa=dp[0];
	dpb=dp[1];

	for(i=0;i<p;i++){
	    dpa[i]=-2147483647;
	}
	dpa[0]=c;

	for(i=1;i<=n;i++){
	    if(l[i].ci<l[i].ai){
		for(j=0;j<l[i].pi && j<p;j++){
		    dpb[j]=dpa[j];
		}
		for(j=l[i].pi;j<p;j++){
		    if(dpa[j-l[i].pi]>=l[i].ci){
			dpb[j]=max(dpa[j],dpa[j-l[i].pi]+l[i].ai-l[i].ci);
		    }else{
			dpb[j]=dpa[j];
		    }
		}
		dptmp=dpa;
		dpa=dpb;
		dpb=dptmp;
	    }
	}
	ma=-1;
	for(i=0;i<p;i++){
	    ma=max(ma,dpa[i]);
	}
	printf("%d\n",ma);
	break;
    }

    return 0;
}
