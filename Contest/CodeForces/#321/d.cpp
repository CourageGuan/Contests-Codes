#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 18;
LL d[maxn+2][1<<maxn];
LL a[maxn+2],G[maxn+2][maxn+2];

inline int next(int x)
{
    int l = x & -x, y = x + l;
    return y | (((x^y) / l) >> 2);
}

void check(LL &x,LL y)
{
	if(x<y) x = y;
}

int sum(int x)
{
	int cnt = 0;
	while(x)
	{
		if(x&1) ++cnt;
		x>>=1;
	}
	return cnt;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)==3)
	{
		for(int i=0;i<n;++i) scanf("%lld",a+i);
		memset(G,0,sizeof G);
		for(int i=0;i<k;++i)
		{
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			G[x-1][y-1] = c;
		}
		memset(d,0,sizeof d);
		for(int i=0;i<n;++i)
		{
			d[i][1<<i] = a[i];
		}
		for(int i=0;i<(1<<n);++i)
		{
			for(int j=0;j<n;++j)
			{
				if(i&(1<<j)) continue;
				for(int t = 0;t<n;++t)
				{
					if(i&(1<<t))
					{
						check(d[j][i|(1<<j)],d[t][i]+G[t][j]+a[j]);
					}
				}
			}
		}
		LL ans = 0;
		for(int i=(1<<m)-1 ; i<(1<<n) ;i = next(i))
		{
			for(int j=0;j<n;++j)
			{
				if(i & (1<<j))
				{
					check(ans,d[j][i]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}



