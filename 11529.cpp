#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;

struct point{
    int x;
    int y;
};

vector<point> opl,pl;
point op;
char lmap[2000];
int cmap[2000];

int cross(point o,point a,point b){
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

bool cmp(point a,point b){
    int ax,ay;
    int bx,by;
    
    ax=a.x-op.x;
    ay=a.y-op.y;
    bx=b.x-op.x;
    by=b.y-op.y;

    if(ay==0){
	if(ax>0){
	    return true;
	}
	return by<0;
    }
    if(by==0){
	if(bx>0){
	    return false;
	}
	return ay>0;
    }
    if(ay*by<0){
	return ay>by;
    }

    return cross(op,a,b)>0;
}

int main(){
    int n;
    int i,j,k;

    point nn;
    int s,e;
    int ls,rs,rc,sum;
    int u,v;
    int l;
    int flag;
    int count;

    count=1;
    while(true){
	scanf("%d",&n);
	if(n==0){
	    break;
	}

	opl.clear();
	for(i=0;i<n;i++){
	    scanf("%d %d",&nn.x,&nn.y);
	    opl.push_back(nn);
	}

	sum=0;
	for(k=0;k<n;k++){
	    op=opl[k];
	    pl.clear();
	    for(i=0;i<n;i++){
		if(i!=k){
		    pl.push_back(opl[i]);
		}
	    }
	    sort(pl.begin(),pl.end(),cmp);
	    l=n-1;

	    for(i=0;i<l;i++){
		lmap[i]=0;
	    }

	    flag=0;
	    for(i=0;i<l;i++){
		if(cross(op,pl[0],pl[i])<0){
		    flag=1;
		    s=i;
		    break;
		}
	    }
	    if(flag==0){
		continue;
	    }

	    lmap[0]=1;
	    ls=0;
	    rs=0;
	    rc=0;

	    for(i=0;i<l;i++){
		u=(i+1)%l;

		lmap[u]=1;
		cmap[u]=0;
		flag=0;
		v=s;
		while(u!=v){
		    if(cross(op,pl[u],pl[v])<0){
			flag=1;
			e=v;
			break;
		    }

		    if(lmap[v]==1){
			ls-=rs;
			rs-=cmap[(v+1)%l];
			rc-=1;
		    }else{
			cmap[u]++;	
		    }

		    v=(v+1)%l;
		}

		ls=ls+cmap[u]*(rc+1);
		rs+=cmap[u];
		rc++;
		sum+=ls;

		s=e;
		if(flag==0){
		    break;
		}
	    }

	}
	printf("City %d: %.2lf\n",count,(double)sum/(double)(n*(n-1)*(n-2)/6));
	count++;
    }

    return 0;
}
