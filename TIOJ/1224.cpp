#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct node{
    int l;
    int r;
    int cnt;
    int clen;
};
struct rect{
    int l;
    int r;
    int d;
    int u;
};
struct line{
    int 
}

rect l[100010];

bool cmp(node a,node b){
    if(a.l==b.l){
	return a.u<b.u;
    }
    return a.l<b.l;
}

int main(){
    int n;
    int i,j;

    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%d %d %d %d",&l[i].l,&l[i].r,&l[i].d,&l[i].u);
    }
    sort(l,l+n)

    return 0;
}
