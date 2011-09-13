#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

vector<int> qa;
vector<int> qb;
vector<int> qc;

vector<int> patha[65546];
vector<int> pathb[65546];
vector<int> pathc[65546];

int n,m;

int ru(int deep){
    int i;
    int u,v;
    int flag;

    patha[deep]=qa;
    pathb[deep]=qb;
    pathc[deep]=qc;

    if(deep==m){
	if(qc.size()==n){
	    return 1;
	}else{
	    return 0;
	}
    }


    return 0;
}

int main(){
    int i,j,k;

    while(true){
	scanf("%d %d",&n,&m);
	if(n==0 && m==0){
	    break;
	}

	qa.clear();
	qb.clear();
	qc.clear();

	for(i=n-1;i>=0;i--){
	    qa.push_back(i);
	}
	
	printf("%d\n",ru(0));

    }


    return 0;
}
