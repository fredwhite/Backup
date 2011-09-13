#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<string.h>
#include<iostream>

using namespace std;

char str[10010];
vector<string> sp;
string out;
vector<string> o;
int dp[10010];
int idx[10010];

int main(){
    int n;
    int l,s;
    int u,v,tmp,cost;
    int i,j,k;
    int st,en;

    char *pch;
    string ns;

    while(true){
	scanf("%d",&n);
	gets(str);
	if(n==0){
	    break;
	}
	sp.clear();
	while(true){
	    gets(str);
	    l=strlen(str);
	    if(l==0){
		break;
	    }
	    pch=strtok(str," ");
	    while(pch!=NULL){
		ns=pch;
		sp.push_back(ns);
		pch=strtok(NULL," ");
	    }
	}
	s=sp.size();
	printf("%d\n",s);
	for(i=0;i<10010;i++){
	    dp[i]=2147483640;
	    idx[i]=0;
	}
	for(k=0;k<s;k++){
	    j=0;
	    u=0;
	    idx[k]=k;
	    while((k-j)>=0){
		u+=sp[k-j].size();
		if((u+j)>n){
		    break;
		}
		if(j==0){
		    if(u<n){
			cost=500;
		    }else{
			cost=0;
		    }
		}else{
		    tmp=(n-u)%j;
		    v=(n-u)/j-1;
		    cost=0;
		    for(i=0;i<tmp;i++){
			cost+=(v+1)*(v+1);
		    }
		    for(i=tmp;i<j;i++){
			cost+=v*v;
		    }
		}
		if((k-j)>0){
		    cost+=dp[k-j-1];	
		}
		if(cost<dp[k]){
		    dp[k]=cost;
		    idx[k]=k-j;
		}
		j++;
	    }
	}

	en=s-1;
	o.clear();
	while(true){
	    out.clear();
	    st=idx[en];
	    l=en-st+1;
	    u=0;

	    if(l==1){
		out=sp[st];
		out+='\n';
		o.push_back(out);
	    }else{
		for(i=st;i<=en;i++){
		    u+=sp[i].size();
		}

		tmp=st+(l-1)-(n-u)%(l-1);
		v=(n-u)/(l-1);
		for(i=st;i<tmp;i++){
		    out+=sp[i];
		    for(j=0;j<v;j++){
			out+=' ';
		    }
		}
		for(i=tmp;i<en;i++){
		    out+=sp[i];
		    for(j=0;j<=v;j++){
			out+=' ';
		    }
		}
		out+=sp[en];
		out+='\n';
		o.push_back(out);
	    }
	    if(st==0){
		break;
	    }
	    en=st-1;
	}
	u=o.size();
	for(i=u-1;i>=0;i--){
	    printf("%s",o[i].c_str());
	}
	printf("\n");
    }

    return 0;
}
