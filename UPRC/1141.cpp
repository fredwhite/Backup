#include<stdio.h>
#include<stdlib.h>

int main(){
    int t;
    long long int a,b;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%I64d %I64d",&a,&b);
	if(b%2==1){
	    printf("0.00 100.00\n");
	}else{
	    printf("100.00 0.00\n");
	}
    }

    return 0;
}
