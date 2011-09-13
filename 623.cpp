#include<stdio.h>
#include<stdlib.h>

char c[3000];
char log[1005][3000];

int mul(int x){
	int i;
	int t,tmp;

	t=0;
	for(i=0;i<3000;i++){
		tmp=c[i]*x+t;	
		c[i]=tmp%10;
		t=tmp/10;
	}

	return 0;
}

int main(){
	int n;
	int i,j;
	int flag;
	
	for(i=0;i<3000;i++){
		c[i]=0;
	}
	c[0]=1;
	for(i=0;i<1000;i++){
		mul(i+1);
		flag=-1;
		for(j=2999;j>=0;j--){
			if(c[j]!=0 && flag==-1){
				flag=j;		
			}
			if(flag>-1){
				log[i][flag-j]=c[j]+'0';
			}	
		}
		log[i][flag+1]=0;
	}

	while(scanf("%d",&n)!=EOF){
		if(n==0){
			printf("0!\n1\n");
		}else{
			printf("%d!\n%s\n",n,log[n-1]);
		}	
	}

	return 0;
}
