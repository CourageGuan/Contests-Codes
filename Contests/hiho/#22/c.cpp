#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
const int LOG = 20;
const int mod = 1e9 + 7;
vector<int> G[maxn];

int n,m;
int V[maxn];

int p[maxn][LOG]; //init -1
int deep[maxn];
int tot = 0;

int in[maxn],out[maxn];

void dfs(int u,int fa,int dep = 1)
{
	in[u] = ++tot;

	p[u][0] = fa;
	deep[u] = dep;

	for(int i=1;i<LOG;++i)
		if(p[u][i-1] != -1)
			p[u][i] = p[p[u][i-1]][i-1];

	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u,dep+1);
	}
	out[u] = tot;
}

int lca(int u,int v)
{
	if(deep[u] < deep[v]) swap(u,v);
	for(int i=LOG-1;i>=0;--i)
	{
		if(p[u][i]!=-1 && deep[p[u][i]] >= deep[v])
		{
			u = p[u][i];
		}
	}
	if(u == v) return u;
	for(int i=LOG-1;i>=0;--i)
	{
		if(p[u][i] != p[v][i])
		{
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}

int d[maxn*2];

void update(int x,int val)
{
	for(int i=x;i<=tot;i+=i&-i)
		d[i] = 1LL*d[i]*val%mod;
}

int query(int x)
{
	int res = 1;
	for(int i=x; i; i -= i&-i)
		res = 1LL*res*d[i]%mod;
	return res;
}

int pow_m(int a,int n)
{
	int res = 1;
	while(n)
	{
		if(n&1) res = 1LL*res*a%mod;
		a = 1LL*a*a%mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",V+i);
	for(int i=0;i<n-1;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(p,-1,sizeof p);
	tot = 0;
	dfs(1,0);
	for(int i=1;i<=tot;++i) d[i] = 1;
	for(int i=1;i<=n;++i)
	{
		update(in[i],V[i]);
//		printf("%d\n",query(in[i]));
		update(out[i]+1,pow_m(V[i],mod-2));
	}
	scanf("%d",&m);
	while(m--)
	{
		int op,u,v;
		scanf("%d%d%d",&op,&u,&v);
		if(op)
		{ 
			int z = 1LL*v*pow_m(V[u],mod-2)%mod;
			update(in[u],z);
			update(out[u]+1,pow_m(z,mod-2));
			V[u] = 1LL*V[u]*z%mod;
		}
		else
		{
			int r = lca(u,v);
			printf("%d\n",1LL*pow_m(query(in[r]),mod-2)*pow_m(query(in[p[r][0]]),mod-2)%mod*query(in[u])%mod*query(in[v])%mod);
		}
	}
	return 0;
}
