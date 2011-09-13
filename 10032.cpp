#include<stdio.h>
#include<stdlib.h>

int l[105];
long long int dp[105][47250];

int main(){
    int t,n;
    int i,j,k,o;
    int u,v;
    long long int a,b;
    int sum,s;

    scanf("%d",&t);
    for(k=0;k<t;k++){
	scanf("%d",&n);
	sum=0;
	for(i=0;i<n;i++){
	    scanf("%d",&l[i]);
	    sum+=l[i];
	}
	if(n%2==1){
	    l[n]=0;
	    n++;
	}    
	s=sum;
	sum=sum/2;
	for(i=0;i<n;i++){
	    for(j=0;j<=sum;j++){
		dp[i][j]=0;
	    }
	}
	dp[0][0]=1;
	dp[0][l[0]]=2;
	v=n/2;
	for(i=1;i<n;i++){
	    u=l[i];
	    for(j=0;j<u;j++){
		dp[i][j]=dp[i-1][j];
	    }
	    for(j=u;j<=sum;j++){
		dp[i][j]=dp[i-1][j-u]*2 | dp[i-1][j];
	    }
	}
	if(k!=0){
	    printf("\n");
	}
	a=1;
	for(i=0;i<v;i++){
	    a*=2;
	}
	for(i=sum;i>=0;i--){
	    if((dp[n-1][i]&a)!=0){
		if(i<=(s-i)){
		    printf("%d %d\n",i,s-i);
		}else{
		    printf("%d %d\n",s-i,i);
		}
		break;
	    }
	}
    }


    return 0;
}
