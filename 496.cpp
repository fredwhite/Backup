#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>

using namespace std;

map<int,int> la;
char str[1000000000];

int main(){
    int a;
    map<int,int>::iterator it;
    int s,count,discount;
    char *pch;

    while(gets(str)!=NULL){
	la.clear();
	s=0;
	pch=strtok(str," ");
	while(pch!=NULL){
	    sscanf(pch,"%d",&a);

	    s++;
	    it=la.find(a);
	    if(it!=la.end()){
		it->second++;
	    }else{
		la.insert(pair<int,int>(a,1));
	    }

	    pch=strtok(NULL," ");
	}
	count=0;
	discount=0;

	gets(str);
	pch=strtok(str," ");
	while(pch!=NULL){
	    sscanf(pch,"%d",&a);

	    count++;
	    it=la.find(a);
	    if(it==la.end()){
		discount++;
	    }else{
		it->second--;
		if(it->second==0){
		    la.erase(it);
		}
	    }

	    pch=strtok(NULL," ");
	}

	if(count==s && discount==0){
	    printf("A equals B\n");
	}else if(count>s && discount==(count-s)){
	    printf("A is a proper subset of B\n");
	}else if(count<s && discount==0){
	    printf("B is a proper subset of A\n");
	}else if(discount==count){
	    printf("A and B are disjoint\n");
	}else{
	    printf("I'm confused!\n");
	}
    }

    return 0;
}
