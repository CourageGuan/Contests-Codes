#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 1000010;
int n;
bool vis[maxn];
int ans[810];
pair<int,int> a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&n)==1)	
	{
		int mx = 0;
		n*=2;
		memset(ans,0,sizeof ans);
		memset(vis,0,sizeof vis);
		for(int i=2;i<=n;++i)
		{
			for(int j=1;j<i;++j)
			{
				int t;
				scanf("%d",&t);
				a[t] = make_pair(j,i);
				mx = max(mx,t);
				vis[t] = 1;
			}
		}
		for(int i=mx;i>0;--i)
		{
			if(!vis[i]) continue;
			int u = a[i].first,v = a[i].second;
			if(ans[u] || ans[v]) continue;
			ans[u] = v;
			ans[v] = u;
		}
		for(int i=1;i<=n;++i) printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}
