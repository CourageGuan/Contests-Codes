#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int n,x,y,cnt;
vector<int> G[maxn];

int dfs(int u,int fa)
{
	int lft = 2;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v == fa) continue;
		int t = dfs(v,u);
		if(lft && t)
		{
			++cnt;
			--lft;
		}
	}
	return lft;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&x,&y);
	
	for(int i=0;i<n-1;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	if(x == y || n == 2)
	{
		printf("%lld\n",(LL)x*(n-1));
		return 0;
	}

	if(x < y)
	{
		cnt = 0;
		dfs(1,1);
		printf("%lld\n",(LL)cnt*x + (LL)(n-1-cnt)*y);
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			if(G[i].size() == n-1)
			{
				printf("%lld\n",(LL)y*(n-2)+x);
				return 0;
			}
		}
		printf("%lld\n",(LL)y*(n-1));
	}
	return 0;
}



