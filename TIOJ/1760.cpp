#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct node{
    int idx;
    int os;
    int dark;
};

node l[300010];
int ol[300010];
int out[300010];

bool cmp(node a,node b){
    if(a.dark==b.dark){
	return a.os>b.os;
    }
    return a.dark<b.dark;
}
bool cmpb(int a,int b){
    return l[a].os>l[b].os;
}

int main(){
    int n;
    int i;

    int flag;
    int u,v;

    scanf("%d",&n);
    for(i=0;i<n;i++){
	l[i].idx=i;
	scanf("%d %d",&l[i].os,&l[i].dark);
	out[i]=-1;
    }
    sort(l,l+n,cmp);
    for(i=0;i<n;i++){
	ol[i]=i;
    }
    sort(ol,ol+n,cmpb);

    u=0;
    for(i=0;i<n;i++){
	while(u<n){
	    if(ol[u]==i){
		u++;
		break;
	    }else{
		if(l[ol[u]].dark<=l[i].dark){
		    u++;
		}else{
		    out[l[i].idx]=l[ol[u]].dark; 
		    break;
		}
	    }
	}
    }

    printf("%d",out[0]);
    for(i=1;i<n;i++){
	printf(" %d",out[i]);
    }
    printf("\n");

    return 0;
}
