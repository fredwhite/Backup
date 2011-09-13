#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

struct point{
    double x;
    double y;
};
vector<point> gra;
vector<point> can;
point sn;

double cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}

bool cmp(point a,point b){
    double c;

    if(a.y==0.0 && b.y==0.0 && a.x*b.x<0.0){
	return a.x>b.x;
    }
    if(a.y==0.0 && b.y!=0.0){
	if(a.x>=0.0){
	    return true;
	}
	return b.y<0.0;
    }
    if(b.y==0.0 && a.y!=0.0){
	if(b.x>=0.0){
	    return false;
	}
	return a.y>0.0;
    }
    if(a.y*b.y<0.0){
	return a.y>b.y;
    }

    c=cross(a,b);
    if(c==0.0){
	return (a.x*a.x+a.y*a.y)<(b.x*b.x+b.y*b.y);
    }

    return c>0.0;
}

int main(){
    int n;
    int i;

    point np;
    point a,b;
    int u,v;
    double c;

    while(scanf("%d",&n)!=EOF){
	if(n==0){
	    break;
	}

	gra.clear();
	can.clear();

	for(i=0;i<n;i++){
	    scanf("%lf %lf",&np.x,&np.y);
	    gra.push_back(np);
	}

	sn=gra[0];
	for(i=1;i<n;i++){
	    if(gra[i].x>sn.x){
		sn=gra[i];
	    }
	}
	for(i=0;i<n;i++){
	    gra[i].x-=sn.x;
	    gra[i].y-=sn.y;
	}
	sort(gra.begin(),gra.end(),cmp);

	can.push_back(gra[0]);
	can.push_back(gra[1]);
	v=1;
	for(i=2;i<n;i++){
	    while(v>=1){
		a.x=can[v-1].x-can[v].x;
		a.y=can[v-1].y-can[v].y;
		b.x=gra[i].x-can[v].x;
		b.y=gra[i].y-can[v].y;

		c=cross(a,b);
		if(c<=0.0){
		    break;
		}
		can.pop_back();
		v--;
	    }	
	    can.push_back(gra[i]);
	    v++;
	}
	while(v>=1){
	    a.x=can[v-1].x-can[v].x;
	    a.y=can[v-1].y-can[v].y;
	    b.x=gra[0].x-can[v].x;
	    b.y=gra[0].y-can[v].y;

	    c=cross(a,b);
	    if(c<=0.0){
		break;
	    }
	    can.pop_back();
	    v--;
	}

    }

    return 0;
}
