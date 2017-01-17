#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e5 + 10;
int sz[maxn],mark[maxn],n,k;
vector<int> G[maxn];
LL ans;

void dfs(int u,int fa = -1)
{
	sz[u] = mark[u];
	F(i,0,G[u].size()-1)
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u);
		sz[u] += sz[v];
	}
}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&k);
	k *= 2;
	F(i,1,k)
	{
		int u;
		scanf("%d",&u);
		mark[u] = 1;
	}
	F(i,1,n-1)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);

	ans = 0;
	F(v,2,n)
	{
		ans += min(sz[v],k-sz[v]);
//		printf("%d %d %d\n",v,sz[v],k-sz[v]);
	}

	printf("%lld\n",ans);
	return 0;
}
