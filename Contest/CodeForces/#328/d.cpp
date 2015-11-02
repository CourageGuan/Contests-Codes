#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2e6 + 10;

int vis[maxn];
vector<int> G[maxn],g[maxn];
int n,m,ans;

struct Node
{
	int d,p;
};

bool dfs(int u,int fa)
{
	bool flag = false;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v == fa) continue;
		if(dfs(v,u) || vis[v])
		{
			flag = true;
			g[u].push_back(v);
			g[v].push_back(u);
			++ans;
		}
	}
	return flag;
}

Node dfs1(int u,int fa)
{
	bool leaf = true;
	Node now = (Node){0,maxn};
	for(int i=0;i<g[u].size();++i)
	{
		int v = g[u][i];
		if(v == fa) continue;
		leaf = false;
		Node p = dfs1(v,u);
		if(p.d+1 > now.d || (p.d+1 == now.d && now.p > p.p)) now = (Node){p.d+1,p.p};
	}
	if(leaf) return (Node){0,u};
	return now;
}

void gao(int d)
{
	Node p = dfs1(d,-1);
//	printf("%d %d\n",p.d,p.p);
	Node t = dfs1(p.p,-1);
	printf("%d\n%d\n",min(t.p,p.p),2*ans - t.d);
}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;++i)
	{ int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(vis,0,sizeof vis);
	int d;
	for(int i=0;i<m;++i)
	{
		scanf("%d",&d);
		vis[d] = 1;
	}
	ans = 0;
	dfs(d,-1);
	/*
	for(int i=1;i<=n;++i)
	{
		printf("%d:",i);
		for(int j=0;j<g[i].size();++j) printf(" %d",g[i][j]);
		puts("");
	}
	*/
	gao(d);
	return 0;
}


