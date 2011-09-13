#include<stdio.h>
#include<stdlib.h>

char map[102][102];
char lmap[102];

int main(){
    int n,m;
    int i,j,k;
    int u,v;
    int flag;
    int sum;
    char c;

    while(true){
	scanf("%d",&n);
	if(n==0){
	    break;
	}
	scanf("%d",&m);
	if(m==0){
	    break;
	}
	for(i=0;i<n;i++){
	    scanf("%c",&c);
	    for(j=0;j<m;j++){
		scanf("%c",&map[i][j]);
		map[i][j]-='0';
	    }
	}
	sum=0;
	for(k=0;k<n;k++){
	    for(i=0;i<m;i++){
		lmap[i]=1;
	    }
	    for(i=k;i<n;i++){
		lmap[0]=lmap[0] & map[i][0];
		flag=0;
		if(lmap[0]==1){
		    flag++;
		}
		for(j=1;j<m;j++){
		    lmap[j]=lmap[j] & map[i][j];
		    if(lmap[j]==1){
			flag++;
		    }else{
			sum+=(1+flag)*flag/2;
			flag=0;
		    }
		}
		sum+=(1+flag)*flag/2;
	    }
	}
	printf("%d\n",sum);
    }

    return 0;
}
