#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
vector<int> res[3];
int vis[maxn];

int n,m;

bool dfs(int u,int t)
{
	if(G[u].size() == 0) return true;
	if(vis[u] == 3-t) return 0;
	if(vis[u]) return 1;
	vis[u] = t;

//	printf("!%d %d\n",u,t);

	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(!dfs(v,3-t)) return 0;
	}
	return 1;
}


int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> m;
	for(int i=0;i<m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			if(!dfs(i,1))
			{
				puts("-1");
				return 0;
			}
		}
	}
	for(int i=1;i<=n;++i) res[vis[i]].push_back(i);
	for(int i=1;i<=2;++i)
	{
		printf("%d\n",(int)res[i].size());
		for(auto x:res[i]) printf("%d ",x);
		puts("");
	}
	return 0;
}

