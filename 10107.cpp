#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a;
vector<int> b;

bool cmp(int q,int w){
	return q>w;
}

int main(){
	int n,m;
	int flag=0;

	scanf("%d",&n);
	printf("%d\n",n);
	m=n;
	flag=1;
	while(scanf("%d",&n)!=EOF){
		if(flag==1){
			if(n<m){
				a.push_back(n);
				b.push_back(m);
				push_heap(a.begin(),a.end());
				push_heap(b.begin(),b.end(),cmp);
			}else{
				a.push_back(m);
				b.push_back(n);
				push_heap(a.begin(),a.end());
				push_heap(b.begin(),b.end(),cmp);
			}
			printf("%d\n",(a[0]+b[0])/2);
			flag=0;
		}else{
			if(n<a[0]){
				m=a[0];
				pop_heap(a.begin(),a.end());
				a.pop_back();
				a.push_back(n);
				push_heap(a.begin(),a.end());
			}else if(n>b[0]){
				m=b[0];
				pop_heap(b.begin(),b.end(),cmp);
				b.pop_back();
				b.push_back(n);
				push_heap(b.begin(),b.end(),cmp);
			}else{
				m=n;
			}
			printf("%d\n",m);
			flag=1;
		}
	}
	
	return 0;
}
