#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define fi first
#define se second

const int maxn = 1e5 + 10; 
vector<pair<int,int>> G[maxn];
int score[maxn],vis[maxn];
int n,m,q,cnt = 0;

void dfs(int u,int s)
{
	score[u] = s;
	vis[u] = cnt;
	for(int i=0;i<G[u].size();++i)
	{
		auto v = G[u][i]; 
		if(!vis[v.first]) dfs(v.fi,s-v.se);
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<m;++i)
	{
		int u,v,s;
		scanf("%d %d %d",&u,&v,&s);
		G[u].push_back(make_pair(v,s));
		G[v].push_back(make_pair(u,-s));
	}
	cnt = 0;
	for(int i=1;i<=n;++i)
	{
		if(!vis[i]) ++cnt,dfs(i,0);
	}
	while(q--)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		if(vis[u] != vis[v]) puts("-1");
		else printf("%d\n",score[u] - score[v]);
	}
	return 0;
}
