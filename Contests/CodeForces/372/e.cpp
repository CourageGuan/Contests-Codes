#include<bits/stdc++.h>

typedef double DB;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define mp std::make_pair
#define fi first
#define se second

const int maxn = 1e5 + 10;
int n,m;
std::vector<std::pair<int,int> > G[maxn];
std::vector<int> dd;
std::map<int,LL> vis;
int root,size;
int sz[maxn],f[maxn],done[maxn];
LL d1[maxn],d2[maxn],p[maxn],invp[maxn],cnt,ans;


void exgcd(LL a,LL b,LL& d,LL &x,LL &y)
{
	if(!b)  d = a,x = 1,y = 0;
	else  { exgcd(b,a%b,d,y,x); y -= (a/b)*x; }
}

LL inv(LL a)
{
	LL d,x,y;
	exgcd(a,m,d,x,y);
	return d==1 ? (x+m) % m : -1;
}

void getroot(int u,int fa=0)
{
	sz[u] = 1,f[u] = 0;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i].fi;
		if(v == fa || done[v]) continue;
		getroot(v,u);
		sz[u] += sz[v];
		f[u] = std::max(f[u],sz[v]);
	}
	f[u] = std::max(f[u],size - sz[u]);
	if(f[u] < f[root]) root = u;
}

void dfs1(int u,int dep,int fa=0)
{
	LL t = (m-d1[u])%m;
	t = t*invp[dep]%m;
	vis[t]++;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i].fi;
		if(v == fa || done[v]) continue;
		d1[v] = (d1[u]*10  + G[u][i].se)%m;
		dfs1(v,dep+1,u);
	}
}

void dfs2(int u,int dep,int fa=0)
{
	cnt += vis[d2[u]];
	LL t = (m - d1[u])%m;
	t = t*invp[dep]%m;
	if(d2[u] == t) --cnt;

	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i].fi;
		if(v == fa || done[v]) continue;
		d2[v] = (d2[u] + G[u][i].se*p[dep]%m)%m;
		dfs2(v,dep+1,u);
	}
}

LL cal(int u,int init)
{
	cnt = 0;
	vis.clear();
	init%=m;
	d1[u] = d2[u] = init;
	dfs1(u,init==0?0:1);
	dfs2(u,init==0?0:1);
	return cnt;
}

void gao(int u)
{
	ans += cal(u,0);
	done[u] = 1;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i].fi; 
		if(done[v]) continue;
		ans -= cal(v,G[u][i].se);
		f[0] = size = sz[v];
		root = 0;
		getroot(v);
		gao(root);
	}
}

void init()
{
	p[0] = 1%m;
	F(i,1,maxn-1) p[i] = (p[i-1]*10)%m;
	int x,y;
	invp[1] = inv(10);
	F(i,2,maxn-1) invp[i] = (invp[i-1]*invp[1])%m;
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&m);
	init();
	F(i,1,n-1)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		++u,++v;
		G[u].push_back(mp(v,w));
		G[v].push_back(mp(u,w));
	}
	f[0] = size = n;
	root = 0;
	getroot(1);
	ans = 0;
	gao(root);
	printf("%lld\n",ans);
	return 0;
}
