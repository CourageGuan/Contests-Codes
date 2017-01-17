#include<bits/stdc++.h>
using namespace std;

int solve()
{
	for(int a=1;a<1000;++a)
		for(int b=a+1;b<1000;++b)
		{
			int c = 1000 - a - b;
			if(c <= b) continue;
			if(a*a + b*b == c*c)
			{
		//		printf("%d %d %d\n",a,b,c);
				return a*b*c;
			}
		}
	return -1;
}

int main()
{
	printf("%lld\n",solve());
	return 0;
}
