/*
PROG: line
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>

int n,k;
int l[50];
long long int map[23][23];
char lmap[30];
int log[30];

int main(){
    freopen("line.in","r",stdin);
    freopen("line.out","w",stdout);

    char str[100];
    int i,j,o;
    long long int a,b;
    long long int u,v;
    int s;

    scanf("%I64d %I64d",&n,&k);

    for(i=1;i<=n;i++){
	for(j=i;j<=n;j++){
	    u=j-i;
	    v=0;
	    for(o=i+1;o<=n;o++){
		u*=(n-i-v);
		v++;
	    }
	    map[i][j]=u;
	}
    }

    for(;k>0;k--){
	scanf("%s",str);
	for(i=0;i<=n;i++){
	    lmap[i]=0;
	}

	if(str[0]=='P'){
	    scanf("%I64d",&a);

	    for(i=0;i<n;i++){
		s=0;
		for(j=1;j<=n;j++){
		    log[j]=s;
		    if(lmap[j]==0){
			s++;
		    }
		}
		for(j=n;j>=1;j--){
		    if()
		}
	    }


	}else if(str[0]=='Q'){
	    for(i=0;i<n;i++){
		scanf("%d",&l[i]);
	    }
	}
    }

    return 0;
}
