#include<stdio.h>
#include<stdlib.h>

char lmap[2010];

int main(){
    int t;
    int n;

    int i,j;
    int a,b;
    long long int sum;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d",&n);
	
	for(i=0;i<=n;i++){
	    lmap[i]=0;
	}
	lmap[0]=1;
	lmap[1]=1;
	
	sum=0;
	for(i=2;i<=n;i++){
	    a=0;
	    b=0;
	    for(j=1;j<i;j++){
		if(lmap[j]==1 && (i%j)==0){
		    a++;
		}
	    }
	    for(j=i+1;j<=n;j++){
		if((j%i)==0){
		    b++;
		}
	    }
	    if(a<b){
		lmap[i]=1;
	    }else{
		sum+=(long long int)a;
	    }
	}
	printf("%I64d\n",sum);
    }

    return 0;
}
