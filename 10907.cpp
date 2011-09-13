#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector>

using namespace std;

struct point{
    int x;
    int y;
};
struct dpoint{
    double x;
    double y;
};
struct edge{
    point a;
    point b;
};
edge el[30];

vector<point> s;

int cross(point a,point b,point o){
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
dpoint touch(edge a,edge b){
    dpoint ret;
    point pa,pb,pc,tp;
    int ca,cb,cc;

    tp.x=0;
    tp.y=0;

    pa.x=a.b.x-a.a.x;
    pa.y=a.b.y-a.a.y;
    pb.x=b.b.x-b.a.x;
    pb.y=b.b.y-b.a.y;
    pc.x=b.a.x-a.a.x;
    pc.y=b.a.y-a.a.y;

    ca=cross(pa,pb,tp);
    cb=cross(pc,pb,tp);
    cc=cross(pc,pa,tp);

    if(ca<0){
	ca=-ca;
	cb=-cb;
	cc=-cc;
    }
    if(ca!=0 && cb>=0 && cb<=ca && cc>=0 && cc<=ca){
	ret.x=(double)a.a.x+((double)pa.x*((double)cb/(double)ca));
	ret.y=(double)a.a.y+((double)pa.y*((double)cb/(double)ca));
    }else{
	ret.x=-11000.0;
	ret.y=-11000.0;
    }

    return ret;
}

int main(){
    int n,l;
    int i,j,k;
    int x,y;

    int idx;
    int flag;
    double ta,area;
    point tp;
    edge ea,eb;
    int u,v;
    dpoint ret;

    int c;

    c=1;
    while(scanf("%d",&n)!=EOF){
	printf("Gallery #%d\n",c);
	c++;

	scanf("%d %d",&el[0].b.x,&el[0].b.y);
	for(i=1;i<n;i++){
	    el[i].a=el[i-1].b;
	    scanf("%d %d",&el[i].b.x,&el[i].b.y);
	}
	el[0].a=el[n-1].b;
	
	ta=0;
	tp.x=0;
	tp.y=0;
	for(i=0;i<n;i++){
	    if(cross(el[i].a,el[(i+1)%n].b,el[i].b)>0){
		idx=i;
		break;
	    }
	    ta+=cross(el[i].a,el[i].b,tp);
	}
	for(;i<n;i++){
	    ta+=cross(el[i].a,el[i].b,tp);
	}
	ta=fabs((double)ta)/2.0;

	scanf("%d",&l);
	for(j=0;j<l;j++){
	    scanf("%d %d",&x,&y);

	    ea.a.x=x;
	    ea.a.y=y;
	    ea.b.x=x+(el[idx].b.x-x)*10000;
	    ea.b.y=y+(el[idx].b.y-y)*10000;
	    eb.a.x=x;
	    eb.a.y=y;
	    eb.b.x=-ea.b.x;
	    eb.b.y=-ea.b.y;

	    flag=0;
	    area=0.0;
	    s.clear();
	    for(i=0;i<n;i++){
		u=(idx+i+1)%n;

		s.push_back(el[u].a);

		ret=touch(el[u],eb);
		if(ret.x>=-1000 && (ret.x!=(double)el[idx].b.x | ret.y!=(double)el[idx].b.y)){
		    flag+=1; 
		}

		ret=touch(el[u],ea);	
		if(ret.x>=-1000 && (ret.x!=(double)el[idx].b.x | ret.y!=(double)el[idx].b.y) &&
		    (ret.x!=(double)x | ret.y!=(double)y)){
		    flag+=10;

		    v=s.size();
		    for(k=1;k<v;k++){
			area+=(double)cross(s[k],s[k-1],tp);
		    }
		    area+=ret.x*(double)s[v-1].y-ret.y*(double)s[v-1].x;
		    area+=(double)s[0].x*ret.y-(double)s[0].y*ret.x;
		    area=fabs(area)/2.0;

		    break; 
		}
	    }
	    if(flag<10){
		printf("%.2lf\n",(double)ta);
	    }else if(flag==10){
		printf("%.2lf\n",(double)ta-area);
	    }else if(flag>10){
		printf("%.2lf\n",area);
	    }
	}
    }

    return 0;
}
