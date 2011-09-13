#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char in[1010];
char out[1010];
char w[1010];
char a[1010];
char c[1010];
int il;
int ol;
int wl;
int al;
int cl;

int mul(int x){
	int i;
	int tmp;
	int t;
	
	t=0;
	for(i=0;i<al;i++){
		tmp=a[i]*x+t;
		c[i]=tmp%10;
		t=tmp/10;
	}
	cl=al;
	if(t>0){
		c[cl]=t;
		cl++;
	}

	return 0;
}
int sub(){
	int i;
	int t,tmp;
	
	t=0;
	for(i=0;i<cl;i++){
		tmp=w[i]-c[i]-t;
		if(tmp<0){
			w[i]=10+tmp;	
			t=1;
		}else{
			w[i]=tmp;
			t=0;
		}
	}
	for(i=cl;i<wl;i++){
		tmp=w[i]-t;
		if(tmp<0){
			w[i]=10+tmp;	
			t=1;
		}else{
			w[i]=tmp;
			t=0;
		}
	}
	for(i=wl-1;i>=0;i--){
		if(w[i]>0){
			wl=i+1;
			return 0;
		}
	}
	wl=0;

	return 0;	
}
int add(int x){
	int i;
	int t,tmp;

	t=x;
	for(i=0;i<al;i++){
		tmp=a[i]+t;
		a[i]=tmp%10;
		t=tmp/10;
	}
	if(t>0){
		a[al]=t;
		al++;
	}
	
	return 0;
}
int check(){
	int i;

	if(wl>cl){
		return 1;
	}else if(wl<cl){
		return 0;
	}else{
		for(i=wl-1;i>=0;i--){
			if(w[i]>c[i]){
				return 1;
			}else if(w[i]<c[i]){
				return 0;
			}
		}
		return 1;
	}

	return 0;
}

int sq(){
	int i,j,k;
	int u,v;
	int tmp;

	while(il>0){
		for(i=wl+1;i>=2;i--){
			w[i]=w[i-2];
		}
		w[1]=in[il-1];
		w[0]=in[il-2];
		il-=2;
		wl+=2;
		u=0;
		for(i=wl-1;i>=0;i--){
			if(w[i]>0){
				u=i+1;
				break;
			}
		}
		wl=u;

		for(i=al;i>=1;i--){
			a[i]=a[i-1];
		}
		al+=1;

		
		for(j=9;j>=0;j--){
			a[0]=j;
			if(j==0 && al==1){
				al=0;
			}
			mul(j);
			if(j==0){
				cl=0;
			}
			if(check()==1){
				sub();	
				add(j);
				out[ol]=j+'0';
				ol++;
				break;
			}
		}
	}

	return 0;
}

int main(){
	int t;
	int i,j,k;
	int u;
	char tmp;

	scanf("%d",&t);
	for(k=0;k<t;k++){
		scanf("%s",in);
		il=strlen(in);
		for(i=0;i<il;i++){
			in[i]-='0';
		}
		u=il/2;
		for(i=0;i<u;i++){
			tmp=in[i];
			in[i]=in[il-i-1];
			in[il-i-1]=tmp;
		}
		if(il%2==1){
			in[il]=0;
			il++;
		}
		wl=0;
		al=0;
		ol=0;
		sq();
		out[ol]=0;
		if(k>0){
			printf("\n");
		}
		printf("%s\n",out);
	}

	return 0;
}
