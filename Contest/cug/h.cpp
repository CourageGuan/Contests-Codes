//ax+by=c
//gcd(a,b)=1 c便能表示所有整数...
#include<stdio.h>
#include<iostream>
using namespace std;

#define abs(a) (a>=0)?a:-a
/*
bool solve(int a,int b)
{
	a=abs(a);b=abs(b);
	if(a==0) return b==1;
	if(b==0) return a==1;
	if(a==1 || b==1) return true;
	if(a>b) swap(a,b);
	if( b%a==1 || b%a==a-1) return true;
	return solve(b-a,a);
}
*/

/*
bool solve(int a,int b)
{
	if(a==b) return false;
	if(a>b) swap(a,b);
	if(a==0) return b==1;
	if(b%a==1) return true;
	return  solve(b%a,a);
}
*/

int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}

int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)==2){
		a=abs(a);
		b=abs(b);
		if(gcd(a,b)==1) puts("Yes");
		else puts("No");
	}
	return 0;
}

