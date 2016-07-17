#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int d[maxn];
LL ans;
int n,m;

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
	for(int i=1;i<=n;++i) d[i] = 1;
	ans = 0;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<G[i].size();++j)
		{
			int v = G[i][j];
			if(v < i) d[i] = max(d[i],d[v]+1);
		}
		ans = max(ans,(LL)d[i]*(LL)G[i].size());
	}
	printf("%lld\n",ans);
	return 0;
}
