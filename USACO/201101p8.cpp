/*
PROG: traffic
LANG: C++
ID: netfire1
*/

#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int c[305],r[305],db[305],dp[305];
int map[305][305];
int cmap[305];

vector<int> q;

int calc(int a,int b,int t){
	int sa,sb;
	int i;
	int la,lb,flaga,flagb;
	int count;

	sa=c[a];
	sb=c[b];
	la=0;
	lb=0;
	flaga=0;
	flagb=0;
	for(i=0;i<=t;i++){
		if(flaga==0){
			if(la==r[a]){
				sa=!sa;
				flaga=1;
				la=0;
			}else{
				la++;
			}
		}else{
			if(sa==0){
				if(la==db[a]){
					sa=!sa;
					la=0;
				}else{
					la++;
				}
			}else{
				if(la==dp[a]){
					sa=!sa;
					la=0;
				}else{
					la++;
				}

			}
		}
		if(flagb==0){
			if(lb==r[b]){
				sb=!sb;
				flagb=1;
				lb=0;
			}else{
				lb++;
			}
		}else{
			if(sb==0){
				if(lb==db[b]){
					sb=!sb;
					lb=0;
				}else{
					lb++;
				}
			}else{
				if(lb==dp[b]){
					sb=!sb;
					lb=0;
				}else{
					lb++;
				}

			}
		}
	}
	if(sa==sb){
		return 0;
	}

	count=0;
	while(sa!=sb){
		count++;
		if(flaga==0){
			if(la==r[a]){
				sa=!sa;
				flaga=1;
				la=0;
			}else{
				la++;
			}
		}else{
			if(sa==0){
				if(la==db[a]){
					sa=!sa;
					la=0;
				}else{
					la++;
				}
			}else{
				if(la==dp[a]){
					sa=!sa;
					la=0;
				}else{
					la++;
				}

			}
		}
		if(flagb==0){
			if(lb==r[b]){
				sb=!sb;
				flagb=1;
				lb=0;
			}else{
				lb++;
			}
		}else{
			if(sb==0){
				if(lb==db[b]){
					sb=!sb;
					lb=0;
				}else{
					lb++;
				}
			}else{
				if(lb==dp[b]){
					sb=!sb;
					lb=0;
				}else{
					lb++;
				}

			}
		}
	}

	return count;
}

int main(){
	int s,d;
	int n,m;
	int i,j,k;
	int a,b,u,v;
	char tmp; 

	scanf("%d %d",&s,&d);
	scanf("%d %d",&n,&m);
	s--;
	d--;

	for(i=0;i<n;i++){
		scanf("%c",&tmp);
		scanf("%c %d %d %d",&tmp,&r[i],&db[i],&dp[i]);	
		if(tmp=='B'){
			c[i]=0;
		}else{
			c[i]=1;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			map[i][j]=-1;			
		}
		cmap[i]=2147483640;
	}
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&u);
		a--;
		b--;
		map[a][b]=u;
		map[b][a]=u;
	}
	
	q.clear();
	cmap[s]=0;
	q.push_back(s);
	while(!q.empty()){
		a=q.back();
		q.pop_back();

		for(i=0;i<n;i++){
			if(map[a][i]!=-1){
				u=calc(a,i,cmap[a]);
				printf("    %d\n",u);
				u+=cmap[a];
				if(u+map[a][i]<cmap[i]){
					cmap[i]=u+map[a][i];
					q.push_back(i);	
				}
			}
		}
	}

	if(cmap[d]==2147483640){
		printf("0\n");
	}else{
		printf("%d\n",cmap[d]);
	}

	return 0;
}
