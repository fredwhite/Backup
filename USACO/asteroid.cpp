/*
PROG: asteroid
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

vector<int> gra[1010];
char mmap[1010];
char lmap[1010];
int ma[1010];

int ru(int a){
    int i;
    int u,v;

    lmap[a]=1;

    u=gra[a].size();
    for(i=0;i<u;i++){
	v=gra[a][i];
	if(lmap[v]==0){
	    if(mmap[v]==0){
		mmap[a]=1;
		mmap[v]=1;
		ma[v]=a;
		ma[a]=v;
		
		return 1;
	    }else{
		if(lmap[ma[v]]==0 && ru(ma[v])==1){
		    mmap[a]=1;
		    mmap[v]=1;
		    ma[v]=a;
		    ma[a]=v;

		    return 1;
		}
	    }
	}
    }

    return 0;
}

int main(){
    freopen("asteroid.in","r",stdin);
    freopen("asteroid.out","w",stdout);

    int n,k;
    int i,j;
    int col,row;
    int sum;

    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
	gra[i].clear();
	gra[i+500].clear();

	mmap[i]=0;
	mmap[i+500]=0;
    }
    for(i=0;i<k;i++){
	scanf("%d %d",&row,&col);
	row--;
	col--;

	gra[col].push_back(row+500);
	gra[row+500].push_back(col);
    }

    for(i=0;i<n;i++){
	if(mmap[i]==0){
	    for(j=0;j<n;j++){
		lmap[j]=0;
		lmap[j+500]=0;
	    }
	    ru(i);
	}
    }
    sum=0;
    for(i=0;i<n;i++){
	if(mmap[i]==1){
	    sum++;
	}
    }
    printf("%d\n",sum);

    return 0;
}
