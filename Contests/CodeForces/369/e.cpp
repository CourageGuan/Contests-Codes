#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define gcd __gcd

const int mod = 1e6 + 3;
LL n,k;

LL pow_m(LL a,LL n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a %mod;
		a = a*a %mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%lld %lld",&n,&k);
	if(n <= 62 && k > (1LL<<n))
	{
		puts("1 1");
		return 0;
	}
	LL t = k-1,cnt = 0,p2 = pow_m(2,n),cur = 1,m;
	while(t) cnt += t>>1,t >>= 1;
	F(i,1,k-1)
	{
		cur = cur*(p2 - i + mod)%mod;
		if(cur == 0) break;
	}
	LL inv = pow_m(pow_m(2,cnt),mod-2);
	cur = cur*inv%mod;
	m = pow_m(p2,k-1)*inv%mod;
	cur = (m - cur + mod)%mod;
	printf("%lld %lld\n",cur,m);
	return 0;
}
