/*
PROG: bookclub
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>

int map[50005][55];
char d[50005];

int main(){
	int n,nq,p;

	int i,j,k;
	int u,v;
	int a,b;

	freopen("bookclub.in","r",stdin);
	freopen("bookclub.out","w",stdout);

	while(scanf("%d %d %d",&n,&nq,&p)!=EOF){
		for(i=0;i<n;i++){
			for(j=0;j<nq;j++){
				scanf("%d",&map[i][j]);
			}
			d[i]=1;
		}
		for(k=0;k<p;k++){
			scanf("%d %d",&a,&b);
			a--;
			for(i=0;i<n;i++){
				if(map[i][a]!=b){
					d[i]=0;
				}
			}
		}
		u=0;
		for(i=0;i<n;i++){
			if(d[i]==1){
				u++;
			}
		}
		printf("%d\n",u);
	}

	return 0;
}
