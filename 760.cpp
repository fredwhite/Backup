#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

char stra[350];
char strb[350];

vector<string> out;

bool cmp(string a,string b){
    int tmp;

    tmp=a.compare(b);
    if(tmp>=0){
	return false;
    }else{
	return true;
    }
}

int main(){
    int i,j,k;
    int u,v;
    int a,b;
    string tmp;
    int ma;
    int c;

    c=0;
    while(true){
	if(c!=0){
	    if(gets(stra)==NULL){
		break;
	    }
	}
	if(gets(stra)==NULL){
	    break;
	}
	gets(strb);
	
	a=strlen(stra);
	b=strlen(strb);

	if(c!=0){
	    printf("\n");
	}
	c=1;
	out.clear();

	for(i=0;i<a;i++){
	    for(j=0;j<b;j++){
		if(stra[i]==strb[j]){
		    tmp.clear();
		    k=0;
		    while(true){
			if((i+k)<a && (j+k)<b){
			    if(stra[i+k]!=strb[j+k]){
				break;
			    }
			    tmp+=stra[i+k];
			}else{
			    break;
			}
			k++;
		    }
		    out.push_back(tmp);
		}
	    }
	}
	
	sort(out.begin(),out.end(),cmp);
	u=out.size();
	ma=0;
	for(i=0;i<u;i++){
	    if(out[i].size()>ma){
		ma=out[i].size();
	    }
	}
	if(ma==0){
	    printf("No common sequence.\n");
	    continue;
	}
	tmp.clear();
	for(i=0;i<u;i++){
	    if(out[i].size()==ma && tmp.compare(out[i])!=0){
		printf("%s\n",out[i].c_str());
		tmp=out[i];
	    }
	}

    }

    return 0;
}
