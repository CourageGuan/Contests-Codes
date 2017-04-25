#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;
vector<int> G[maxn];
int d1[maxn],d2[maxn],cat[maxn],ans;
int n,m;

void dfs(int fa,int u)
{
	if(cat[u]) d1[u] = d1[fa] + 1;

	d2[u] = max(d1[u],d2[fa]);

	if(G[u].size() == 1 && u!=1)
	{
		if(d2[u] <= m) ++ans;
	}

	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v!=fa)
		{
			dfs(u,v);
		}
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d",&n,&m)==2)
	{
		for(int i=1;i<=n;++i) scanf("%d",cat+i);
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		memset(d1,0,sizeof d1);
		memset(d2,0,sizeof d2);
		ans = 0;
		dfs(0,1);
		printf("%d\n",ans);
	}
	return 0;
}
