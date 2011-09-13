#include<stdio.h>
#include<stdlib.h>

int dp[26][26][500];

int main(){
    int l,s;
    int i,j,k,o;
    int u,v;
    int c;

    c=1;
    while(true){
	scanf("%d %d",&l,&s);
	if(l==0 && s==0){
	    break;
	}
	printf("Case %d: ",c);
	c++;
	if(l>26){
	    printf("0\n");
	    continue;
	}
	if((52-l+1)*l/2<s){
	    printf("0\n");
	    continue;
	}

	for(i=0;i<26;i++){
	    for(j=0;j<=s;j++){
	        dp[0][i][j]=0;
	    }
	}
	for(i=0;i<26;i++){
	    dp[0][i][i+1]=1;
	}
	for(k=1;k<l;k++){
	    for(i=0;i<26;i++){
		for(j=0;j<=s;j++){
		    dp[k][i][j]=0;
		}
	    }

	    for(i=0;i<26;i++){
		for(j=i+1;j<26;j++){
		    for(o=j+1;o<=s;o++){
			dp[k][j][o]+=dp[k-1][i][o-j-1];
		    }
		}
	    }
	}
	sum=0;
	for(i=0;i<26;i++){
	    sum+=dp[l-1][i][s];     
	}
	printf("%d\n",sum);
    }

    return 0;
}
