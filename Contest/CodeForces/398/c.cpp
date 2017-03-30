#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=a;i<b;++i)

const int maxn = 2e6 + 10;
vector<int> G[maxn];
int n;
int s[maxn],t[maxn];
LL cur = 0;

void dfs(int u,int fa=-1)
{
	s[u] = t[u];
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u);
		s[u] += s[v];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);	
	F(i,1,n+1)
	{
		int f;
		scanf("%d %d",&f,t+i);
		G[f].push_back(i);
		cur += t[i];
	}
	if(cur%3)
	{
		puts("-1");
		return 0;
	}
	dfs(G[0][0]);
	vector<int> ans;
	F(i,1,n+1)
	{
//		printf("%d %d\n",i,s[i]);
		if(i == G[0][0]) continue;
		if(s[i] == cur/3)
		{
			ans.push_back(i);
		}
		if(ans.size() >= 2) break;
	}
	if(ans.size() != 2)
	{
		puts("-1");
	}
	else
	{
		printf("%d %d\n",ans[0],ans[1]);
	}
	return 0;
}
