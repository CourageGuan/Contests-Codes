/*还专门翻了下2001年的日历...*/
#include<cstdio>
#include<iostream>
using namespace std;

const int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//const int week[]={0,1,4,4,7,2,5,7,3,6,1,4,6};		//作弊大法好

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(m>12 || month[m]<n){
		puts("Impossible");
		return 0;
	}
	int w,c,y,d;
	c=20;
	y=(m<=2)?0:1;
	m=(m<=2)?m+12:m;
	d=n;
	w=((int)((double)c/4)-2*c+y+(int)((double)y/4)+(int)((double)(m+1)*13.0/5)+d-1) % 7;
	printf("%d\n",(w<=0)?w+7:w);
	return 0;
}
