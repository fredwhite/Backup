/*
PROG: meetplace
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>

int link[1010];
char lmap[1010];

int main(){
    freopen("meetplace.in","r",stdin);
    freopen("meetplace.out","w",stdout);
    
    int n,m;
    int i,j,k;
    int u,v;
    int a,b;

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
	link[i]=-1;
    }
    for(i=1;i<n;i++){
	scanf("%d",&a);
	a--;
	link[i]=a;
    }
    for(k=0;k<m;k++){
	scanf("%d %d",&a,&b);
	a--;
	b--;
	for(i=0;i<n;i++){
	    lmap[i]=0;
	}
	u=a;
	while(u!=-1){
	    lmap[u]=1;
	    u=link[u];
	}

	u=b;
	while(u!=-1){
	    if(lmap[u]==1){
		break;
	    }
	    u=link[u];
	}
	printf("%d\n",u+1);
    }

    return 0;
}
