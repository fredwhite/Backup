#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

struct node{
    int os;

    int f;
    int s;
};

int l;
vector<node> sl;
int ra[1010];
char str[1010];

char ostr[1010];
int ol;
int ans;

bool cmpa(node a,node b){
    return str[a.os]<str[b.os];
}
bool cmpb(node a,node b){
    if(a.f==b.f){
	return a.s<b.s;
    }
    return a.f<b.f;
}

int bsa(int ll,int r){
    int tmp;
    int i;

    if(ll>r){
	return 0;
    }

    tmp=(ll+r)/2;
    i=0;
    while(i<ol && (sl[tmp].os+i)<l){
	if(ostr[i]!=str[sl[tmp].os+i]){
	    break;
	}
	i++;
    }
    if(i==ol){
	ans=tmp;
	bsa(ll,tmp-1);
    }else{
	if((sl[tmp].os+i)==l){
	    bsa(tmp+1,r);
	}else if(ostr[i]<str[sl[tmp].os+i]){
	    bsa(ll,tmp-1);
	}else{
	    bsa(tmp+1,r);
	}
    }

    return 0;
}
int bsb(int ll,int r){
    int tmp;
    int i;

    if(ll>r){
	return 0;
    }

    tmp=(ll+r)/2;
    i=0;
    while(i<ol && (sl[tmp].os+i)<l){
	if(ostr[i]!=str[sl[tmp].os+i]){
	    break;
	}
	i++;
    }
    if(i==ol){
	ans=tmp;
	bsb(tmp+1,r);
    }else{
	if((sl[tmp].os+i)==l){
	    bsb(tmp+1,r);
	}else if(ostr[i]<str[sl[tmp].os+i]){
	    bsb(ll,tmp-1);
	}else{
	    bsb(tmp+1,r);
	}
    }

    return 0;
}


int main(){
    int t;
    int i,j;
    int u,v;
    char c;
    int n;
    int f,s;

    node nn;
    int ma;
    int maidx;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%s",str);
	l=strlen(str);

	sl.clear();
	for(i=0;i<l;i++){
	    nn.os=i;
	    nn.f=0;
	    nn.s=0;
	    sl.push_back(nn);
	}
	sort(sl.begin(),sl.end(),cmpa);

	u=0;
	c=-1;
	for(i=0;i<l;i++){
	    if(str[sl[i].os]!=c){
		c=str[sl[i].os];
		u++;
	    }
	    ra[sl[i].os]=u;
	}

	u=1;
	while(u<l){
	    for(i=0;i<l;i++){
		sl[i].f=ra[sl[i].os];
		if((sl[i].os+u)<l){
		    sl[i].s=ra[sl[i].os+u];
		}else{
		    sl[i].s=0;
		}
	    }
	    
	    sort(sl.begin(),sl.end(),cmpb);

	    f=-1;
	    s=-1;
	    v=0;
	    for(i=0;i<l;i++){
		if(sl[i].f!=f || sl[i].s!=s){
		    v++;
		    f=sl[i].f;
		    s=sl[i].s;
		}
		ra[sl[i].os]=v;
	    }
	    u*=2;
	}
	for(i=0;i<l;i++){
	    ra[sl[i].os]=i;
	}

	u=0;
	ma=0;
	maidx=-1;
	for(i=0;i<l;i++){
	    if(ra[i]!=0){
		v=ra[i]-1;
		if(u>0){
		    u--;
		}
		while((i+u)<l && (sl[v].os+u)<l){
		    if(str[i+u]!=str[sl[v].os+u]){
			break;
		    }
		    u++;
		}

		if(u>ma){
		    ma=u;
		    maidx=i;
		}else if(u==ma){
		    if(ra[i]<ra[maidx]){
			maidx=i;
		    }
		}
	    }
	}

	if(ma>0){
	    ol=ma;
	    memcpy(ostr,&str[maidx],ol);
	    ostr[ol]=0;
	    bsa(0,l-1);
	    f=ans;
	    bsb(0,l-1);
	    s=ans;
	    printf("%s %d\n",ostr,s-f+1);
	}else{
	    printf("No repetitions found!\n");
	}
    }

    return 0;
}
