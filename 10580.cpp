#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

struct pack{
    int idx;

    int f;
    int s;
};

char msg[20490];
char text[102500];
char tmp[102500];
char omsg[102500];

int rank[102500];
int sa[102500];

pack pl[102500];
int point;
int ans;
int ansidx;

vector<string> out;

bool cmpa(pack a,pack b){
    return text[a.idx]<text[b.idx];
}
bool cmpb(pack a,pack b){
    if(a.f==b.f){
	return a.s<b.s;
    }

    return a.f<b.f;
}

int bs(int l,int r){
    int itmp;
    int i,j;

    if(l>r){
	return 0;
    }

    itmp=(l+r)/2;
    i=sa[itmp];

    j=point;
    while(text[i]!=0 && msg[j]!=0){
	if(msg[j]!=text[i]){
	    break;
	}
	i++;
	j++;
    }

    if(ans<(j-point)){
	ans=j-point;
	ansidx=itmp;
    }

    if(text[i]==0){
	bs(itmp+1,r);
    }else if(msg[j]>text[i]){
	bs(itmp+1,r);
    }else if(msg[j]<text[i]){
	bs(l,itmp-1);
    }

    return 0;
}

int main(){
    int i,j;
    int l;

    char c;
    int f,s;
    int u,v;

    gets(msg);
    l=strlen(msg);
    for(i=0;i<l;i++){
	if(msg[i]>='a' && msg[i]<='z'){
	    msg[i]=msg[i]-'a'+'A';
	}
    }

    i=0;
    while(gets(tmp)!=NULL){
	l=strlen(tmp);
	for(j=0;j<l;j++){
	    omsg[i+j]=tmp[j];
	    if(tmp[j]>='a' && tmp[j]<='z'){
		tmp[j]=tmp[j]-'a'+'A';
	    }
	    text[i+j]=tmp[j];
	}
	i+=l;
	omsg[i]='\n';
	text[i]='\n';
	i++;
    }
    omsg[i-1]=0;
    text[i-1]=0;

    l=strlen(text);
    for(i=0;i<l;i++){
	pl[i].idx=i;
    }
    sort(pl,pl+l,cmpa);

    c=text[pl[0].idx];
    rank[pl[0].idx]=1;
    j=1;
    for(i=1;i<l;i++){
	if(text[pl[i].idx]!=c){
	    c=text[pl[i].idx];
	    j++;
	}
	rank[pl[i].idx]=j;
    }

    u=1;
    while(u<l){
	for(i=l-u-1;i>=0;i--){
	    pl[i].idx=i;
	    pl[i].f=rank[i];
	    pl[i].s=rank[i+u];
	}
	for(i=l-u;i<l;i++){
	    pl[i].idx=i;
	    pl[i].f=rank[i];
	    pl[i].s=0;
	}
	sort(pl,pl+l,cmpb);

	f=pl[0].f;
	s=pl[0].s;
	rank[pl[0].idx]=1;
	j=1;
	for(i=1;i<l;i++){
	    if(pl[i].f!=f || pl[i].s!=s){
		f=pl[i].f;
		s=pl[i].s;

		j++;
	    }
	    rank[pl[i].idx]=j;
	}

	u*=2;
    }
    for(i=0;i<l;i++){
	sa[rank[i]-1]=i;
    }

    /*for(i=0;i<l;i++){
	printf("%s\n",&text[sa[i]]);
    }
    printf("\n");*/

    out.clear();

    point=0;
    u=strlen(msg);
    while(true){
	while(point<u){
	    if(msg[point]!=' '){
		break;
	    }
	    point++;
	}
	if(point>=u){
	    break;
	}

	ans=0;
	ansidx=-1;
	bs(0,l);

	i=sa[ansidx];
	v=sa[ansidx]+ans;
	while(i<v){
	    if(omsg[i]!=' '){
		break;
	    }
	    i++;
	}
	j=v-1;
	while(j>=i){
	    if(omsg[j]!=' '){
		break;
	    }
	    j--;
	}
	if(i<=j){
	    c=omsg[j+1];
	    omsg[j+1]=0;

	    out.push_back(&omsg[i]);

	    omsg[j+1]=c;
	}

	point+=ans;
    }

    printf("%d\n",out.size());
    u=out.size();
    for(i=0;i<u;i++){
	printf("%s\n",out[i].c_str());
    }

    return 0;
}
