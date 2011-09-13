#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[1000010];
int fail[1000010];
int ans;

int fa(){
    int i,j;
    int l;
    int u,v;

    l=strlen(str);
    fail[0]=-1;
    j=-1;
    for(i=1;i<l;i++){
	while(j>=0 && str[i]!=str[j+1]){
	    j=fail[j];
	}
	if(str[i]==str[j+1]){
	    j+=1;
	}

	u=i+1;
	v=j+1;
	if(v>0){
	    if(ans!=-1 && (u-v)!=ans){
		ans=-1;
	    }
	    if(v*2==u){
		ans=v;
	    }
	}else{
	    ans=-1;
	}

	fail[i]=j;
    }

    return 0;
}

int main(){
    int i;
    int l;

    while(true){
	scanf("%s",str);
	if(str[0]=='.'){
	    break;
	}

	l=strlen(str);
	ans=-1;
	fa();
	if(ans!=-1){
	    printf("%d\n",l/ans);
	}else{
	    printf("1\n");
	}
    }

    return 0;
}
