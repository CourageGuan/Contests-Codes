#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define fi first
#define se second

const int maxn = 1e5 + 10;
int n,vis[maxn],vising[maxn];
vector<int> fa[maxn];
vector<int> ans;
pair<int,int> p[maxn];

int dfs(int u,int f)
{
	if(u == 1) return 1;
	if(u == f) return 0;
	int v = p[fa[u][0]].fi;
	return dfs(v,f);
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	int t;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&p[i].fi,&p[i].se);
		if(p[i].se == 1)
			ans.push_back(i);
		fa[p[i].se].push_back(i);
		if(fa[p[i].se].size() == 2) t = p[i].se;
	}
	if(!ans.size())
	{
		int t1 = dfs(p[fa[t][0]].fi,t),t2 = dfs(p[fa[t][1]].fi,t);
		if(t1 && t2)
		{
			ans.push_back(fa[t][0]);
			ans.push_back(fa[t][1]);
		}
		else if(t1)
		{
			ans.push_back(fa[t][1]);
		}
		else if(t2)
		{
			ans.push_back(fa[t][0]);
		}
	}
	for(int i=0;i<ans.size();++i) printf("%d ",ans[i]); 
	puts("");
	return 0;
}
