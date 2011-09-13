#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

struct point{
    int x;
    int y;
    int z;
};

vector<point> l;
vector<int> o;

long long int cross(point a,point b){
    return (long long int)a.x*(long long int)b.y-(long long int)a.y*(long long int)b.x;
}
bool cmp(point a,point b){
    long long int c; 

    if(a.y==0 && b.y==0 && (long long int)a.x*(long long int)b.x<=0LL){
	return a.x>b.x;
    }else if(a.y==0 && a.x>=0 && b.y!=0){
	return true;
    }else if(b.y==0 && b.x>=0 && a.y!=0){
	return false;
    }else if((long long int)a.y*(long long int)b.y<0LL){
	return a.y>b.y;
    }else{
	c=cross(a,b);
	if(c!=0LL){
	    return c>0LL;
	}else{
	    return (long long int)a.x*(long long int)a.x+(long long int)a.y*(long long int)a.y<
		(long long int)b.x*(long long int)b.x+(long long int)b.y*(long long int)b.y;
	}
    }
}

bool cmpb(int a,int b){
    if(l[a].x==l[b].x){
	return l[a].y<l[b].y;
    }
    return l[a].x<l[b].x;
}

int main(){
    int n;
    int x,y,z;
    int i,j,k;
    int prev;
    int flag,u,count;

    point np,cp;

    count=1;
    while(scanf("%d",&n)!=EOF){
	if(n==0){
	    break;
	}
	l.clear();
	o.clear();
	for(i=0;i<n;i++){
	    scanf("%d %d %d",&np.x,&np.y,&np.z);
	    l.push_back(np);
	}

	sort(l.begin(),l.end(),cmp);
	prev=l[0].z;
	for(i=1;i<n;i++){
	    if(cross(l[i-1],l[i])==0LL && (long long int)l[i-1].x*(long long int)l[i].x>=0LL && (long long int)l[i-1].y*(long long int)l[i].y>=0LL){
		if(l[i].z<=prev){
		    o.push_back(i);
		}else{
		    prev=l[i].z;
		}
	    }else{
		prev=l[i].z;
	    }
	}

	printf("Data set %d:\n",count);
	count++;

	sort(o.begin(),o.end(),cmpb);
	flag=0;
	u=o.size();
	for(i=0;i<u;i++){
	    if(flag==1){
		printf(";\n");
	    }else{
		printf("Some lights are not visible:\n");
	    }
	    flag=1;
	    printf("x = %d, y = %d",l[o[i]].x,l[o[i]].y);
	}
	if(flag==1){
	    printf(".\n");
	}else{
	    printf("All the lights are visible.\n");
	}
    }

    return 0;
}
