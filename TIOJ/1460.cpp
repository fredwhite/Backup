#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

struct node{
    int row;
    int col;
    int high;
};

int map[505][505];
int lmap[505][505];
vector<node> l;
queue<node> q;

bool cmp(node a,node b){
    return a.high<b.high;
}

int main(){
    int t;
    int n,m;
    int i,j,k;
    int u,v;
    int row,col;
    int count;
    int ma;

    int pc[4]={0,1,0,-1};
    int pr[4]={-1,0,1,0};

    node nn,cn;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d %d",&n,&m);
	l.clear();
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		scanf("%d",&map[i][j]);
		nn.row=i;
		nn.col=j;
		nn.high=map[i][j];
		l.push_back(nn);

		lmap[i][j]=2147483647;
	    }
	}
	sort(l.begin(),l.end(),cmp);

	u=l.size();
	count=0;
	for(i=0;i<u;i++){
	    if(lmap[l[i].row][l[i].col]==2147483647){
		count++;
		if(count>m){
		    break;
		}
		lmap[l[i].row][l[i].col]=0;

		while(!q.empty()){
		    q.pop();
		}

		q.push(l[i]);
		while(!q.empty()){
		    cn=q.front();
		    q.pop();
		    v=lmap[cn.row][cn.col];
		    
		    for(k=0;k<4;k++){
			row=cn.row+pr[k];
			col=cn.col+pc[k];
			if(row>=0 && row<n && col>=0 && col<n){
			    if(cn.high<map[row][col]){
				if((v+1)<lmap[row][col]){
				    lmap[row][col]=v+1;

				    nn.row=row;
				    nn.col=col;
				    nn.high=map[row][col];

				    q.push(nn);
				}
			    }
			}	    
		    }
		}
	    }
	}
	ma=-1;
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		ma=max(ma,lmap[i][j]);
	    }
	}
	if(ma!=2147483647){
	    printf("%d\n",ma);
	}else{
	    printf("Impossible\n");
	}
    }

    return 0;
}
