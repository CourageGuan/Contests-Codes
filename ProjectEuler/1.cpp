#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL solve()
{
	LL res = 0;
	for(int i=3;i<1000;++i)
	{
		if(i%3 == 0 || i%5 == 0)
		{
			res += i;
		}
	}
	return res;
}

int main()
{
	printf("%lld\n",solve());
	return 0;
}
