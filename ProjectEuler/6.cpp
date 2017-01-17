#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL solve()
{
	LL sum = 100/2*(1+100),ss = 100LL*(100+1)*(2*100+1)/6;
	return sum*sum - ss;
}

int main()
{
	printf("%lld\n",solve());
	return 0;
}
