#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int map[110][110];

int main(){
    int n;
    int i,j,k;
    long long int mi;
    long long int tmp;

    while(scanf("%d",&n)!=EOF){
	if(n==0){
	    break;
	}
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		scanf("%d",&map[i][j]);
		if(map[i][j]==0){
		    map[i][j]=-1;
		}
	    }	    
	}

	for(k=0;k<n;k++){
	    for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		    if(map[i][k]!=-1 && map[k][j]!=-1){
			if(map[i][j]!=-1){
			    map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}else{
			    map[i][j]=map[i][k]+map[k][j];
			}
		    }
		}
	    }
	}
	mi=10000010;
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		if(map[i][j]!=-1 && map[j][i]!=-1){
		    tmp=(long long int)map[i][j]+(long long int)map[j][i];
		    mi=min(mi,tmp);
		}
	    }
	}
	if(mi!=10000010){
	    printf("%I64d\n",mi);
	}else{
	    printf("-1\n");
	}
    }

    return 0;
}
