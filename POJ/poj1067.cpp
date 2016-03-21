//威佐夫博奕
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;


int main()
{
	int a,b,k;
	while(scanf("%d %d",&a,&b)==2)
	{
		if(a>b) swap(a,b);
		k = ((a*2)/(1+sqrt(5)) + 0.5);
		if(floor(k*(1+sqrt(5))/2) == a)
		{
			puts(a+k == b?"0":"1");
			continue;
		}
		else ++k;
		if(floor(k*(1+sqrt(5))/2) == a) puts(a+k == b?"0":"1");
		else puts("1");
	}
	return 0;
}
