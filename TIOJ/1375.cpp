#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

vector<int> map[25];
char lmap[25][25];
char log[25][25];
int n,m;
int ans;

int chk(int a,int count){
    int i,j;
    int u,v;
    int c;

    c=count;
    for(i=a;i<n;i++){
	u=map[i].size();
	for(j=0;j<u;j++){
	    v=map[i][j];	
	    if(lmap[i][v]==0){
		c++;
	    }
	    lmap[i][v]++;
	    lmap[v][i]++;
	}
    }
    for(i=a;i<n;i++){
	u=map[i].size();
	for(j=0;j<u;j++){
	    v=map[i][j];
	    lmap[i][v]--;
	    lmap[v][i]--;
	}
    }
    if(c<n){
	return 0;
    }

    return 1;
}
int ru(int a,int deep,int count){
    int i;
    int u,v;
    int c;
    
    if(count==m){
	ans=deep;
	return 1;
    }
    if(a==n){
	return 0;
    }

    if(ru(a+1,deep,count)==1){
	return 1;
    }

    c=count;
    u=map[a].size();
    for(i=0;i<u;i++){
	v=map[a][i];	
	if(lmap[a][v]==0){
	    c++;
	}
	lmap[a][v]++;
	lmap[v][a]++;
    }
    if(ru(a+1,deep+1,c)==1){
	return 1;
    }
    for(i=0;i<u;i++){
	v=map[a][i];
	lmap[a][v]--;
	lmap[v][a]--;
    }

    return 0;
}
    
int main(){
    int i,j;
    int a,b;
    int tmp;

    while(scanf("%d %d",&n,&tmp)!=EOF){
	for(i=0;i<n;i++){
	    map[i].clear();
	    for(j=0;j<n;j++){
		lmap[i][j]=0;
		log[i][j]=0;
	    }
	}
	m=0;
	for(i=0;i<tmp;i++){
	    scanf("%d %d",&a,&b);
	    if(log[a][b]==0){
		m++;
		map[a].push_back(b);
		map[b].push_back(a);
		log[a][b]=1;
		log[b][a]=1;
	    }
	}

	ans=-1;
	ru(0,0,0);
	while(ans==-1);
	printf("%d\n",ans);

    }
    return 0;
}
