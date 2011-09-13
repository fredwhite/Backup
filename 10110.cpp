#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	long long int u,v;

	while(true){
		scanf("%lld",&u);
		if(u==0){
			break;
		}
		v=sqrt(u);
		if(v*v==u){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}

	return 0;
}
