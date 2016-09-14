#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 20101009;
const int maxn = 1e7 + 7;
bool vis[maxn];
int p[maxn],tot,n,m;
LL g[maxn];

void init()
{
	tot = 0;
	g[1] = 1;
	for(int i=2;i<maxn;++i)
	{
		if(!vis[i])
		{
			p[tot++] = i;
			g[i] = 1LL*i*(1-i);
		}
		for(int j=0;j<tot;++j)
		{
			int t = i*p[j];
			if(t >= maxn) break;
			vis[t] = 1;
			if(i%p[j]) g[t] = g[i]*p[j]*(1-p[j]);
			else
			{
				g[t] = g[i]*p[j];
				break;
			}
		}
	}
	g[0] = 0;
	for(int i=1;i<maxn;++i) g[i] = ((g[i]+g[i-1])%mod+mod)%mod;
}

LL pow_m(LL a,int n)
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

LL cal(int n,int m)
{
	int N = min(n,m),l = 1,r;
	LL res = 0;
	while(l <= N)
	{
		r = min(min(m/(m/l),n/(n/l)),N);
		res += (g[r] - g[l-1]+mod)%mod*(m/l)%mod*(n/l)%mod*(m/l+1)%mod*(n/l+1)%mod;
		res %= mod;
		l = r+1;
	}
	return res*pow_m(4,mod-2)%mod;
}

int main()
{
	//freopen("test.txt","r",stdin);
	init();
	while(scanf("%d %d",&n,&m) == 2)
	{
		printf("%lld\n",cal(n,m));
	}
	return 0;
}
