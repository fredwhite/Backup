#include<stdio.h>
#include<stdlib.h>

long long int map[25][25][25];
long long int p[25][25];
long long int l[25];
long long int dp[25];

int main(){
	int i,j,k;
	int ai,aj;
	int bi,bj;
	int t,a,b,c;
	long long int tmp;
	long long int ma;
	int flag;

	scanf("%d",&t);
	flag=0;
	while(t>0){
		t--;
		scanf("%d %d %d",&a,&b,&c);
		ma=-9223372036854775803LL;
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				for(k=0;k<c;k++){
					scanf("%lld",&map[i][j][k]);
					if(map[i][j][k]>ma){
						ma=map[i][j][k];
					}
				}
			}
		}
		for(ai=0;ai<a;ai++){
			for(i=0;i<b;i++){
				for(j=0;j<c;j++){
					p[i][j]=0;
				}
			}
			for(aj=ai;aj<a;aj++){
				for(i=0;i<b;i++){
					for(j=0;j<c;j++){
						p[i][j]+=map[aj][i][j];
					}
				}		
				for(bi=0;bi<b;bi++){
					for(i=0;i<c;i++){
						l[i]=0;
					}
					for(bj=bi;bj<b;bj++){
						for(i=0;i<c;i++){
							l[i]+=p[bj][i];
							if(l[i]>ma){
								ma=l[i];
							}
						}
						dp[0]=l[0];
						if(dp[0]<0){
							dp[0]=0;
						}
						for(i=1;i<c;i++){
							tmp=dp[i-1]+l[i];
							if(tmp>=0){
								dp[i]=tmp;
								if(dp[i]>ma){
									ma=dp[i];
								}
							}else{
								dp[i]=0;
							}
						}
					}
				}
			}
		}
		if(flag!=0){
			printf("\n");
		}
		flag=1;
		printf("%lld\n",ma);
	}

	return 0;
}
