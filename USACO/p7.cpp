/*
PROG: paren
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

char l[100005];
vector<long long int> q;

int main(){
    freopen("paren.in","r",stdin);
    freopen("paren.out","w",stdout);

    int n;
    int i,j;
    char p;
    long long int u,v;

    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%d",&l[i]);
    }
    p=10;
    q.push_back(0);
    for(i=0;i<n;i++){
	if(l[i]==0){
	    q.push_back(0);
	}else{
	    if(p==0){
		q.pop_back();
		u=1LL;
		q[q.size()-1]=(q[q.size()-1]+u)%12345678910LL;
	    }else{
		u=(q[q.size()-1]*2LL)%12345678910LL;
		q.pop_back();
		q[q.size()-1]=(q[q.size()-1]+u)%12345678910LL;
	    }
	}    
	p=l[i];
    }

    printf("%lld\n",q[0]);	

    return 0;
}
