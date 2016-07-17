#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
double res[maxn];
int sum[maxn];
int n;

void dfs(int u)
{
	sum[u] = 1;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		dfs(v);
		sum[u] += sum[v];
	}
}

void dp(int u)
{
	int sz = G[u].size();

	if(sz == 1)
	{
		int v = G[u][0];
		res[v] = res[u] + 1;
		dp(v);
		return;
	}

	double s = 0;
	for(int i=0;i<sz;++i)
	{
		s += sum[G[u][i]];
	}

	for(int i=0;i<sz;++i)
	{
		int v = G[u][i];
		res[v] = (s-sum[v])/2 + res[u] + 1;
		dp(v);
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n;
	for(int i=2;i<=n;++i) 
	{
		int t;
		cin >> t;
		G[t].push_back(i);
	}
	dfs(1);
	res[1] = 1;
	dp(1);
	for(int i=1;i<=n;++i)
		printf("%.7lf ",res[i]);
	return 0;
}

