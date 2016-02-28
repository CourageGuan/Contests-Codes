#include<cstdio>

typedef long long LL;
LL mod = 100;

LL qpow(LL a,LL n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a % mod;
		a = a*a%mod;
		n>>=1;
	}
	return res;
}

int main()
{
	LL n;
	scanf("%lld",&n);
	printf("%lld\n",qpow(5,n));
	return 0;
}
