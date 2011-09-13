/*
PROG: badrand
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>

char d[10005];

int main(){
	freopen("badrand.in","r",stdin);
	freopen("badrand.out","w",stdout);

	int n,m,s;
	int tmp;
	int i;
	int c;

	while(scanf("%d",&n)!=EOF){
		for(i=0;i<10005;i++){
			d[i]=0;
		}
		c=0;
		while(d[n]==0){
			d[n]=1;
			c++;
			tmp=n/10;
			m=tmp%100;
			n=m*m;
		}
		printf("%d\n",c);	
	}


	return 0;
}
