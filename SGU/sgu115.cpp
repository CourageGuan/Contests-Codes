/*还专门翻了下2001年的日历...*/
#include<cstdio>
#include<iostream>
using namespace std;

const int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int week[]={0,1,4,4,7,2,5,7,3,6,1,4,6};

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(m>12 || month[m]<n) puts("Impossible");
	n%=7;
	n-=1;
	printf("%d\n",(week[m]+n+7-1)%7+1);
	return 0;
}
