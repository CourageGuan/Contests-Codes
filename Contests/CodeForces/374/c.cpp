#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 5010;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
vector<int> G[maxn],E[maxn],ans;
LL d[maxn][maxn];
int n,m;
LL t;

LL dfs(int u,int s)
{
	if(s <= 0) return INF;
	LL &ans = d[u][s];
	if(ans != -1) return ans;
	ans = INF;
	for(int i=0;i<G[u].size();++i)
//	F(i,0,G[u].size()-1)
	{
		ans = min(ans,dfs(G[u][i],s-1) + E[u][i]);
	}
	return ans;
}

void getans(int u,int s)
{
	if(u == 1)
	{
		ans.push_back(1);
	   	return;
	}

	for(int i=0;i<G[u].size();++i)
	{
		if(s - 1 > 0 && d[G[u][i]][s-1] + E[u][i] == d[u][s])
		{
			getans(G[u][i],s-1);
			break;
		}
	}
	ans.push_back(u);
}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&t);	
	memset(d,-1,sizeof d);
	d[1][1] = 0;
	F(i,1,m)
	{
		int u,v,t;
		scanf("%d %d %d",&u,&v,&t);
		G[v].push_back(u);
		E[v].push_back(t);
	}
	for(int i=n;i>=2;--i) if(dfs(n,i) <= t)
	{
		getans(n,i);
		printf("%d\n",ans.size());
		for(auto it:ans ) printf("%d ",it);
		return 0;
	}
	return 0;
}
