#include<stdio.h>
#include<stdlib.h>

struct point{
    double x;
    double y;
};
struct top{
    top *next;
    int idx;
    point pa,pb;
};
top pool[100005];
int pp;

double dot(point a,point b,point o){
    return (a.x-o.x)*(b.x-o.x)+(a.y-o.y)*(b.y-o.y);
}
double cross(point a,point b,point o){
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

int main(){
    int n;

    int i;
    int u,v;

    point a,b;
    top *pn,*cn,*nn;

    double ra,rb,rc,rd;
    int flag;

    while(scanf("%d",&n)!=EOF){
	if(n==0){
	    break;
	}

	pool[0].next=NULL;
	pp=1;

	for(i=0;i<n;i++){
	    scanf("%lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y);
	    cn=(&pool[0])->next;
	    pn=&pool[0];
	    while(cn!=NULL){
		ra=cross(a,cn->pa,cn->pb);
		rb=cross(b,cn->pa,cn->pb);
		rc=cross(a,cn->pa,b);
		rd=cross(a,cn->pb,b);

		flag=0;
		if(ra*rb<0 && rc*rd<0){
		    flag=1;
		}else{
		    if(ra==0){
			if(dot(cn->pa,cn->pb,a)<=0){
			    flag=1;
			}
		    }
		    if(rb==0){
			if(dot(cn->pa,cn->pb,b)<=0){
			    flag=1;
			}
		    }
		    if(rc==0){
			if(dot(a,b,cn->pa)<=0){
			    flag=1;
			}
		    }
		    if(rd==0){
			if(dot(a,b,cn->pb)<=0){
			    flag=1;
			}
		    }
		}

		if(flag==1){
		    pn->next=cn->next;     
		    cn=pn;
		}
		pn=cn;
		cn=cn->next;
	    }

	    nn=&pool[pp];
	    pp++;
	    
	    nn->next=NULL;
	    nn->idx=i;
	    nn->pa=a;
	    nn->pb=b;
	    pn->next=nn;
	}
	cn=(&pool[0])->next;
	printf("Top sticks: %d",cn->idx+1);
	cn=cn->next;
	while(cn!=NULL){
	    printf(", %d",cn->idx+1);
	    cn=cn->next;
	}
	printf(".\n");
    }

    return 0;
}
