#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n = 600851475143;

LL solve()
{
	LL res ;
	int m = sqrt(n)+1;
	for(int i=3;i<m;i+=2)
	{
		if(n%i == 0)
		{
			res = i;
			while(n%i == 0) n/=i;
		}
		if(n == 1) break;
	}
	if(n != 1) res = n;
	return res;
}

int main()
{
	printf("%lld\n",solve());
	return 0;
}
