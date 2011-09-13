#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

struct node{
    int os;

    int f;
    int s;
};

char ostr[1010];
char str[1010];
int l;
vector<node> sl;
int ra[1010];
int cou;
int offset;
int lcp[1010];

bool cmpa(node a,node b){
    return str[a.os]<str[b.os];
}
bool cmpb(node a,node b){
    if(a.f==b.f){
	return a.s<b.s;
    }
    return a.f<b.f;
}
bool cmpc(node a,node b){
    if(ra[a.os]==ra[b.os]){
	if((a.os+cou)>l || (b.os+cou)>l){
	    return a.os>b.os;
	}else{
	    return ra[a.os+offset]<ra[b.os+offset];
	}
    }
    return ra[a.os]<ra[b.os];
}

int main(){
    int i,j;
    int u,v;
    int f,s;
    int ma;

    char c;
    node nn;

    while(gets(ostr)!=NULL){
	u=strlen(ostr);
	if(u==0){
	    break;
	}
	l=0;
	for(i=0;i<u;i++){
	    if(ostr[i]!=' '){
		str[l]=ostr[i];
		l++;
	    }
	}

	sl.clear();
	for(i=0;i<l;i++){
	    nn.os=i;
	    nn.f=0;
	    nn.s=0;
	    sl.push_back(nn);
	}

	sort(sl.begin(),sl.end(),cmpa);
	c=0;
	u=0;
	for(i=0;i<l;i++){
	    if(str[sl[i].os]!=c){
		c=str[sl[i].os];
		u++;
	    }
	    ra[sl[i].os]=u;
	}

	u=1;
	while(u<l){
	    for(j=0;j<l;j++){
		sl[j].f=ra[sl[j].os];
		if((sl[j].os+u)<l){
		    sl[j].s=ra[sl[j].os+u];
		}else{
		    sl[j].s=0;
		}
	    }
	    sort(sl.begin(),sl.end(),cmpb);

	    f=-1;
	    s=-1;
	    v=0;
	    for(j=0;j<l;j++){
		if(sl[j].f!=f || sl[j].s!=s){
		    f=sl[j].f;
		    s=sl[j].s;
		    v++;
		}
		ra[sl[j].os]=v;
	    }
	    u*=2;
	}
	for(i=0;i<l;i++){
	    ra[sl[i].os]=i;
	}

	u=0;
	for(i=0;i<l;i++){
	    if(ra[i]==0){
		lcp[i]=0;
	    }else{
		if(u>0){
		    u--;
		}
		v=ra[i]-1;
		while(i+u<l && sl[v].os+u<l){
		    if(str[i+u]!=str[sl[v].os+u]){
			break;
		    }
		    u++;
		}
		lcp[i]=u;
	    }
	}

	for(i=1;i<l;i++){
	    u=0;
	    ma=0;
	    for(j=1;j<l;j++){
		if(lcp[sl[j].os]<i){
		    ma=max(ma,u);
		    u=0;
		}else{
		    u++;
		}
	    }	
	    ma=max(ma,u);
	    ma+=1;
	    if(ma>1){
		printf("%d\n",ma);
	    }else{
		break;
	    }
	}

	printf("\n");
    }

    return 0;
}
