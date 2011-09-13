#include<stdio.h>
#include<stdlib.h>

int n,m;
char map[27][2];
char smap[27];
long long int dp[27][50]; 

long long int ru(int a,int s){
    if(dp[a][s]!=-1){
	return dp[a][s];
    }
    if(s==0){
	if(smap[a]==1){
	    dp[a][s]=1;
	    return 1;
	}else{
	    dp[a][s]=0;
	    return 0;
	}
    }

    dp[a][s]=ru(map[a][0],s-1)+ru(map[a][1],s-1);

    return dp[a][s];
}

int main(){
    int i,j,k;
    int u,v;
    char a,b,c,p;
    char str[100];

    while(scanf("%d",&n)!=EOF){
	for(i=0;i<n;i++){
	    gets(str);
	    scanf("%c %c %c %c",&p,&a,&b,&c);
	    p=p-'A';
	    a=a-'A';
	    b=b-'A';
	    map[p][0]=a;
	    map[p][1]=b;
	    if(c=='x'){
		smap[p]=1;
	    }else{
		smap[p]=0;
	    }
	    for(j=0;j<50;j++){
		dp[i][j]=-1;
	    }
	}
	scanf("%d",&m);
	if(m==0){
	    printf("1\n");
	    continue;
	}
	printf("%lld\n",ru(0,m));
    }

    return 0;
}
