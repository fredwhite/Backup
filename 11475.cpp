#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stra[100010];
char strb[100010];

int fail[100010];

int fa(char *str){
    int l;
    int i,j;
    int u,v;

    l=strlen(str);
    j=-1;
    fail[0]=-1;
    for(i=1;i<l;i++){
	while(j>=0 && str[j+1]!=str[i]){
	    j=fail[j];
	}

	if(str[j+1]==str[i]){
	    j++;
	}
	fail[i]=j;
    }

    return 0;
}

int main(){
    int i,j;
    int l;

    while(gets(stra)!=NULL){
	l=strlen(stra);
	for(i=0;i<l;i++){
	    strb[l-i-1]=stra[i];
	}
	strb[l]=0;

	fa(strb);
	
	j=-1;
	for(i=0;i<l;i++){
	    while(j>=0 && strb[j+1]!=stra[i]){
		j=fail[j];
	    }

	    if(strb[j+1]==stra[i]){
		j++;
	    }
	}

	printf("%s%s\n",stra,&strb[j+1]);
    }

    return 0;
}
