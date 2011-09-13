#include<stdio.h>
#include<stdlib.h>

unsigned long long int mara[2][2],marb[2][2];
unsigned long long int marl[64][2][2];

int main(){
    int t;
    int i,j,o,k;

    unsigned long long int m,na,nb;

    mara[0][0]=0LL;
    mara[0][1]=1LL;
    mara[1][0]=1LL;
    mara[1][1]=1LL;

    for(k=0;k<64;k++){
	for(i=0;i<2;i++){
	    for(j=0;j<2;j++){
		marl[k][i][j]=mara[i][j];
	    }
	}

	for(i=0;i<2;i++){
	    for(j=0;j<2;j++){
		marb[i][j]=0LL;
		for(o=0;o<2;o++){
		    marb[i][j]+=mara[i][o]*mara[o][j];
		    marb[i][j]%=1000000007LL;
		}
	    }
	}

	for(i=0;i<2;i++){
	    for(j=0;j<2;j++){
		mara[i][j]=marb[i][j];
	    }
	}
    }

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%I64d %I64d %I64d",&na,&nb,&m);

	mara[0][0]=na%1000000007LL;
	mara[0][1]=nb%1000000007LL;

	m-=2LL;	
	for(k=0;k<64;k++){
	    if((m&1LL)==1LL){
		for(i=0;i<2;i++){
		    marb[0][i]=0LL;
		    for(o=0;o<2;o++){
		        marb[0][i]+=mara[0][o]*marl[k][o][i];
		        marb[0][i]%=1000000007LL;
		    }
		}

		mara[0][0]=marb[0][0];
		mara[0][1]=marb[0][1];
	    }
	    m=m>>1;
	}

	printf("%I64d\n",mara[0][1]);
    }	

    return 0;
}
