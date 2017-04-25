#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
const int maxd = 18;
int n,m;
int cnt[maxn],dep[maxn],p[maxn][maxd];
LL len[maxn],lenup[maxn];
vector<int> G[maxn];

void dfs(int u,int fa)
{
	p[u][0] = fa;
	dep[u] = dep[fa] + 1;
	len[u] = 0;
	cnt[u] = 1;
	for(int i=1;i<maxd;++i) p[u][i] = p[p[u][i-1]][i-1];

	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v != fa)
		{
			dfs(v,u);
			cnt[u] += cnt[v];
			len[u] +=  len[v] + cnt[v];
		}
	}
}


void dfs2(int u,int fa)
{
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v == fa) continue;
		lenup[v] = lenup[u] + (n - cnt[v]) - cnt[v];
		dfs2(v,u);
	}
}

int lca(int u,int v)
{
	int len = 0;
	if(dep[u] < dep[v]) swap(u,v);
	for(int i=maxd-1;i>=0;--i)
		if(dep[p[u][i]] >= dep[v])
		{
			len += 1<<i;
			u = p[u][i];
		}
	if(u == v) return -len;
	for(int i=maxd-1;i>=0;--i)
	{
		if(p[u][i] != p[v][i])
		{
			u = p[u][i];
			v = p[v][i];
			len += 2*(1<<i);
		}
	}
	len += 2;
	return len;
}

double solve(int u,int v)
{
	int t  = lca(u,v);
	//printf("%d\n",t);
	if(t > 0)
	{
		LL num = (LL)cnt[u]*cnt[v];
		return ((LL)cnt[u]*len[v] + (LL)cnt[v]*len[u] + num*(t+1))/(double)num;
	}
	else
	{
		t = -t;
		if(dep[u] > dep[v]) swap(u,v);
		int pv = v;
		for(int i=maxd-1;i>=0;--i)
			if(dep[p[pv][i]] > dep[u])
			{
				pv = p[pv][i];
			}
		LL lenu  = lenup[u] - len[pv] - cnt[pv];
		int cntu = cnt[1] - cnt[pv];
		LL num = (LL)cntu*cnt[v];
		//printf("%d %d\n",lenu,cntu);
		return ((LL)cntu*len[v] + (LL)cnt[v]*lenu + num*(t+1))/(double)num;
	}
}



int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	lenup[1] = len[1];
	dfs2(1,0);
	for(int i=0;i<m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%.12lf\n",solve(u,v));
	}
	return 0;
}

