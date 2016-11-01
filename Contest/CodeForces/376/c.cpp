#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e5 + 10;
int n,m,k,tot,mx,ans;
int vis[maxn],c[maxn],l[maxn],r[maxn];
vector<int> G[maxn];
set<pair<int,int> > st;
map<int,int> cnt;

void dfs(int u)
{
	++tot;
	vis[u] = 1;
	cnt[c[u]]++;
	mx = max(cnt[c[u]],mx);

	for(int i=0;i<G[u].size();++i)
	{
		int v =G[u][i];
		if(vis[v]) continue;
		dfs(v);
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&k);
	F(i,1,n) scanf("%d",c+i);
	F(i,1,m)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		if(u > v) swap(u,v);
		if(st.find(make_pair(u,v)) != st.end()) continue;
		st.insert(make_pair(u,v));

		G[u].push_back(v);
		G[v].push_back(u);
	}
	ans = 0;
	F(i,1,n)
		if(!vis[i] && G[i].size())
		{
			cnt.clear();
			tot = 0;
			mx = 0;
			dfs(i);
			ans += tot - mx;
		}
	printf("%d\n",ans);
	return 0;
}
