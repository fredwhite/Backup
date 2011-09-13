#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>

using namespace std;

long long int map[85][85][85];
long long int tmap[85];
long long int l[85];
int cmap[85];

bool cmp(long long int a,long long int b){
    return a<b;
}

int main(){
    int i,j,k,o;
    int w;
    int u,v;

    int c,r,q;
    int a,b,cost;
    int count;

    long long int tmp,mia,mib;
    
    count=1;
    while(scanf("%d %d %d",&c,&r,&q)!=EOF){
	if(c==0 && r==0 && q==0){
	    break;
	}

	for(i=0;i<c;i++){
	    scanf("%lld",&l[i]); 
	    tmap[i]=l[i];
	}
	sort(tmap,tmap+c,cmp);
	v=tmap[0];
	w=1;
	for(i=1;i<c;i++){
	    if(tmap[i]!=v){
		tmap[w]=tmap[i];
		w++;
		v=tmap[i];
	    }
	}
	for(i=0;i<c;i++){
	    for(k=0;k<w;k++){
		if(tmap[k]==l[i]){
		    cmap[i]=k;
		    break;
		}
	    }
	}

	for(i=0;i<c;i++){
	    for(j=0;j<c;j++){
		for(k=0;k<w;k++){
		    map[i][j][k]=5223372036854775807LL;
		}
	    }
	    map[i][i][cmap[i]]=0LL;
	}

	for(i=0;i<r;i++){
	    scanf("%d %d %d",&a,&b,&cost);
	    a--;
	    b--;

	    u=max(cmap[a],cmap[b]);
	    map[a][b][u]=min(map[a][b][u],(long long int)cost);
	    map[b][a][u]=map[a][b][u];
	}
	for(o=0;o<c;o++){
	    for(i=0;i<c;i++){
		for(j=i+1;j<c;j++){
		    mia=5223372036854775807LL;
		    mib=5223372036854775807LL;
		    for(k=0;k<w;k++){
			mia=min(mia,map[i][o][k]);
			mib=min(mib,map[o][j][k]);
			if(map[i][o][k]!=5223372036854775807LL || map[o][j][k]!=5223372036854775807LL){
			    if(mia!=5223372036854775807LL && mib!=5223372036854775807LL){
				map[i][j][k]=min(map[i][j][k],mia+mib);
				map[j][i][k]=map[i][j][k];
			    }
			}
		    }
		}
	    }
	}
	for(i=0;i<c;i++){
	    for(j=0;j<c;j++){
		tmp=5223372036854775807LL;
		for(k=0;k<w;k++){
		    tmp=min(tmp,map[i][j][k]+tmap[k]);
		}
		map[i][j][0]=tmp;
		map[j][i][0]=map[i][j][0];
	    }
	}

	if(count>1){
	    printf("\n");
	}
	printf("Case #%d\n",count);
	count++;
	for(i=0;i<q;i++){
	    scanf("%d %d",&a,&b);
	    a--;
	    b--;
	    if(map[a][b][0]==5223372036854775807L){
		printf("-1\n");
	    }else{
		printf("%lld\n",map[a][b][0]);
	    }
	}
    }

    return 0;
}
