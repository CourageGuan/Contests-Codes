#include<bits/stdc++.h>
using namespace  std;
typedef long long LL;

const int maxn = 2010;
vector<LL> G[maxn];
int x[maxn],y[maxn];
int n;

LL solve()
{
	for(int i=0;i<n;++i) G[i].clear();
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			LL dis = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
			G[i].push_back(dis);
			G[j].push_back(dis);
		}
	}
	for(int i=0;i<n;++i) sort(G[i].begin(),G[i].end());
	LL res = 0;
	for(int i=0;i<n;++i)
	{
		int cnt = 1;
		for(int j=1;j<G[i].size();++j)
		{
			if(G[i][j] == G[i][j-1]) ++cnt;
			if(cnt != 1 && (G[i][j] != G[i][j-1] || j == G[i].size() - 1))
			{
				res += (LL)cnt*(cnt-1)/2;
				cnt = 1;
			}
		}
	}
	return res;
}


int main()
{
//	freopen("test.txt","r",stdin);
	freopen("boomerang_constellations.txt","r",stdin);
	freopen("ans_a.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d %d",x+i,y+i);
		printf("Case #%d: %lld\n",z,solve());
	}
	return 0;
}
