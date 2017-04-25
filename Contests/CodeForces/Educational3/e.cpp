#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;

int n,m;
struct Edge{
	int u,v,w,id;
	Edge(int u,int v,int w,int id):u(u),v(v),w(w),id(id) {}
	bool operator<(const Edge& rhs) const{
		return w < rhs.w;
	}
};

vector<int> G[maxn];
vector<Edge> edges;
int f[maxn],ans[maxn];

int find(int x)
{
	return f[x] ? f[x] = find(f[x]):x;
}

LL Kruskal()
{
	LL res = 0;
	sort(edges.begin(),edges.end());
	for(int i=0;i<edges.size();++i)
	{
		int u = find(edges[i].u),v = find(edges[i].v);
		if(u != v)
		{
			f[u] = v;
			res += edges[i].w;
			ans[edges[i].id] = 0;
			G[edges[i].u].push_back(i);
			G[edges[i].v].push_back(i);
			//printf("%d %d\n",edges[i].u,edges[i].v);
		}
	}
	return res;
}

const int LOG = 18;
int p[maxn][LOG],deep[maxn],mx[maxn][LOG];

void dfs(int u,int fa,int dep = 1)
{
	//printf("%d %d\n",u,fa);

	p[u][0] = fa;
	deep[u] = dep;

	for(int i=1;i<LOG;++i)
		if(p[u][i-1] != -1)
			p[u][i] = p[p[u][i-1]][i-1];

	for(int i=0;i<G[u].size();++i)
	{
		int v = edges[G[u][i]].v;
		if(v == u) v = edges[G[u][i]].u;
		if(fa == v) continue;
		mx[v][0] = edges[G[u][i]].w;
		dfs(v,u,dep+1);
	}
}

int query(int u,int v)
{
	if(deep[u] < deep[v] ) swap(u,v);
	int resu = mx[u][0],resv = mx[v][0];
	
	for(int i = LOG-1;i>=0;--i)
	{
		if(p[u][i] != -1 && deep[p[u][i]] >= deep[v])
		{
			resu = max(resu,mx[u][i]);
			u = p[u][i];
		}
	}

	if(u == v) return resu;
	
	for(int i = LOG-1;i>=0;--i)
	{
		if(p[u][i] != p[v][i])
		{
			resu = max(resu,mx[u][i]);
			u = p[u][i];
			resv = max(resv,mx[v][i]);
			v = p[v][i];
		}
	}
	resu = max(resu,mx[u][0]);
	resv = max(resv,mx[v][0]);
	return max(resu,resv);
}

void init()
{
	memset(f,0,sizeof f);
	memset(p,-1,sizeof p);
	memset(ans,-1,sizeof ans);
	memset(mx,0,sizeof mx);
}

int main()
{
	//freopen("test.txt","r",stdin);
	init();
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		edges.push_back(Edge(u,v,w,i));
	}
	LL res = Kruskal();
	dfs(1,-1);

	for(int i=1;i<LOG;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(p[j][i-1] != -1)
			{
				mx[j][i] = max(mx[j][i-1],mx[p[j][i-1]][i-1]);
			}
		}
	}

	for(int i=0;i<edges.size();++i) 
	{
		if(ans[edges[i].id])
		{
			int d = query(edges[i].u,edges[i].v);
		//	printf("%d %d \n",edges[i].id,d);
			ans[edges[i].id] = edges[i].w - d;
		}
	}

	for(int i=0;i<m;++i) printf("%lld\n",res + ans[i]);
	return 0;
}

