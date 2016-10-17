#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
vector<int> G[maxn];
int n;
LL fac[maxn*20],deg[maxn];

LL pow_m(LL a,LL n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a %mod;
		a = a*a%mod;
		n >>= 1;
	}
	return res;
}

LL getC(LL n,LL m)
{
	if(n < m) return 0;
	if(m > n-m) m = n - m;
	return fac[n]*pow_m(fac[n-m]*fac[m]%mod,mod-2)%mod;
}

void init()
{
	fac[0] = 1;
	for(int i=1;i<maxn*20;++i) fac[i] = fac[i-1]*i%mod;
}

int main()
{
//	freopen("input.txt","r",stdin);
	init();
	while(scanf("%d",&n) == 1)
	{
		memset(deg,0,sizeof deg);
		LL ans = 1;
		for(int i=0;i<n-1;++i)
		{
			int u,v,c;
			scanf("%d %d %d",&u,&v,&c);
			deg[u] += c;
			deg[v] += c;
			ans = ans*getC(2*c,c)%mod;
			ans = ans*c%mod;
		}
		ans = ans*fac[deg[1]]%mod;
		for(int i=2;i<=n;++i) ans = ans*fac[deg[i]-1]%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
