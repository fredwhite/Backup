#include<stdio.h>
#include<stdlib.h>

int l[300010];
int n,m;
int ans;

int check(int lim){
    int i;
    int a,b;
    int u,v;
    int c;

    for(i=0;i<n;i++){
	if((l[i]+l[(i+1)%n])>lim){
	    return 0;
	}
    }

    c=m-2;
    u=0;
    v=1;
    a=l[0]+l[1];
    b=l[1];
    for(i=2;i<n;i++){
	if((a+l[i])>lim){
	    if((b+l[i])>lim){
		if((i-1)==v){
		    return 0;
		}

		c-=2;
		if(c<0){
		    return 0;
		}

		u=i-1;
		v=i;
		a=l[i-1]+l[i];
		b=l[i];
	    }else{
		c-=1;
		if(c<0){
		    return 0;
		}

		u=v;
		v=i;
		a=b+l[i];
		b=l[i];
	    }
	}else{
	    a+=l[i];
	    b+=l[i];
	}
    }

    if((b+l[0])>lim){
	c-=1;
	if(c<0){
	    return 0;
	}
    }

    return 1;
}

int bs(int l,int r){
    int tmp;

    if(l>r){
	return 0;
    }

    tmp=(l+r)/2;
    if(check(tmp)==1){
	ans=tmp;
	bs(l,tmp-1);
    }else{
	bs(tmp+1,r);
    }

    return 0;
}

int main(){
    int i;
    int u;

    while(scanf("%d %d",&n,&m)!=EOF){
	u=0;
	for(i=0;i<n;i++){
	    scanf("%d",&l[i]);
	    u+=l[i];
	}
	bs(0,u);
	printf("%d\n",ans);
    }

    return 0;
}
