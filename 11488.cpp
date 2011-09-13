#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;

struct node{
    char str[205];
};

node dic[50010];

bool cmp(node a,node b){
    if(strcmp(a.str,b.str)<0){
	return true;
    }else{
	return false;
    }
}

int main(){
    int t,n;
    int i,j;
    int l;
    int u;
    int ma;
    int c[205];
    char str[205];

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("%s",dic[i].str);
	}
	sort(dic,dic+n,cmp);

	for(i=0;i<205;i++){
	    c[i]=0;
	    str[i]='a';
	}
	ma=-1;
	for(i=0;i<n;i++){
	    l=strlen(dic[i].str);
	    for(j=0;j<l;j++){
		if(dic[i].str[j]!=str[j]){
		    break;
		}
	    }
	    u=j;

	    for(j=0;j<u;j++){
		c[j]+=1;
	    }
	    for(j=u;j<205;j++){
		ma=max(ma,(j+1)*c[j]);
		c[j]=0;
	    }
	    for(j=u;j<l;j++){
		c[j]=1;
	    }

	    strcpy(str,dic[i].str);
	}
	for(i=0;i<205;i++){
	    ma=max(ma,(i+1)*c[i]);
	}
	printf("%d\n",ma);
    }

    return 0;
}
