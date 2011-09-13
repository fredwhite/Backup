#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

int map[102][102];
char d[102];
int amap[102],bmap[102];

int main(){
	int c,s,e,t;
	int i,j,k,l;
	int u,v;
	int ma;

	while(scanf("%d %d %d %d",&c,&s,&e,&t)!=EOF){
		if(c==0 && s==0 && e==0 && t==0){
			break;
		}
		s--;
		for(i=0;i<c;i++){
			for(j=0;j<c;j++){
				scanf("%d",&map[i][j]);		
			}
			d[i]=0;
		}
		for(i=0;i<e;i++){
			scanf("%d",&u);
			u--;
			d[u]=1;
		}
		for(i=0;i<c;i++){
			amap[i]=map[s][i];
		}
		for(l=1;l<t;l++){
			for(i=0;i<c;i++){
				u=amap[i];
				for(k=0;k<c;k++){
					u=max(u,amap[k]+map[k][i]);
				}
				bmap[i]=u;
			}
			for(i=0;i<c;i++){
				amap[i]=bmap[i];
			}
		}
		ma=0;
		for(i=0;i<c;i++){
			if(d[i]==1){
				ma=max(bmap[i],ma);
			}	
		}
		printf("%d\n",ma);
	}

	return 0;
}
