#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n,m;
bool vis[maxn];
vector<int> G[maxn];
int match[maxn];

bool dfs(int u)
{
    for(int i = 0; i < G[u].size();++i)
    {
        int v = G[u][i];
        if(!vis[v])
        {
            vis[v] = 1;
            int t = match[v]; match[v] = u;
            if(t == -1 || dfs(t)) return true;
            match[v] = t;
        }
    }
    return false;
}

int solve()
{
    int ans = 0;
    memset(match,-1,sizeof(match));
    for(int i = 1;i <= n;++i)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }
    return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans = solve();
	printf("%d\n",ans/2);
	return 0;
}
