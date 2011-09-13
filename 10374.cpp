#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<map>
#include<string>

using namespace std;

map<string,string> tmap;
map<string,int> tcmap;
map<string,int> icmap;

int main(){
    int t,n,m;
    int i,j,k;
    int u,v;
    int l;
    char str[100];
    char nstr[100],tstr[100];
    string ns,ts;
    string os;
    int ma;
    int flag;

    map<string,string>::iterator tit;
    map<string,int>::iterator it;

    scanf("%d",&t);
    for(k=0;k<t;k++){
	scanf("%d",&n);
	gets(str);

	tmap.clear();
	tcmap.clear();
	icmap.clear();
	os.clear();

	for(i=0;i<n;i++){
	    gets(nstr);
	    gets(tstr);
	    ns=nstr;
	    if(strcmp(tstr,"independent")!=0){
		ts=tstr;
		tmap.insert(pair<string,string>(ns,ts));
		tcmap.insert(pair<string,int>(ts,0));
	    }else{
		icmap.insert(pair<string,int>(ns,0));
	    }
	}
	scanf("%d",&m);
	gets(str);
	ma=0;
	flag=0;
	for(i=0;i<m;i++){
	    gets(nstr);
	    ns=nstr;
	    tit=tmap.find(ns);
	    if(tit!=tmap.end()){
		it=tcmap.find(tit->second);
		it->second++;
		if(it->second>ma){
		    ma=it->second;
		    os=it->first;
		    flag=1;
		}else if(it->second==ma){
		    flag=0;
		}
	    }else{
		it=icmap.find(ns);
		if(it!=icmap.end()){
		    it->second++;
		    if(it->second>ma){
			ma=it->second;
			os="independent";
			flag=1;
		    }else if(it->second==ma){
			flag=0;
		    }
		}
	    }
	}
	if(k>0){
	    printf("\n");
	}
	if(flag==0){
	    printf("tie\n");
	}else{
	    printf("%s\n",os.c_str());
	}
    }

    return 0;
}
