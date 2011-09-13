#include<stdio.h>
#include<stdlib.h>

char dp[1005][2000];
int l[1005];
char c[2000];

int add(int a,int b){
	int i;
	int t,tmp;
	int la,lb;

	t=0;
	la=l[a];
	lb=l[b];
	if(la<lb){
		for(i=0;i<la;i++){
			tmp=dp[a][i]+dp[b][i]+t;
			dp[b][i]=tmp%10;
			t=tmp/10;	
		}
		for(i=la;i<lb;i++){
			tmp=dp[b][i]+t;
			dp[b][i]=tmp%10;
			t=tmp/10;
		}
		if(t>0){
			dp[b][lb]=t;
			l[b]++;
		}
	}else{
		for(i=0;i<lb;i++){
			tmp=dp[a][i]+dp[b][i]+t;
			dp[b][i]=tmp%10;
			t=tmp/10;	
		}
		for(i=lb;i<la;i++){
			tmp=dp[a][i]+t;
			dp[b][i]=tmp%10;
			t=tmp/10;
		}
		l[b]=la;
		if(t>0){
			dp[b][lb]=t;
			l[b]++;
		}
	}

	return 0;	
}

int main(){
	int n;
	int i;

	while(scanf("%d",&n)!=EOF){
		dp[0][0]=1;
		l[0]=1;
		dp[1][0]=2;
		l[1]=1;
		dp[2][0]=5;
		l[2]=1;
		for(i=3;i<=n;i++){
			l[i]=0;
			add(i-1,i);
			add(i-1,i);
			add(i-2,i);
			add(i-3,i);		
		}	
		for(i=l[n]-1;i>=0;i--){
			printf("%d",dp[n][i]);
		}
		printf("\n");
	}

	return 0;
}
