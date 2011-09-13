#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[250];
int d[250];
long long int dp[250];

int main(){
	int t;
	int i,j,k;
	int l;
	long long int u,v,ma;

	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%s",str);
		l=strlen(str);	
		for(i=0;i<l;i++){
			d[i]=str[i]-'0';	
		}
		dp[0]=d[0];
		for(i=1;i<l;i++){
			u=0;
			ma=0;
			for(j=0;j<=9 && (i-j)>=0;j++){
				v=d[i-j];
				for(k=0;k<j;k++){
					v*=10;
				}
				u+=v;
				if(u<=2147483647){
					if(u+dp[i-j-1]>ma){
						ma=u+dp[i-j-1];
					}
				}else{
					break;
				}
			}
			dp[i]=ma;
		}
		printf("%lld\n",dp[l-1]);
	}

	return 0;	
}
