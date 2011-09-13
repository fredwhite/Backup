#include<stdio.h>
#include<stdlib.h>

double l[200];
long long int dp[8][10];
long long int count[8][10];

int main(){
    int n;
    int i,j,k;

    int u,v;
    long long int sum;
    
    while(scanf("%d",&n)!=EOF){
	if(n==0){
	    break;
	}
	for(i=0;i<n;i++){
	    scanf("%lf",&l[i]);
	}

	for(i=0;i<8;i++){
	    for(j=0;j<10;j++){
	        dp[i][j]=0LL;
	        count[i][j]=0LL;
	    }
	}

	for(i=0;i<n;i++){
	    u=((int)(l[i]*10.0+0.5)%10);
	    count[0][u]+=1LL;
	}

	for(k=1;k<8;k++){
	    for(i=0;i<n;i++){
		u=((int)(l[i]*10.0+0.5)%10);
		for(j=0;j<10;j++){
		    if((j+u)>=10){
			dp[k][(j+u)-10]+=dp[k-1][j]+count[k-1][j];
			count[k][(j+u)-10]+=count[k-1][j];
		    }else{
			dp[k][j+u]+=dp[k-1][j];
			count[k][j+u]+=count[k-1][j];
		    }
		}
	    }
	}

	sum=0LL;
	for(i=0;i<10;i++){
	    sum+=dp[7][i];
	}
	printf("%lld\n",sum);

    }
    
    return 0;
}
