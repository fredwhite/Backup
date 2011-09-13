/*
PROG: commas
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	freopen("commas.in","r",stdin);
	freopen("commas.out","w",stdout);

	char str[100],o[200];
	int i,j,s,u;

	while(scanf("%s",str)!=EOF){
		j=0;
		u=1;
		s=strlen(str);
		for(i=s-1;i>=0;i--){
			o[j]=str[i];
			if(u%3==0){
				o[j+1]=',';
				j++;
			}
			u++;

			j++;
		}
		if(o[j-1]!=','){
			printf("%c",o[j-1]);
		}
		for(i=j-2;i>=0;i--){
			printf("%c",o[i]);
		}	
		printf("\n");
	}

	return 0;
}
