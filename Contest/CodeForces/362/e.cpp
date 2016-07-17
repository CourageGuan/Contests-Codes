#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

LL pow_mod(LL a,LL n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return res;
}


int main()
{
	int k,odd=-1;
	cin >> k;
	LL t = 2;
	for(int i=0;i<k;++i)
	{
		LL a;
		cin >> a;
		if(!(a&1)) odd = 1;
		t = pow_mod(t,a);
	}
	t = t*pow_mod(2,mod-2)%mod;
	printf("%lld/%lld\n",(t+odd)*pow_mod(3,mod-2)%mod,t);
	return 0;
}
