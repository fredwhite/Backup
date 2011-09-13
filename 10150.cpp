#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<queue>

using namespace std;

struct pack{
    int idx;
    char str[20];
};

vector<pack> so;
map<string,int> ta;
vector<string> sm;
vector<int> t;

vector<int> mp[26000];
queue<int> q;
char lmap[26000];
int path[26000];

char str[20];
char stra[20],strb[20];

bool cmp(pack a,pack b){
    if(strcmp(a.str,b.str)>0){
	return false;
    }
    return true;
}

int main(){
    map<string,int>::iterator it,ita,itb;
    int i,j,k;
    int c;
    int l;
    int u,v;
    int s,d;
    int flag;
    int a;

    pack np;

    ta.clear();
    so.clear();
    sm.clear();
    c=0;

    while(true){
	gets(str);
	l=strlen(str);
	if(l==0){
	    break;
	}

	it=ta.find(str);
	if(it==ta.end()){
	    ta.insert(pair<string,int>(str,c));
	    np.idx=c;
	    for(i=0;i<l;i++){
		k=0;
		for(j=0;j<l;j++){
		    if(j!=i){
			np.str[k]=str[j];
			k++;
		    }
		}
		np.str[k]=0;
		so.push_back(np);
	    }

	    sm.push_back(str);

	    c++;
	}	
    }
    sort(so.begin(),so.end(),cmp);

    for(i=0;i<c;i++){
	mp[i].clear();
    }

    if(c>0){
	strcpy(str,so[0].str);
	t.clear();
	t.push_back(so[0].idx);

	u=so.size();

	for(i=1;i<u;i++){
	    if(strcmp(str,so[i].str)==0){
		v=t.size();
		flag=0;
		for(j=0;j<v;j++){
		    if(t[j]==so[i].idx){
			flag=1;
		    }
		}
		if(flag==0){		    
		    for(j=0;j<v;j++){
			mp[t[j]].push_back(so[i].idx);
			mp[so[i].idx].push_back(t[j]);
		    }
		    t.push_back(so[i].idx);
		}
	    }else{
		t.clear();
		t.push_back(so[i].idx);
		strcpy(str,so[i].str);
	    }
	}
    }

    k=0;
    while(scanf("%s %s",stra,strb)!=EOF){
	ita=ta.find(stra);
	itb=ta.find(strb);

	if(k!=0){
	    printf("\n");
	}
	k=1;

	if(ita==ta.end() || itb==ta.end()){
	    printf("No solution.\n");
	    continue;
	}
	s=ita->second;
	d=itb->second;

	for(i=0;i<c;i++){
	    lmap[i]=0;
	    path[i]=-1;
	}

	q.push(s);
	lmap[s]=1;
	flag=0;
	while(!q.empty()){
	    a=q.front();
	    q.pop();

	    if(a==d){
		flag=1;
		break;
	    }

	    u=mp[a].size();
	    for(i=0;i<u;i++){
		v=mp[a][i];
		if(lmap[v]==0){
		    lmap[v]=1;
		    path[v]=a;
		    q.push(v);
		}
	    }
	}

	if(flag==1){
	    t.clear();
	    u=d;
	    while(u!=-1){
		t.push_back(u);
		u=path[u];
	    }

	    while(!t.empty()){
		printf("%s\n",sm[t.back()].c_str());
		t.pop_back();
	    }

	}else{
	    printf("No solution.\n");
	}

    }

    return 0;
}
