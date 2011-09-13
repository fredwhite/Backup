#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>

using namespace std;

struct pack{
    int idx;
    int num;
};
struct uni{
    long long int mix;
    int mixcma;
    long long int zero;
    int zerocma;
};

int vn;
int l[300010];
pack pl[300010];
int tl[300010];

uni ca[300010];
uni cb[300010];

bool cmp(pack a,pack b){
    return a.num<b.num;
}

int lowbit(int x){
    return x&(x^(x-1));
}

int insa(int x,uni un){
    int i;
    int u;

    u=vn+1;
    i=x+1;
    while(i<=u){
	if(un.zero<ca[i].zero){
	    ca[i].zero=un.zero;
	    ca[i].zerocma=un.zerocma;
	}else if(un.zero==ca[i].zero && un.zerocma>ca[i].zerocma){
	    ca[i].zerocma=un.zerocma;
	}

	i+=lowbit(i);
    }
}
int insb(int x,uni un){
    int i;
    int u;
    
    u=vn+1;
    i=(vn-x)+1;
    while(i<=u){
	if(un.mix<cb[i].mix){
	    cb[i].mix=un.mix;
	    cb[i].mixcma=un.mixcma;
	}else if(un.mix==cb[i].mix && un.mixcma>cb[i].mixcma){
	    cb[i].mixcma=un.mixcma;
	}

	i+=lowbit(i);
    }
}

uni querya(int x){
    int i;
    uni un;

    un.zero=5764607523034234879LL;
    un.zerocma=0;

    i=x+1;
    while(i>0){
	if(ca[i].zero<un.zero){
	    un.zero=ca[i].zero;
	    un.zerocma=ca[i].zerocma;
	}else if(ca[i].zero==un.zero && ca[i].zerocma>un.zerocma){
	    un.zerocma=ca[i].zerocma;
	}

	i-=lowbit(i);
    }

    return un;
}
uni queryb(int x){
    int i;
    uni un;

    un.mix=5764607523034234879LL;
    un.mixcma=0;

    i=(vn-x)+1;
    while(i>0){
	if(cb[i].mix<un.mix){
	    un.mix=cb[i].mix;
	    un.mixcma=cb[i].mixcma;
	}else if(cb[i].mix==un.mix && cb[i].mixcma>un.mixcma){
	    un.mixcma=cb[i].mixcma;
	}

	i-=lowbit(i);
    }

    return un;
}

int main(){
    int n,m;
    int i,j;

    int u,v;

    uni un,una,unb;

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
	scanf("%d",&l[i]);
	pl[i].idx=i;
	pl[i].num=(n-i)-l[i];
    }
    sort(pl,pl+n,cmp);

    u=-2000000000;
    v=-1;
    for(i=0;i<n;i++){
	if(pl[i].num!=u){
	    u=pl[i].num;
	    v++;
	}
	tl[pl[i].idx]=v;
    }
    vn=v;

    u=vn+1;
    for(i=0;i<=u;i++){
	ca[i].zero=5764607523034234879LL;
	ca[i].zerocma=0;
	cb[i].mix=5764607523034234879LL;
	cb[i].mixcma=0;
    }

    un.mix=(long long int)(n-l[0]);
    un.mixcma=0;
    un.zero=0LL;
    un.zerocma=0;
    insa(tl[0],un);
    insb(tl[0],un);

    for(i=1;i<n;i++){
	una=querya(tl[i]);

	if((tl[i]+1)<=vn){
	    unb=queryb(tl[i]+1);

	    if((unb.mix-(long long int)(n-i)+(long long int)l[i])<una.zero){
		un.zero=unb.mix-(long long int)(n-i)+(long long int)l[i];
		un.zerocma=unb.mixcma+1;
		un.mix=unb.mix;
		un.mixcma=unb.mixcma+1;
	    }else if((unb.mix-(long long int)(n-i)+(long long int)l[i])==una.zero){
		if(unb.mixcma>una.zerocma){
		    un.zero=unb.mix-(long long int)(n-i)+(long long int)l[i];
		    un.zerocma=unb.mixcma+1;
		    un.mix=unb.mix;
		    un.mixcma=unb.mixcma+1;
		}else{
		    un.zero=una.zero;
		    un.zerocma=una.zerocma+1;
		    un.mix=una.zero+(long long int)(n-i)-(long long int)l[i];
		    un.mixcma=una.zerocma+1;
		}
	    }else{
		un.zero=una.zero;
		un.zerocma=una.zerocma+1;
		un.mix=una.zero+(long long int)(n-i)-(long long int)l[i];
		un.mixcma=una.zerocma+1;
	    }
	}else{
	    un.zero=una.zero;
	    un.zerocma=una.zerocma+1;
	    un.mix=una.zero+(long long int)(n-i)-(long long int)l[i];
	    un.mixcma=una.zerocma+1;
	}

	insa(tl[i],un);
	insb(tl[i],un);
    }

    printf("%d\n",min(m,un.zerocma));

    return 0;
}
