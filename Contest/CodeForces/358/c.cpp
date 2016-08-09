#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int n;
vector<int> G[maxn],E[maxn];
int a[maxn],son[maxn],ans;

void dfs1(int u)
{
	son[u] = 1;
	R(i,G[u].size())
	{
		int v = G[u][i];
		dfs1(v);
		son[u] += son[v];
	}
}

void dfs(int u,LL mx)
{
	R(i,G[u].size())
	{
		int v = G[u][i];
		if(max(1LL*E[u][i],mx+E[u][i]) > a[v])
		{
			ans += son[v];
			continue;
		}
		dfs(v,max(1LL*E[u][i],mx+E[u][i]));
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n;
	F(i,1,n) scanf("%d",a+i);
	F(i,2,n)
	{
		int u,c;
		scanf("%d %d",&u,&c);
		G[u].push_back(i);
		E[u].push_back(c);
	}
	dfs1(1);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
