#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 200010;
const LL INF = 1LL<<60;
const double eps = 60;

struct Edge
{
	int u,v;
	LL d;
} edge[2*maxn];

LL tmp[maxn],val[maxn];

vector<int> G[maxn];
int deep[maxn],sz[maxn],fa[maxn],son[maxn];
int top[maxn],id[maxn],tot;
int n,m;


void dfs1(int u)
{
	if(fa[u] != -1) deep[u] = deep[fa[u]] + 1;
	sz[u] = 1;
	son[u] = 0;
	for(int i=0;i<G[u].size();++i)
	{
		int v = edge[G[u][i]].v;
		if(v != fa[u])
		{
			tmp[v] = edge[G[u][i]].d;
			fa[v] = u;
			dfs1(v);
			sz[u] += sz[v];
			if(sz[v] > sz[son[u]])
				son[u] = v;
		}
	}
}

void dfs2(int u)
{
	id[u] = tot++;
	val[id[u]] = tmp[u];
	if(son[u])
	{
		top[son[u]] = top[u];
		dfs2(son[u]);
	}
	for(int i=0;i<G[u].size();++i)
	{
		int v = edge[G[u][i]].v;
		if(v != fa[u] && v != son[u])
		{
			top[v] = v;
			dfs2(v);
		}
	}
}


//--------------------------------------------------------------------------------

LL sum[maxn<<2];

void pushup(int u)
{
	 if(log2(1.0*sum[u<<1]) + log2(1.0*sum[u<<1|1]) >= eps) 
		 sum[u] = INF;
	 else
		 sum[u] = sum[u<<1]*sum[u<<1|1];
}

void build(int L,int R,int u)
{
	if(L == R)
	{
		sum[u] = val[L]; 
	}
	else
	{
		int m = (L+R)>>1;
		build(L,m,u<<1);
		build(m+1,R,u<<1|1);
		pushup(u);
	}
	//printf("...%d %d %d\n",L,R,sum[u]);
}

void modify(int p,LL v,int L,int R,int u)
{
	if(L == R)
	{
		val[L] = sum[u] = v;
	}
	else
	{
		int m = (L+R)>>1;
		if(p>m) 
			modify(p,v,m+1,R,u<<1|1);
		else
			modify(p,v,L,m,u<<1);
		pushup(u);
	}
}

LL query(int cL,int cR,int L,int R,int u)
{
	if(cL <= L && R <= cR)
	{
		return sum[u];
	}
	else
	{
		int m = (L+R)>>1;
		if(cR <= m)
			return query(cL,cR,L,m,u<<1);
		else if(cL > m)
			return query(cL,cR,m+1,R,u<<1|1);
		else
		{
			LL a = query(cL,cR,L,m,u<<1),b = query(cL,cR,m+1,R,u<<1|1);
			if(log2(1.0*a) + log2(1.0*b) >= eps)
				return INF;
			else 
				return a*b;
		}
	}
}

LL get(int u,int v)
{
	LL res = 1,qry;
	while(top[u] != top[v])
	{
		if(deep[top[u]] < deep[top[v]]) swap(u,v);
		qry = query(id[top[u]],id[u],1,n,1);
		if(log2(1.0*res) + log2(1.0*qry) >= eps)
			res = INF;
		else 
			res *= qry;
		u = fa[top[u]];
	}
	if(u == v) return res;
	if(deep[u] > deep[v]) swap(u,v);
	qry = query(id[u]+1,id[v],1,n,1);
	if(log2(1.0*res) + log2(1.0*qry) >= eps)
		res = INF;
	else 
		res *= qry;
	return res;
}

void init()
{
	memset(fa,-1,sizeof fa);
	memset(sz,0,sizeof sz);
	tmp[1] = 1; deep[1] = 1; top[1] = 1; tot = 1;
	dfs1(1);
	dfs2(1);
	build(1,n,1);
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	int cnt = 0;
	for(int i=1;i<n;++i)
	{
		int u,v;
		LL x;
		scanf("%d %d %lld",&u,&v,&x);
		G[u].push_back(cnt);
		edge[cnt++] = (Edge){u,v,x};
		G[v].push_back(cnt);
		edge[cnt++] = (Edge){v,u,x};
	}
	init();
//	for(int i=1;i<=n;++i) printf("%d %d\n",i,id[i]);
	while(m--)
	{
		int op,a,b;
		LL x;
		scanf("%d",&op);
		if(op == 1)
		{
			scanf("%d %d %lld",&a,&b,&x);
			LL cur = get(a,b);
			printf("%lld\n",x/cur);
		}
		else
		{
			scanf("%d %lld",&a,&x);
			int p = 2*(a-1);
			if(fa[edge[p].u] == edge[p].v) p = edge[p].u;
			else p = edge[p].v;
			modify(id[p],x,1,n,1);
		}
	}
	return 0;
}
