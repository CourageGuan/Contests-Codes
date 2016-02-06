#include<bits/stdc++.h>
using namespace std;

const int maxn = 40010;
const int maxm = 1e5 + 10;
const int maxd = 18;
int n,m,B,tot,cur;
int a[maxn],b[maxn],l[maxn],r[maxn],idx[maxn << 1];
vector<int> G[maxn];
int p[maxn][maxd],dep[maxn];
int vis[maxn],cnt[maxn],ans[maxm];

struct Res{
	int l,r,rt;
	int id;
	bool operator<(const Res& rhs) const
	{
		if(l/B == rhs.l/B) return r < rhs.r;
		else return l < rhs.l;
	}
} q[maxm];

void dfs(int u,int fa)
{
	l[u] = ++tot; idx[tot] = u;
	p[u][0] = fa;
	dep[u] = dep[fa] + 1;

	for(int i=1;i<maxd;++i) p[u][i] = p[p[u][i-1]][i-1];

	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v != fa) dfs(v,u);
	}
	r[u] = ++tot; idx[tot] = u;
}


int lca(int u,int v)
{
	if(dep[u] < dep[v]) swap(u,v);
	for(int i=maxd-1;i>=0;--i)
		if(dep[p[u][i]] >= dep[v]) u = p[u][i];
	if(u == v) return u;
	for(int i=maxd-1;i>=0;--i)
		if(p[u][i] != p[v][i])
		{
			u = p[u][i];
			v = p[v][i];
		}
	return p[u][0];
}

int update(int x)
{
	if(vis[x])
	{
		if(--cnt[a[x-1]] == 0) --cur;
	}
	else if(cnt[a[x-1]]++ == 0) ++cur;

	vis[x] ^= 1;
}

void solve()
{
	//for(int i=0;i<tot;++i) printf("%d ",idx[i]);
	//puts("");
	//for(int i=0;i<m;++i) printf("%d %d\n",q[i].l,q[i].r);
	//puts("");
	int L = q[0].l,R = q[0].l-1;
	cur = 0;
	for(int i=0;i<m;++i)
	{
		while(L < q[i].l) update(idx[L++]);
		while(L > q[i].l) update(idx[--L]);
		while(R < q[i].r) update(idx[++R]);
		while(R > q[i].r) update(idx[R--]);
		int u = idx[L],v = idx[R];
		if(q[i].rt != u && q[i].rt != v) update(q[i].rt);
		ans[q[i].id] = cur;
		if(q[i].rt != u && q[i].rt != v) update(q[i].rt);
	}
	for(int i=0;i<m;++i) printf("%d\n",ans[i]);
}


void init()
{
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	memset(p,0,sizeof p);
	for(int i=1;i<maxn;++i) G[i].clear();
	tot = 0;
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d",&n,&m) == 2)
	{
		init();
		for(int i=0;i<n;++i) scanf("%d",a+i),b[i] = a[i];
		sort(b,b+n);
		int pn = unique(b,b+n) - b;
		for(int i=0;i<n;++i) a[i] = lower_bound(b,b+pn,a[i]) - b + 1;
		for(int i=0;i<n-1;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,1);
		B = sqrt(tot) + 1;
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			q[i].id = i;
			if(l[u] > l[v]) swap(u,v);
			q[i].rt = lca(u,v);
			if(q[i].rt == u) q[i].l = l[u],q[i].r = l[v];
			else q[i].l = r[u],q[i].r = l[v];
		}
		sort(q,q+m);
		solve();
	}
	return 0;
}
