#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 4e6;

LL solve()
{
	LL res = 0;
	int t,a=1,b=2;
	for(;;)
	{
		t = b;
		b = a+b;
		a = t;
		if(!(a&1)) res += a;
		if(a > maxn) break;
	}
	return res;
}

int main()
{
	printf("%lld\n",solve());
	return 0;
}
