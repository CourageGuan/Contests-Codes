#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 4e5 + 10;
int n;
vector<int> G[maxn];
int yes[maxn],sz[maxn],mx[maxn];

void dfs(int u,int fa = -1) 
{
	mx[u] = 0;
	sz[u] = 1;
	++yes[u];
	R(i,G[u].size())
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u);
		sz[u] += sz[v];
		mx[u] = max(mx[u],mx[v]);
		if(sz[v] - mx[v] > n/2) --yes[u];
	}
	if(sz[u] <= n/2) mx[u] = sz[u];
}

void dfs1(int u,int s,int fa = -1)
{
	vector<int> st;
	st.push_back(0);
	R(i,G[u].size())
	{
		int v = G[u][i];
		if(v == fa) continue;
		st.push_back(v);
	}
	vector<int> pre(st.size()+2),suf(st.size()+2);
	F(i,1,st.size()-1) pre[i] = max(pre[i-1],mx[st[i]]);
	for(int i=st.size()-1;i>0;--i) suf[i] = max(suf[i+1],mx[st[i]]);
	F(i,1,st.size()-1) if(n - sz[st[i]] <= n/2 || n - sz[st[i]] - max(max(pre[i-1],suf[i+1]),s) <= n/2) ++yes[st[i]];
	F(i,1,st.size()-1)
	{
		int t = s;
		t = max(t,max(pre[i-1],suf[i+1]));
		if(n - sz[st[i]] <= n/2) t = n-sz[st[i]];
		dfs1(st[i],t,u);
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	R(i,n-1)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	yes[1] = 1;
	dfs(1);
	dfs1(1,0);
	F(i,1,n) putchar(yes[i]>1?'1':'0'),putchar(' ');
	return 0;
}
