#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<string>

using namespace std;

map<string,int> table;
int lik[100010];
int c[100010];

int dis(int a){
    if(lik[a]==a){
	return a;
    }

    return lik[a]=dis(lik[a]);
}

int main(){
    int i,j;

    int t;
    int n;
    map<string,int>::iterator ita,itb;
    int count;
    char stra[50],strb[50];
    string sa,sb;
    int a,b;

    scanf("%d",&t);
    for(;t>0;t--){
	scanf("%d",&n);
	count=0;
	table.clear();
	for(i=0;i<n;i++){
	    scanf("%s %s",stra,strb);
	    sa=stra;
	    sb=strb;

	    ita=table.find(sa);
	    if(ita==table.end()){
		table.insert(pair<string,int>(sa,count));
		a=count;
		lik[a]=a;
		c[a]=1;
		count++;
	    }else{
		a=dis(ita->second);
	    }

	    itb=table.find(sb);
	    if(itb==table.end()){
		table.insert(pair<string,int>(sb,count));
		b=count;
		lik[b]=b;
		c[b]=1;
		count++;
	    }else{
		b=dis(itb->second);
	    }
	    
	    if(a!=b){
		lik[a]=b; 
		c[b]+=c[a];
	    }

	    printf("%d\n",c[b]);
	}
    }

    return 0;
}
