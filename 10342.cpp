#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int gra[105][105][2];

bool cmp(int a,int b){
    return a<b;
}

int main(){
    int n,r,q;
    int i,j,k,o;

    int a,b;
    int u,v;
    int d[6];

    int count;

    count=1;
    while(scanf("%d %d",&n,&r)!=EOF){
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		gra[i][j][0]=147483647;
		gra[i][j][1]=147483647;
	    }
	    gra[i][i][0]=0;
	}
	for(i=0;i<r;i++){
	    scanf("%d %d %d",&a,&b,&u);
	    gra[a][b][0]=u;
	    gra[b][a][0]=u;
	}

	for(k=0;k<n;k++){
	    for(i=0;i<n;i++){
		for(j=i;j<n;j++){
		    d[0]=gra[i][j][0];
		    d[1]=gra[i][j][1];
		    d[2]=gra[i][k][0]+gra[k][j][0];
		    d[3]=gra[i][k][1]+gra[k][j][1];
		    d[4]=gra[i][k][0]+gra[k][j][1];
		    d[5]=gra[i][k][1]+gra[k][j][0];
		    sort(d,d+6,cmp);
	
		    u=d[0];
		    v=147483647;
		    for(o=1;o<6;o++){
			if(d[o]!=u){
			    v=d[o];
			    break;
			}
		    }

		    gra[i][j][0]=u;
		    gra[i][j][1]=v;
		    gra[j][i][0]=gra[i][j][0];
		    gra[j][i][1]=gra[i][j][1];
		}
	    }
	}
	for(k=0;k<n;k++){
	    for(i=0;i<n;i++){
		for(j=i;j<n;j++){
		    d[0]=gra[i][j][0];
		    d[1]=gra[i][j][1];
		    d[2]=gra[i][k][0]+gra[k][j][0];
		    d[3]=gra[i][k][1]+gra[k][j][1];
		    d[4]=gra[i][k][0]+gra[k][j][1];
		    d[5]=gra[i][k][1]+gra[k][j][0];
		    sort(d,d+6,cmp);
	
		    u=d[0];
		    v=147483647;
		    for(o=1;o<6;o++){
			if(d[o]!=u){
			    v=d[o];
			    break;
			}
		    }

		    gra[i][j][0]=u;
		    gra[i][j][1]=v;
		    gra[j][i][0]=gra[i][j][0];
		    gra[j][i][1]=gra[i][j][1];
		}
	    }
	}
	
	scanf("%d",&q);
	printf("Set #%d\n",count);
	count++;
	for(k=0;k<q;k++){
	    scanf("%d %d",&a,&b);
	    if(gra[a][b][1]>10200){
		printf("?\n");
	    }else{
		printf("%d\n",gra[a][b][1]);
	    }
	}
    }

    return 0;
}

