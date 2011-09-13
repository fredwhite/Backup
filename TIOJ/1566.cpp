#include<stdio.h>
#include<stdlib.h>
#include<deque>

using namespace std;
    
deque<unsigned int> ma;
deque<unsigned int> mi;
unsigned int l[10000010];

int insert(unsigned int a){
    
    while(!ma.empty()){
	if(ma.front()>=a){
	    break;
	}
	ma.pop_front();
    }
    ma.push_front(a);
    while(!mi.empty()){
	if(mi.front()<=a){
	    break;
	}
	mi.pop_front();
    }
    mi.push_front(a);

    return 0;
}
int remove(unsigned int a){

    if(!ma.empty()){
	if(ma.back()==a){
	    ma.pop_back();
	}
    }
    if(!mi.empty()){
	if(mi.back()==a){
	    mi.pop_back();
	}
    }

    return 0;
}

int main(){
    int i,j;
    int u;
    
    int n,m;
    unsigned int k;
    int count;

    scanf("%d %d %u",&n,&m,&k);
    for(i=0;i<n;i++){
	scanf("%u",&l[i]);
    }
    
    count=0;
    insert(l[0]);
    for(i=1;i<m;i++){
	insert(l[i]);
	if((ma.back()-mi.back())==k){
	    count++;
	}
    }
    for(i=m,j=1;i<n;i++,j++){
	remove(l[i-m]);
	insert(l[i]);
	
	if((ma.back()-mi.back())==k){
	    count++;
	}
    }
    u=n-1;
    for(i=n-m+1;i<u;i++){
	remove(l[i-1]);

	if((ma.back()-mi.back())==k){
	    count++;
	}
    }

    ma.clear();
    mi.clear();

    printf("%d\n",count);

    insert(l[0]);
    for(i=1;i<m;i++){
	insert(l[i]);
	if((ma.back()-mi.back())==k){
	    printf("1 %d\n",i+1);
	}
    }
    for(i=m,j=1;i<n;i++,j++){
	remove(l[i-m]);
	insert(l[i]);
	if((ma.back()-mi.back())==k){
	    printf("%d %d\n",j+1,i+1);
	}
    }
    u=n-1;
    for(i=n-m+1;i<u;i++){
	remove(l[i-1]);
	if((ma.back()-mi.back())==k){
	    printf("%d %d\n",i+1,n);
	}
    }

    return 0;
}
