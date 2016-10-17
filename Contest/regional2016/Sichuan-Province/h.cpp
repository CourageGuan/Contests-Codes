#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
vector<int> G[maxn],C[maxn];
int n;
LL fac[maxn*20];
LL d[maxn];

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

void dfs(int u,int p,int fa=-1)
{
	d[u] = 1;
	int cnt = 1;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i],c = C[u][i];
		if(v == fa) continue;
		dfs(v,c,u);
		d[u] = d[u]*d[v]%mod;
		d[u] = d[u]*fac[2*c]%mod;
		d[u] = d[u]*getC(cnt+c-1,cnt-1)%mod;
		cnt += c;
	}
	--cnt;
	d[u] = d[u]*getC(cnt+p-1,p-1)%mod;
}

int main()
{
	//freopen("input.txt","r",stdin);
	init();
	while(scanf("%d",&n) == 1)
	{
		for(int i=0;i<=n;++i) G[i].clear(),C[i].clear();
		for(int i=0;i<n-1;++i)
		{
			int u,v,c;
			scanf("%d %d %d",&u,&v,&c);
			G[u].push_back(v);
			G[v].push_back(u);
			C[u].push_back(c);
			C[v].push_back(c);
		}
		dfs(1,1);
		printf("%lld\n",d[1]);
	}
	return 0;
}
