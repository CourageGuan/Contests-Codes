#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
vector<int> G[maxn];
int son[maxn],vis[maxn],mx[maxn];
int n;

int dfs(int u,int pa)
{
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v!=pa)
		{
			int d = dfs(v,u)+1;
			if(d>mx[u])
			{
				son[u] = v;
				mx[u] = d;
			}
		}
	}
	return mx[u];
}


int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
		}
		memset(mx,0,sizeof mx);
		memset(vis,0,sizeof vis);
		memset(son,-1,sizeof son);
		int ans = 0,inc = 0;
		ans = mx[1] = dfs(1,-1);
		for(int i=1; i!=-1 ; i=son[i]) vis[i] = 1;
		for(int i=2;i<=n;++i)
		{
			if(!vis[i]) inc = max(inc,mx[i]+1);
		}
		printf("%d\n",ans+inc);
	}
	return 0;
}

