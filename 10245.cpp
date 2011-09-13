#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

struct point{
    double x;
    double y;
};
vector<point> pl;
point ml[10050];

bool cmp(const point &a,const point &b){
    if(a.x==b.x){
	return a.y<b.y;
    }

    return a.x<b.x;
}
bool cmpa(const point &a,const point &b){
    return a.y<b.y;
}

double dist(const point &a,const point &b){
    double u,v;

    u=a.x-b.x;
    v=a.y-b.y;

    return sqrt((double)(u*u+v*v));
}

double ru(int l,int r){
    int i,j;
    int u,v;
    double a,b,mi;

    mi=214748364700.0;
    if(l>=r){
	return mi;
    }

    v=(l+r)/2;
    a=ru(l,v);
    b=ru(v+1,r);
    mi=min(mi,a);
    mi=min(mi,b);

    u=0;
    for(i=v;i>=l;i--){
	if((pl[v].x-pl[i].x)>=mi){
	    break;
	}
	ml[u]=pl[i];
	u++;
    }
    for(i=v+1;i<=r;i++){
	if((pl[i].x-pl[v].x)>=mi){
	    break;
	}
	ml[u]=pl[i];
	u++;
    }

    a=mi;
    sort(ml,ml+u,cmpa);
    for(i=0;i<u;i++){
	for(j=1;j<=3;j++){
	    if(i+j>=u){
		break;
	    }
	    mi=min(mi,dist(ml[i],ml[i+j]));
	}
    }

    return mi;
}

int main(){
    int n;
    int i,j;
    double x,y;
    int flag;
    double mi;
    int a,b;

    point np;

    while(scanf("%d",&n)!=EOF){
	if(n==0){
	    break;
	}

	pl.clear();
	for(i=0;i<n;i++){
	    scanf("%lf%lf",&np.x,&np.y);
	    pl.push_back(np);
	}
	sort(pl.begin(),pl.end(),cmp);

	mi=ru(0,n-1);
	if(mi>=10000.0 || n==1){
	    printf("INFINITY\n");
	}else{
	    printf("%.4lf\n",mi);
	}
    }

    return 0;
}
