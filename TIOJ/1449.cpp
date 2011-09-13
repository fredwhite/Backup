#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int dp[1010][1010];
int l[1010];

bool cmp(int a,int b){
    return a<b;
}

int main(){
    int n,k;
    int i,j;
    int u,v;

    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
	scanf("%d",&l[i]);
    }
    sort(l,l+n,cmp);

    return 0;
}
