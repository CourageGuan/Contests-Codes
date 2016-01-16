#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;

LL pow_mod(LL a,int n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = (res*a) %mod;
		a = a*a %mod ;
		n>>=1;
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	LL n,m;
	scanf("%lld %lld",&n,&m);
	LL inv = pow_mod(2,mod-2);
//	printf("%lld\n",inv);
	LL ans = (n%mod)*(m%mod)%mod,dec = 0,l=1,r;
	m = min(n,m);
	while(l<=m)
	{
		r = min(m,n/(n/l));
		dec += ((n/l)%mod) * ((r+l)%mod)%mod *((r-l+1)%mod) %mod * inv %mod;
		dec %= mod;
		l = r+1;
	}
	ans += mod - dec;
	ans %= mod;
	printf("%lld\n",ans);
	return 0;
}
