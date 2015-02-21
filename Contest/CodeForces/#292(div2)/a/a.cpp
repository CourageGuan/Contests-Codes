#include<cstdio>
#include<iostream>
using namespace std;

#define abs(a) (a<0)?-a:a;

int main()
{
	int a,b,s;
	scanf("%d %d %d",&a,&b,&s);
	a=abs(a);b=abs(b);
	puts((a+b>s || (s-a-b) & 1)?"No":"Yes");
	return 0;
}
