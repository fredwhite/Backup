/*
PROG: rotsym
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>
#include<map>

using namespace std;

struct point{
    long long int x;
    long long int y;
};

point po[1010];
map<long long int,short> dic;

int main(){
    freopen("rotsym.in","r",stdin);
    freopen("rotsym.out","w",stdout);

    int n;
    int i,j;
    long long int x,y;
    long long int u,v;
    long long int tmp;
    long long int sum;

    point np,cp;
    map<long long int,short>::iterator it;

    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%lld %lld",&po[i].x,&po[i].y);
	po[i].x+=1000000000;
	po[i].y+=1000000000;
    }
    dic.clear();
    for(i=0;i<n;i++){
	for(j=i+1;j<n;j++){
	    u=po[i].x+po[j].x;
	    v=po[i].y+po[j].y;
	    tmp=u*2000000000+v;
	    it=dic.find(tmp);
	    if(it==dic.end()){
		dic.insert(pair<long long int,short>(tmp,1));
	    }else{
		it->second+=1;
	    }
	}
    }
    sum=0;
    for(it=dic.begin();it!=dic.end();++it){
	if(it->second>=2){
	    tmp=it->second;
	    tmp=(tmp*(tmp-1LL))/2;
	    sum+=tmp;
	}
    }
    printf("%lld\n",sum);

    return 0;
}
