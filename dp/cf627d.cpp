#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int d[maxn],up[maxn],sz[maxn],sum[maxn],n,k,li,res;
int a[maxn],b[maxn];

void dfs1(int u,int fa=-1)
{
	sz[u] = 1;
	sum[u] = a[u] >= li;
	F(i,0,G[u].size()-1)
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs1(v,u);

		sz[u] += sz[v];
		sum[u] += sum[v];
	}
}

void dfs2(int u,int fa=-1)
{
	int mx1,mx2;
	mx1 = mx2 = 0;
	d[u] = 0;
	F(i,0,G[u].size()-1)
	{
		int v = G[u][i];
		if(v == fa) continue;
		if(sz[u] - sz[v] == sum[u] - sum[v] && up[u]) up[v] = 1;
		dfs2(v,u);
		if(sz[v] == sum[v]) d[u] += sz[v];
		else
		{
			if(d[v] >= mx1) mx2 = mx1,mx1 = d[v];
			else if(d[v] > mx2) mx2 = d[v];
		}
	}
	if(a[u] < li)
	{
		d[u] = 0;
		return;
	}
	d[u] += mx1+1;
	res = max(res,d[u]+mx2+up[u]*(n-sz[u]));
}

bool yes(int m)
{
	li = m;
	res = 0;
	memset(up,0,sizeof up);
	dfs1(1);
	up[1] = a[1] >= li;
	dfs2(1);
	return res >= k;
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&k);
	F(i,1,n) scanf("%d",a+i),b[i] = a[i];
	F(i,1,n-1) 
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	sort(b+1,b+n+1,greater<int>());
	int L = k,R = n,res = b[n];
	while(L <= R)
	{
		int m = (L+R)>>1;
		if(yes(b[m]))
		{
			res = b[m];
			R = m - 1;
		}
		else L = m + 1;
	}
	printf("%d\n",res);
	return 0;
}
