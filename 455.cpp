#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    int i,j,k,o;
    int u,v;
    char c;
    int l;
    int flag;

    char str[100];

    scanf("%d",&n);
    gets(str);
    for(k=0;k<n;k++){
	gets(str);
	gets(str);
	l=strlen(str);
	for(i=1;i<=l;i++){
	    if(l%i==0){
		flag=0;
		for(j=0;j<i;j++){
		    c=str[j];
		    for(o=i;o<l;o+=i){
			if(str[j+o]!=c){
			    flag=1;
			    break;
			}
		    }
		    if(flag==1){
			break;
		    }
		}
		if(flag==0){
		    if(k>0){
			printf("\n");
		    }
		    printf("%d\n",i);
		    break;
		}
	    }
	}
    }

    return 0;
}
