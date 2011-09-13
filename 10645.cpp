#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

double dpa[55][105][2];
double dpb[55][105][2];
int dish[55][2];
int path[22][55][105][2][2];
int out[22];

int main(){
	int i,j,k,o;
	int t,n,m;
	int u,v,tmp,c;
	double ma;

	while(true){
		scanf("%d %d %d",&t,&n,&m);
		if(t==0 && n==0 && m==0){
			break;
		}
		for(i=0;i<n;i++){
			scanf("%d %d",&dish[i][0],&dish[i][1]);
		}
		for(i=0;i<n;i++){
			for(j=0;j<=m;j++){
				dpa[i][j][0]=-1;
				dpa[i][j][1]=-1;
			}	
			dpa[i][dish[i][0]][0]=dish[i][1];
		}	
		for(k=1;k<t;k++){
			for(i=0;i<n;i++){
				for(j=0;j<=m;j++){
					dpb[i][j][0]=-1;
					dpb[i][j][1]=-1;
				}
			}
			for(i=0;i<n;i++){
				for(j=0;j<=m;j++){
					for(o=0;o<n;o++){
						if(dpa[i][j][0]!=-1){
							if(o==i){
								u=dish[o][0]+j;
								if(u<=m){
									if((((double)dish[o][1])/2+dpa[i][j][0]) > dpb[o][u][1]){
										dpb[o][u][1]=(((double)dish[o][1])/2+dpa[i][j][0]);	
										path[k][o][u][1][0]=i;
										path[k][o][u][1][1]=0;
									}
								}
							}else{
								u=dish[o][0]+j;
								if(u<=m){
									if((double)dish[o][1]+dpa[i][j][0] > dpb[o][u][0]){
										dpb[o][u][0]=(double)dish[o][1]+dpa[i][j][0];	
										path[k][o][u][0][0]=i;
										path[k][o][u][0][1]=0;
									}
								}	
							}
						}	
						if(dpa[i][j][1]!=-1){
							if(o==i){
								u=dish[o][0]+j;
								if(u<=m){
									if(dpa[i][j][1] > dpb[o][u][1]){
										dpb[o][u][1]=dpa[i][j][1];
										path[k][o][u][1][0]=i;
										path[k][o][u][1][1]=1;
									}	
								}
							}else{
								u=dish[o][0]+j;
								if(u<=m){
									if((double)dish[o][1]+dpa[i][j][1] > dpb[o][u][0]){
										dpb[o][u][0]=(double)dish[o][1]+dpa[i][j][1];
										path[k][o][u][0][0]=i;
										path[k][o][u][0][1]=1;
									}
								}
							}
						}
					}
				}
			}
			for(i=0;i<n;i++){
				for(j=0;j<=m;j++){
					dpa[i][j][0]=dpb[i][j][0];
					dpa[i][j][1]=dpb[i][j][1];
				}
			}
		}

		ma=-1;
		u=0;
		v=0;
		c=0;
		for(i=0;i<n;i++){
			for(j=0;j<=m;j++){
				if(dpa[i][j][0]>ma){
					ma=dpa[i][j][0];
					u=i;
					v=0;
					c=j;
				}
				if(dpa[i][j][1]>ma){
					ma=dpa[i][j][1];
					u=i;
					v=1;
					c=j;
				}
			}
		}
		if(ma==-1){
			printf("0.0\n");
			continue;
		}
		printf("%.1f\n",ma);
		out[0]=u;
		for(k=t-1,i=1;k>=1;k--,i++){
			tmp=u;
			u=path[k][tmp][c][v][0];
			v=path[k][tmp][c][v][1];
			c=c-dish[tmp][0];
			out[i]=u;
		}
		printf("%d",out[t-1]+1);
		for(k=t-2;k>=0;k--){
			printf(" %d",out[k]+1);
		}
		printf("\n");
	}

	return 0;
}
