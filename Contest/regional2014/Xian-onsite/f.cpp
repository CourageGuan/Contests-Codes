#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod = 1e9 + 7;

LL pow_m(LL a,LL n)
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

LL C(LL n,LL m)
{
	if(n < m) return 0;
	if(m > n-m) m = n-m;
	LL s1 = 1,s2 = 1;
	for(LL i=0;i<m;++i)
	{
		s1 = s1*(n-i)%mod;
		s2 = s2*(i+1)%mod;
	}
	return s1*pow_m(s2,mod-2)%mod;
}

LL cal(LL n,LL m,LL k)
{
	return (k*pow_m(k-1,n-1)%mod);
}

int main()
{
	int T;
	scanf("%d",&T);
	LL n,m,k;
	for(int z=1;z<=T;++z)
	{
		scanf("%lld %lld %lld",&n,&m,&k);
		LL res = 0;
		LL c = 1;
		for(int i=0;i <= k;++i)
		{
			if(i) c = c*(k-i+1)%mod*pow_m(i,mod-2)%mod;
			LL cur = cal(n,m,i)*c;
	//		printf("%lld %lld\n",c,cur);
			if(!((k-i)&1)) res = (res + cur)%mod;
			else res = ((res - cur)%mod+mod)%mod;
		}
		res = res * C(m,k) %mod;
		printf("Case #%d: %lld\n",z,res);
	}
	return 0;
}
