#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<map>

using namespace std;

map<int,int> l;

int main(){
    int a;
    map<int,int>::iterator it;
    int c;
    int mi;

    c=0;
    mi=2147483647;
    l.clear();
    while(scanf("%d",&a)!=EOF){
	if(a==0){
	    break;
	}
	it=l.find(a);
	if(it==l.end()){
	    l.insert(pair<int,int>(a,1));	    
	    if(c<1){
		c=1;
		mi=a;
	    }else if(c==1){
		if(a<mi){
		    mi=a;
		}
	    }
	}else{
	    it->second++;
	    if(c<it->second){
		c=it->second;
		mi=it->first;
	    }else if(c==it->second){
		if(it->first<mi){
		    mi=it->first;
		}
	    }
	}
	printf("%d %d\n",c,mi);
    }

    return 0;
}
