#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
vector<int> G[maxn];
vector<int> lst;
int dep[maxn],n;

void dfs(int u,int fa)
{
	dep[u] = dep[fa] + 1;
	if(G[u].size() == 1) lst.push_back(dep[u]);
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v != fa) dfs(v,u);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans = 0;
	dep[1] = 0;
	for(int i=0;i<G[1].size();++i)
	{
		int v = G[1][i];
		lst.clear();
		dfs(v,1);
		sort(lst.begin(),lst.end());
		int cur = 0;
		for(int i=0;i<lst.size();++i)
			if(cur >= lst[i]) ++cur;
			else cur = lst[i];
		ans = max(ans,cur);
	}
	printf("%d\n",ans);
	return 0;
}
