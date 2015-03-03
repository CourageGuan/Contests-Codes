#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

#define max(a,b) ((a)>(b))?a:b
#define min(a,b) ((a)>(b))?b:a

void exgcd(long long a,long long b,long long &d,long long &x,long long &y)
{
	if(!b){d=a;x=1;y=0;}
	else{exgcd(b,a%b,d,y,x); y-=x*(a/b);}
}

int main()
{
	//freopen("test","r",stdin);
	long long a,b,c,d,x,x1,x2,y,y1,y2;
	scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&x1,&x2,&y1,&y2);
	c=-c;
	if(c<0) a=-a,b=-b,c=-c;
	if(a<0) {a=-a;swap(x1,x2);x1=-x1,x2=-x2;}
	if(b<0) {b=-b;swap(y1,y2);y1=-y1,y2=-y2;}
	if(a== 0 && b==0){
		if(c==0) printf("%lld\n",(x2-x1+1)*(y2-y1+1));
		else puts("0");
	}
	else if(a==0){
		if(c % b == 0 && c/b>=y1 && c/b<=y2) printf("%lld\n",x2-x1+1);
		else puts("0");
	}
	else if(b==0){
		if(c % a == 0 && c/a>=y1 && c/a<=y2) printf("%lld\n",y2-y1+1);
		else puts("0");
	}
	else{
		exgcd(a,b,d,x,y);
		if(c%d==0){
			x*=c/d;y*=c/d;
			a/=d;b/=d;
			double tx=x,ty=y,ta=a,tb=b,tx1=x1,tx2=x2,ty1=y1,ty2=y2;
			//cout<<x<<" "<<y<<endl;
			long long up=min(floor((tx2-tx)/tb),floor(ty-ty1)/ta);
			long long down=max(ceil((tx1-tx)/tb),ceil((ty-ty2)/ta));
			//cout<<up<<" "<<down<<endl;	
			if(down>up) puts("0");
			else printf("%lld\n",up-down+1);
		}
		else puts("0");
	}
	return 0;
}


