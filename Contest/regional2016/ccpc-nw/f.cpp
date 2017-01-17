#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e5 + 10;
const int LOG = 18;

int n,m,q[maxn],pos[maxn],L[maxn],R[maxn],tot;
int p[maxn][LOG],dep[maxn];
int la,lb,x;
vector<int> G[maxn],a,b;
int bit[maxn];

inline void add(int x,int v)
{
	for(;x>0;x -= x&-x) bit[x] += v;
}

inline int query(int x)
{
	int res = 0;
	for(;x<=n;x += x&-x) res += bit[x];
}

void dfs(int u,int fa=-1,int d = 1)
{
	q[++tot] = u;
	L[u] = tot;
	pos[u] = tot;

	p[u][0] = fa;
	dep[u] = d;

	F(i,1,LOG-1) 
		if(p[u][i-1] != -1)
			p[u][i] = p[p[u][i-1]][i-1];

	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u,d+1);
	}

	R[u] = tot;
}

inline int lca(int u,int v)
{
	if(dep[u] < dep[v]) swap(u,v);
	for(int i=LOG-1;i>=0;--i)
	{
		if(p[u][i] != -1 && dep[p[u][i]] >= dep[v])
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

inline int get(int u)
{
	int l = L[u]+1,r = R[u],lr = -1,rr = -1;

	while(l <= r)
	{
		int m = (l+r)>>1;
		if(query(m) - query(L[u]) >= 0)
		{
			r = m - 1;
			lr = q[m];
		}
		else l = m + 1;
	}


	l = L[u]+1,r = R[u];
	while(l <= r)
	{
		int m = (l+r)>>1;
		if(query(m) - query(L[u]) >= 0)
		{
			l = m + 1;
			rr = q[m];
		}
		else r = m - 1;
	}

//	printf("%d %d %d %d\n",lr,rr,lca(lr,rr),u);

	return lr != -1 && rr != -1 && lca(lr,rr) == u;
}

inline void init(int n)
{
	F(i,1,n) G[i].clear();
	memset(bit,0,sizeof bit);
	memset(p,-1,sizeof p);
	tot = 0;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		printf("Case #%d:\n",z);
		scanf("%d %d",&n,&m);
		init(n);
		F(i,1,n-1)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(!m) continue;
		dfs(1);
		assert(tot == n);
		scanf("%d",&lb);
		F(i,1,lb)
		{
			scanf("%d",&x);
			add(pos[x],1);
			b.push_back(x);
		}
		int res = n - lb;
		F(i,0,lb-1)
		{
			int u = b[i];
			res += get(u);
		}
		printf("%d\n",res);
		--m;
		while(m--)
		{
			F(i,0,lb-1)
			{
				int u = b[i];
				add(pos[u],-1);
			}
			a.clear();
			scanf("%d",&la);
			F(i,1,la)
			{
				scanf("%d",&x);
				add(pos[x],1);
				a.push_back(x);
			}
			res = n - la;
			F(i,0,la-1)
			{
				int u = a[i];
				res += get(u);
			}
			printf("%d\n",res);
			a.swap(b);
			swap(la,lb);
		}
	}
	return 0;
}
