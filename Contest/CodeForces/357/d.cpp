#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
int a[maxn],vis[maxn],dep[maxn],fa[maxn];
vector<int> G[maxn];
vector<pair<int,int> > ans;

int n,m;

bool dfs(int u,int fa = 0)
{
	if(u) dep[u] = dep[fa] + 1;
	if(fa && a[u] != u && a[u] != a[fa])
	{
	//	printf("%d %d %d ",u,a[u],a[fa]);
		return 0;
	}
	R(i,G[u].size())
	{
		int v = G[u][i];
		if(v == fa) continue;
		if(!dfs(v,u)) return 0;
	}
	return 1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	fill(fa,-1);
	R(i,m)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		fa[v] = u;
		G[u].push_back(v);
	}
	F(i,1,n)
	{
		if(fa[i] == -1)
		{
			G[0].push_back(i);
			fa[i] = 0;
		}
		scanf("%d",a+i);
	}
	if(!dfs(0))
	{
		puts("-1");
		return 0;
	}

	F(i,1,n)
	{
		if(!vis[a[i]])
		{
			vis[a[i]] = 1;
			ans.push_back(make_pair(dep[a[i]],a[i]));
		}
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	R(i,ans.size()) printf("%d\n",ans[i].second);
	return 0;
}
