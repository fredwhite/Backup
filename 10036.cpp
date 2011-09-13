#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char om[200],nm[200];

int main(){
	int m,n,d;
	int i,j,k;
	int a,u,v,x;

	scanf("%d",&m);
	for(k=0;k<m;k++){
		scanf("%d %d",&n,&d);
		memset(om,0,d*sizeof(char));
		om[0]=1;
		for(i=0;i<n;i++){
			memset(nm,0,d*sizeof(char));
			scanf("%d",&a);
			u=a%d;
			x=(-a)%d;
			if(u<0){
				u=d+u;
			}
			if(x<0){
				x=d+x;
			}
			for(j=0;j<d;j++){
				if(om[j]==1){
					v=(u+j)%d;
					nm[v]=1;
					v=(x+j)%d;
					nm[v]=1;
				}
			}
			memcpy(om,nm,d*sizeof(char));
		}
		if(nm[0]==1){
			printf("Divisible\n");
		}else{
			printf("Not divisible\n");
		}
	}

	return 0;
}
