#include<bits/stdc++.h>
using namespace std;

typedef long long LL;


LL solve()
{
	LL res=1;
	for(int i=1;i<=20;++i) res = res*(40-i+1)/i;
	return res;
}

int main()
{
	printf("%lld\n",solve());
	return 0;
}
