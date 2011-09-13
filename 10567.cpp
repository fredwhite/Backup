#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stra[1000010];
char strb[1000010];
int *link[1000010][55];
int *q[55];

int pool[66003560];
int cp;

int tran(char c){
    if(c>='a' && c<='z'){
	return c-'a';
    }else{
	return 26+c-'A';
    }
}

int main(){
    int i,j,k;
    int n;
    int l;
    int u,v;

    int flag;
    int mi,ma;

    scanf("%s",stra);

    for(i=0;i<55;i++){
	q[i]=NULL;
    }

    cp=0;
    l=strlen(stra);
    for(i=0;i<l;i++){
	stra[i]=tran(stra[i]);

	if(q[stra[i]]!=NULL){
	    *q[stra[i]]=i;
	    q[stra[i]]=NULL;
	}
	for(j=0;j<52;j++){
	    if(q[j]==NULL){
		pool[cp]=-1;
		q[j]=&pool[cp];
		cp++;
	    }
	    link[i][j]=q[j];
	}
    }

    scanf("%d",&n);
    for(k=0;k<n;k++){
	scanf("%s",strb);
	l=strlen(strb);

	flag=0;
	strb[0]=tran(strb[0]);
	if(strb[0]==stra[0]){
	    mi=0;
	    u=0;
	}else{
	    u=*link[0][strb[0]];
	    mi=u;
	    if(u==-1){
		flag=1;
	    }
	}

	if(flag==0){
	    for(i=1;i<l;i++){
		strb[i]=tran(strb[i]);

		u=*link[u][strb[i]];
		if(u==-1){
		    flag=1;
		    break;
		}
		ma=u;
	    }
	}

	if(flag==0){
	    printf("Matched %d %d\n",mi,ma);
	}else{
	    printf("Not matched\n");
	}

    }

    return 0;
}
