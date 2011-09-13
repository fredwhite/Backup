#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

struct node{
    int idx;
    int os;

    int f;
    int s;
};

char str[105][1010];
int l[105];
int ra[105][1010];
vector<node> sl;
vector<node> out;

char hemap[101000];
vector<int> he;
deque<int> de;

char lmap[1010];
int lcp[105][1010];

bool cmpa(node a,node b){
    return str[a.idx][a.os]<str[b.idx][b.os];
}
bool cmpb(node a,node b){
    if(a.f==b.f){
	return a.s<b.s;
    }
    return a.f<b.f;
}
bool cmpc(int a,int b){
    return lcp[sl[a].idx][sl[a].os]>lcp[sl[b].idx][sl[b].os];
}

int main(){
    int n;
    int i,j;
    int u,v;
    int flag;
    int count;

    int f,s;
    char c;
    int r;
    int lc;

    node nn,cn;
    int ma,lim;

    count=0;
    while(true){
	scanf("%d",&n);
	if(n==0){
	    break;
	}

	if(count!=0){
	    printf("\n");
	}
	count=1;

	sl.clear();

	for(i=0;i<n;i++){
	    scanf("%s",str[i]);
	    u=strlen(str[i]);
	    l[i]=u;
	    for(j=0;j<u;j++){
		nn.idx=i;
		nn.os=j;
		nn.f=0;
		nn.s=0;
		sl.push_back(nn);
	    }
	}
	sort(sl.begin(),sl.end(),cmpa);		

	u=sl.size();

	c=0;
	v=0;
	for(i=0;i<u;i++){
	    if(str[sl[i].idx][sl[i].os]!=c){
		v++;
		c=str[sl[i].idx][sl[i].os];
	    }
	    ra[sl[i].idx][sl[i].os]=v; 
	}

	r=1;
	while(true){
	    flag=0; 
	    for(i=0;i<u;i++){
		sl[i].f=ra[sl[i].idx][sl[i].os];
		if((sl[i].os+r)<l[sl[i].idx]){
		    sl[i].s=ra[sl[i].idx][sl[i].os+r];
		    flag=1;
		}else{
		    sl[i].s=0;
		}
	    }
	    if(flag==0){
		break;
	    }

	    sort(sl.begin(),sl.end(),cmpb);

	    v=0;
	    f=-1;
	    s=-1;
	    for(i=0;i<u;i++){
		if(sl[i].f!=f || sl[i].s!=s){
		    v++;
		    f=sl[i].f;
		    s=sl[i].s;
		}
		ra[sl[i].idx][sl[i].os]=v; 
	    }

	    r*=2;
	}
	for(i=0;i<u;i++){
	    ra[sl[i].idx][sl[i].os]=i;
	}

	for(i=0;i<n;i++){
	    lc=0;
	    for(j=0;j<l[i];j++){
		if(ra[i][j]==0){
		    lcp[i][j]=2147483647;
		}else{
		    v=ra[i][j]-1;
		    if(lc>0){
			lc--;
		    }
		    while((j+lc)<l[i] && (sl[v].os+lc)<l[sl[v].idx]){
			if(str[i][j+lc]!=str[sl[v].idx][sl[v].os+lc]){
			    break;
			}
			lc++;
		    }
		    lcp[i][j]=lc;
		}
	    }
	}

	for(i=0;i<n;i++){
	    lmap[i]=0;
	}
	for(i=0;i<u;i++){
	    hemap[i]=0;
	}
	he.clear();
	de.clear();
	v=0;
	flag=0;

	out.clear();
	ma=0;

	for(i=0;i<u;i++){
	    if(lmap[sl[i].idx]==0){
		v++;
	    }
	    lmap[sl[i].idx]++;
	    if(i>0){
		he.push_back(i);
		push_heap(he.begin(),he.end(),cmpc);
	    }
	    de.push_back(i);

	    while(!de.empty()){
		if(lmap[sl[de.front()].idx]>1){
		    hemap[de.front()]=1;
		    lmap[sl[de.front()].idx]--;
		    de.pop_front();
		}else if(lmap[sl[de.front()].idx]==1 && (v-1)*2>n && v>2){
		    v--;
		    hemap[de.front()]=1;
		    lmap[sl[de.front()].idx]--;
		    de.pop_front();
		}else{
		    break;
		}
	    }
	    hemap[de.front()]=1;

	    while(!he.empty()){
		if(hemap[he.front()]==1){
		    pop_heap(he.begin(),he.end(),cmpc);
		    he.pop_back();
		}else{
		    break;
		}
	    }

	    if(v*2>n && v>=2){
		cn=sl[he.front()];
		lim=lcp[cn.idx][cn.os];
		if(lim>ma){
		    out.clear();
		    out.push_back(cn);
		    flag=1;
		    ma=lim;
		}else if(lim==ma){
		    if(flag==0){
		        out.push_back(cn);
		        flag=1;
		    }
		}else{
		    flag=0;
		}
	    }else{
		flag=0;
	    }
	}

	/*for(i=0;i<u;i++){
	    printf("  %d %s  %d\n",sl[i].idx,&str[sl[i].idx][sl[i].os],lcp[sl[i].idx][sl[i].os]);
	}*/

	if(ma==0){
	    printf("?\n");
	}else{
	    u=out.size();
	    for(i=0;i<u;i++){
		c=str[out[i].idx][out[i].os+ma];
		str[out[i].idx][out[i].os+ma]=0;
		printf("%s\n",&str[out[i].idx][out[i].os]);
		str[out[i].idx][out[i].os+ma]=c;
	    }
	}
    }

    return 0;
}
