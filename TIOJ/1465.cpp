#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

long long int l[505];
long long int ans;
int t,m,n;
long long int ma;

int check(long long int x){
    int i;
    long long int u;
    int count;

    if(x<ma){
	return 0;
    }

    count=1;
    u=x;
    for(i=0;i<m;i++){
	if(l[i]>u){
	    count++;
	    u=x;
	}
	u-=l[i];
    }

    if(count<=n){
	return 1;
    }

    return 0;
}

int bs(long long int l,long long int r){
    long long int tmp;

    if(l<=r){
	tmp=(l+r)/2;
	if(check(tmp)==1){
	    ans=tmp;
	    bs(l,tmp-1);
	}else{
	    bs(tmp+1,r);
	}
    }

    return 0;
}

long long int o[1010];
int main(){
    int i,j,k;
    long long int sum;
    long long int u;
    int count;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d %d",&m,&n);
	sum=0;
	ma=-1;
	for(i=0;i<m;i++){
	    scanf("%I64d",&l[i]);
	    sum+=l[i];
	    ma=max(ma,l[i]);
	}
	ans=-1;
	bs(0,sum);

	u=ans;
	j=0;
	count=1;
	
	for(i=m-1;i>=0;i--){
	    if(l[i]>u){
		count++;
		o[j]=-1;
		j++;
		u=ans;
	    }
	    o[j]=l[i];
	    u-=l[i];
	    j++;
	}
	count=n-count;

	printf("%I64d",o[j-1]);
	for(i=j-2;i>=0;i--){
	    if(o[i]==-1){
		printf(" /");
	    }else{
		if(count>0 && o[i+1]!=-1){
		    printf(" /");
		    count--;
		}
		printf(" %I64d",o[i]);
	    }
	}
	printf("\n");
    }

    return 0;
}
