#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

struct point{
    int row;
    int col;
    int cost;
};

int m,n,k,t;

int sol[110][2];
int goal[110][3];
char gmap[105][105];
int map[105][105];
int tmap[110][110];
char lmap[110][110];
int cmap[110][110];

int ans;
vector<int> gra[500];
int ml[500];
int mp[500];
int log[500];

vector<point> q;

bool cmp(point a,point b){
    return a.cost>b.cost;
}

int ru(int a){
    int i;
    int u,v;

    u=gra[a].size();
    for(i=0;i<u;i++){
	v=gra[a][i];
	if(log[v]==0){
	    log[v]=1;
	    if(ml[v]==0){
		ml[v]=1;
		mp[v]=a;
		ml[a]=1;
		mp[a]=v;

		return 1;
	    }else{
		if(ru(mp[v])==1){
		    ml[v]=1;
		    mp[v]=a;
		    ml[a]=1;
		    mp[a]=v;

		    return 1;
		}
	    }
	}
    }
    
    return 0;
}

int bs(int l,int r){
    int tmp;
    int i,j,o;
    int u,v;

    if(l>r){
	return 0;
    }

    tmp=(l+r)/2;

    for(i=0;i<500;i++){
	gra[i].clear();
	ml[i]=0;
	mp[i]=-1;
    }

    for(i=0;i<k;i++){
	u=110;
	for(j=0;j<t;j++){
	    if(tmap[i][j]<=tmp){
		for(o=0;o<goal[j][2];o++){
		    gra[i].push_back(u);
		    gra[u].push_back(i);
		    u++;
		}
	    }else{
		u+=goal[j][2];
	    }
	}
    }
    for(i=0;i<k;i++){
	u=110;
	for(j=0;j<t;j++){
	    if(tmap[i+50][j]<=tmp){
		for(o=0;o<goal[j][2];o++){
		    gra[i+50].push_back(u);
		    gra[u].push_back(i+50);
		    u++;
		}
	    }else{
		u+=goal[j][2];
	    }
	}
    }

    for(i=0;i<k;i++){
	if(ml[i]==0){
	    for(j=0;j<500;j++){
		log[j]=0;
	    }
	    log[i]=1;
	    ru(i);
	}
    }
    for(i=0;i<k;i++){
	if(ml[i+50]==0){
	    for(j=0;j<500;j++){
		log[j]=0;
	    }
	    log[i+50]=1;
	    ru(i+50);
	}
    }

    u=0;
    for(i=0;i<110;i++){
	if(ml[i]==1){
	    u++;
	}
    }

    if((u+tmp+1)>=(k*2+1)){
	ans=tmp;
	bs(l,tmp-1);
    }else{
	bs(tmp+1,r);
    }

    return 0;
}

int main(){
    int count;
    
    int i,j,o;
    int u,v,r;

    int pr[4]={-1,0,1,0},pc[4]={0,1,0,-1};
    point cp,np;
    int row,col;

    scanf("%d",&count);
    for(;count>0;count--){
	scanf("%d %d %d %d",&m,&n,&k,&t);

	for(i=0;i<k;i++){
	    scanf("%d %d",&sol[i][0],&sol[i][1]);
	    sol[i][0]--;
	    sol[i][1]--;
	}
	for(i=0;i<k;i++){
	    scanf("%d %d",&sol[i+50][0],&sol[i+50][1]);
	    sol[i+50][0]--;
	    sol[i+50][1]--;
	}
	scanf("%d %d",&sol[100][0],&sol[100][1]);

	for(i=0;i<t;i++){
	    scanf("%d %d %d",&u,&v,&r);   
	    u--;
	    v--;
	    gmap[v][u]=r;
	    goal[i][0]=u;
	    goal[i][1]=v;
	    goal[i][2]=r;
	}
	for(i=0;i<m;i++){
	    for(j=0;j<n;j++){
		scanf("%d",&map[i][j]);
	    }
	}

	for(o=0;o<k;o++){
	    q.clear();
	    for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		    lmap[i][j]=0;
		    cmap[i][j]=2147483647;
		}
	    }

	    np.row=sol[o][0];
	    np.col=sol[o][1];
	    np.cost=0;
	    cmap[np.row][np.col]=0;
	    q.push_back(np);
	    while(!q.empty()){
		pop_heap(q.begin(),q.end(),cmp);
		cp=q.back();
		q.pop_back();

		if(lmap[cp.row][cp.col]==0){
		    lmap[cp.row][cp.col]=1;

		    for(j=0;j<4;j++){
			row=cp.row+pr[j];
			col=cp.col+pc[j];
			if(row>=0 && row<m && col>=0 && col<n){
			    if(lmap[row][col]!=1){
				np.row=row;
				np.col=col;
				np.cost=cp.cost;

				if((cp.cost&1)==0){
				    if(map[cp.row][cp.col]>map[row][col]){
					np.cost+=1;
				    }
				}else{
				    if(map[cp.row][cp.col]<map[row][col]){
					np.cost+=1;
				    }
				}
				if(np.cost<cmap[row][col]){
				    cmap[row][col]=np.cost;
				    q.push_back(np);
				    push_heap(q.begin(),q.end(),cmp);
				}
			    } 
			}
		    }
		}
	    }

	    for(i=0;i<t;i++){
		tmap[o][i]=cmap[goal[i][0]][goal[i][1]];
	    }
	}

	for(o=0;o<k;o++){
	    q.clear();
	    for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		    lmap[i][j]=0;
		    cmap[i][j]=2147483647;
		}
	    }

	    np.row=sol[o+50][0];
	    np.col=sol[o+50][1];
	    np.cost=0;
	    cmap[np.row][np.col]=0;
	    q.push_back(np);
	    while(!q.empty()){
		pop_heap(q.begin(),q.end(),cmp);
		cp=q.back();
		q.pop_back();

		if(lmap[cp.row][cp.col]==0){
		    lmap[cp.row][cp.col]=1;

		    for(j=0;j<4;j++){
			row=cp.row+pr[j];
			col=cp.col+pc[j];
			if(row>=0 && row<m && col>=0 && col<n){
			    if(lmap[row][col]!=1){
				np.row=row;
				np.col=col;
				np.cost=cp.cost;

				if((cp.cost&1)==0){
				    if(map[cp.row][cp.col]<map[row][col]){
					np.cost+=1;
				    }
				}else{
				    if(map[cp.row][cp.col]>map[row][col]){
					np.cost+=1;
				    }
				}
				if(np.cost<cmap[row][col]){
				    cmap[row][col]=np.cost;
				    q.push_back(np);
				    push_heap(q.begin(),q.end(),cmp);
				}
			    } 
			}
		    }
		}
	    }

	    for(i=0;i<t;i++){
		tmap[o+50][i]=cmap[goal[i][0]][goal[i][1]];
	    }
	}

	bs(0,2*k+5);
	printf("%d\n",ans);

    }

    return 0;
}
