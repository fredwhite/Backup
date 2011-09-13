#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;

struct node{
    int type;
    int x;
    int s;
    int t;

    int idx;
};
vector<node> la;
vector<node> lb;

vector<node> q;

char lmap[100010];

bool cmpa(node a,node b){
    if(a.x==b.x){
	return a.type<b.type;
    }
    return a.x<b.x;
}
bool cmpb(node a,node b){
    return a.t<b.t;
}

int get(int x){
    node cn;

    do{
	if(q.empty()){
	    return -1;
	}

	pop_heap(q.begin(),q.end(),cmpb);
	cn=q.back();
	q.pop_back();
    }while(lmap[cn.idx]==1 || cn.t<x);

    return cn.idx;
}

int main(){
    int na,nb;
    int i,j;
    int s,t;
    int u,v;

    int last;
    int flag;
    int counta,countb;

    node nn,cn;

    while(scanf("%d %d",&na,&nb)!=EOF){
	la.clear();
	lb.clear();
	for(i=0;i<na;i++){
	    scanf("%d %d",&s,&t);
	    nn.type=0;
	    nn.idx=i;
	    nn.x=s;
	    nn.s=s;
	    nn.t=t;
	    la.push_back(nn);
	    nn.type=3;
	    nn.idx=i;
	    nn.x=t;
	    nn.s=-1;
	    nn.t=-1;
	    la.push_back(nn);
	}

	for(i=0;i<nb;i++){
	    scanf("%d %d",&s,&t);
	    nn.type=0;
	    nn.idx=i;
	    nn.x=s;
	    nn.s=s;
	    nn.t=t;
	    lb.push_back(nn);
	    nn.type=3;
	    nn.idx=i;
	    nn.x=t;
	    nn.s=-1;
	    nn.t=-1;
	    lb.push_back(nn);
	}

	scanf("%d %d",&s,&t);

	nn.type=1;
	nn.x=s;
	nn.s=-1;
	nn.t=-1;
	la.push_back(nn);
	lb.push_back(nn);

	nn.type=2;
	nn.x=t;
	nn.s=-1;
	nn.t=-1;
	la.push_back(nn);
	lb.push_back(nn);

	sort(la.begin(),la.end(),cmpa);
	sort(lb.begin(),lb.end(),cmpa);

	counta=0;
	for(i=0;i<na;i++){
	    lmap[i]=0;
	}
	q.clear();
	last=-1;
	flag=0;
	u=la.size();
	for(i=0;i<u;i++){
	    if(flag==0){
		if(la[i].type==1){
		    last=get(la[i].x);
		    if(last==-1){
			counta=-1;
			break;
		    }
		    flag=1;
		    counta=1;
		}else if(la[i].type==0){
		    q.push_back(la[i]);
		    push_heap(q.begin(),q.end(),cmpb);
		}else if(la[i].type==3){
		    lmap[la[i].idx]=1;
		}
	    }else{
		if(la[i].type==2){
		    break;
		}else if(la[i].type==0){
		    q.push_back(la[i]);
		    push_heap(q.begin(),q.end(),cmpb);
		}else if(la[i].type==3){
		    lmap[la[i].idx]=1;
		    if(la[i].idx==last){
			last=get(la[i].x);
			if(last==-1){
			    counta=-1;
			    break;
			}
			counta++;
		    }
		}
	    }
	}

	countb=0;
	for(i=0;i<nb;i++){
	    lmap[i]=0;
	}
	q.clear();
	last=-1;
	flag=0;
	u=lb.size();
	for(i=0;i<u;i++){
	    if(flag==0){
		if(lb[i].type==1){
		    last=get(lb[i].x);
		    if(last==-1){
			countb=-1;
			break;
		    }
		    flag=1;
		    countb=1;
		}else if(lb[i].type==0){
		    q.push_back(lb[i]);
		    push_heap(q.begin(),q.end(),cmpb);
		}else if(lb[i].type==3){
		    lmap[lb[i].idx]=1;
		}
	    }else{
		if(lb[i].type==2){
		    break;
		}else if(lb[i].type==0){
		    q.push_back(lb[i]);
		    push_heap(q.begin(),q.end(),cmpb);
		}else if(lb[i].type==3){
		    lmap[lb[i].idx]=1;
		    if(lb[i].idx==last){
			last=get(lb[i].x);
			if(last==-1){
			    countb=-1;
			    break;
			}
			countb++;
		    }
		}
	    }
	}


	if(counta!=-1){
	    if(countb==-1){
		printf("A WIN\n");
	    }else if(counta<=countb){
		printf("A WIN\n");
	    }else{
		printf("B WIN\n");
	    }
	}else if(countb!=-1){
	    if(counta==-1){
		printf("B WIN\n");
	    }
	}else{
	    printf("TIE\n");
	}
    }

    return 0;
}
