#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define fi first
#define se second


const int maxn = 1e5 + 10;
int vis[maxn];
int n,m,k;
int a[maxn];
vector<pair<pair<int,int>,int> > E;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&k);
	R(i,m)
	{
		int u,v,d;
		scanf("%d %d %d",&u,&v,&d);
		E.push_back(mp(mp(u,v),d));
	}
	R(i,k)
	{
		scanf("%d",a+i);
		vis[a[i]] = 1;
	}
	int ans = 0x3f3f3f3f;
	R(i,m)
	{
		if(vis[(E[i].fi).fi] + vis[(E[i].fi).se] == 1)
		{
			ans = min(ans,E[i].se);
		}
	}
	printf("%d\n",ans==0x3f3f3f3f?-1:ans);
	return 0;
}
