#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 222222 + 10;
int n,tot,a[maxn],cnt[maxn],d[maxn],mu[maxn],vis[maxn],p[maxn];

void Mobius()
{
	tot = 0;
	mu[1] = 1;
	F(i,2,maxn-1)
	{
		if(!vis[i])
		{
			p[tot++] = i;
			mu[i] = -1;
		}
		R(j,tot)
		{
			int t = i*p[j];
			if(t >= maxn) break;
			vis[t] = 1;
			if(i%p[j]) mu[t] = -mu[i];
			else
			{
				mu[t] = 0;
				break;
			}
		}
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	Mobius();
	while(~scanf("%d",&n))
	{
		fill(cnt,0);
		fill(d,0);
		int mx = 0;
		R(i,n)
		{
			int x;
			scanf("%d",&x);
			cnt[x]++;
			mx = max(x,mx);
		}
		LL ans = 0;
		F(i,1,mx)
			for(int j=i;j<=mx;j+=i) d[i] += cnt[j];
		F(i,1,mx)
		{
			ans += 1LL*d[i]*(d[i]-1)/2*mu[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
