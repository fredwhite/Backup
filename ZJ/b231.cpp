#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;

struct node{
    int a;
    int b;
};
node l[1010];

bool cmp(node na,node nb){
    return (na.a+nb.a+nb.b)<(nb.a+na.a+na.b);
}

int main(){
    int n;
    int a,b;
    int i,j;
    int ma;
    int u;

    while(scanf("%d",&n)!=EOF){
	for(i=0;i<n;i++){
	    scanf("%d %d",&l[i].a,&l[i].b);
	}
	sort(l,l+n,cmp);
	ma=-1;
	u=0;
	for(i=0;i<n;i++){
	    u+=l[i].a;
	    ma=max(ma,u+l[i].b);
	}
	printf("%d\n",ma);
    }

    return 0;
}
