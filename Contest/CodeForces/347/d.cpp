#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int n,m,vis[maxn];
vector<int> G[maxn],col[maxn];
vector<int> part[2];

bool dfs(int u,int c,int p)
{
	if(vis[u] != -1) return vis[u] ==  p;
	
	vis[u] = p;
	part[p].push_back(u);

	for(int i=0;i<G[u].size();++i)
	{
		if(!dfs(G[u][i],c,col[u][i] == c?p:p^1)) return 0;
	}

	return 1;
}

vector<int> solve(int c)
{
	vector<int> ans;
	memset(vis,-1,sizeof vis);

	for(int i=1;i<=n;++i)
	{
		if(vis[i] == -1)
		{
			part[0].clear();
			part[1].clear();

			if(!dfs(i,c,0))
			{
				for(int i=0;i<n+1;++i) ans.push_back(-1);
				return ans;
			}
			int f = 0;
			if(part[0].size() > part[1].size()) f = 1;
			ans.insert(ans.end(),part[f].begin(),part[f].end());
		}
	}
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i)
	{
		int a,b;
		char s[2];
		scanf("%d%d%s",&a,&b,s);
		G[a].push_back(b);
		col[a].push_back(s[0]=='B'?0:1);
		G[b].push_back(a);
		col[b].push_back(s[0]=='B'?0:1);
	}
	vector<int> a = solve(0),b = solve(1);
	if(a.size() > b.size()) a = b;
	if(a.size() > n) puts("-1");
	else
	{
		printf("%d\n",a.size());
		for(auto x: a) printf("%d ",x);
		puts("");
	}
	return 0;
}

