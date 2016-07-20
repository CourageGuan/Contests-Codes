#include<bits/stdc++.h>
using namespace std;
typedef long long  LL;

const int maxn = 3e5 + 10;
int n,q;
int sz[maxn],fa[maxn],ans[maxn];
vector<int> G[maxn];

void dfs(int u)
{
	sz[u] = 1;
	ans[u] =  u;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		dfs(v);
		sz[u] += sz[v];
	}
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(2*sz[v] >= sz[u]) ans[u] = ans[v];
	}
	while(2*(sz[u] - sz[ans[u]]) > sz[u]) ans[u] = fa[ans[u]];
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&q);
	for(int i=2;i<=n;++i)
	{
		scanf("%d",fa+i);
		G[fa[i]].push_back(i);
	}
	dfs(1);
	for(int i=0;i<q;++i)
	{
		int v; scanf("%d",&v);
		printf("%d\n",ans[v]);
	}
	return 0;
}
