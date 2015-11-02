#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int h,w,n;

const int maxn = 2010;
const int mod = int(1e9) + 7;

struct P
{
	int x,y;
	P() {}
	P(int x,int y):x(x),y(y) {}
	bool operator<(const P& rhs) const
	{
		return x<rhs.x || (x == rhs.x && y<rhs.y);
	}
} p[maxn];
LL fac[200010];

LL qpow(LL a,int n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a % mod;
		a = a*a % mod;
		n >>= 1;
	}
	return res;
}

LL C(LL n,LL m)
{
	if(m == 0) return 1;
	return fac[n]*qpow(fac[n-m]*fac[m]%mod,mod - 2)%mod;
}

LL d[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	fac[0] = 1;
	for(int i=1;i<200010;++i) fac[i] = fac[i-1] * i % mod;
	scanf("%d %d %d",&h,&w,&n);
	for(int i=0;i<n;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		p[i] = P(x,y);
	}
	sort(p,p+n);
	if(p[n-1].x == h && p[n-1].y == w || p[0].x == 1 && p[0].y == 1) puts("0");
	else
	{
		p[n].x = h ;
		p[n].y = w ;
		memset(d,0,sizeof d);
		for(int i=0;i<=n;++i)
		{
			d[i] = C(p[i].x+p[i].y-2,p[i].x-1);
			for(int j=0;j<i;++j)
			{
				if(p[j].y <= p[i].y)
				{
					d[i] = (d[i] - C(p[i].x - p[j].x + p[i].y - p[j].y,p[i].x - p[j].x)*d[j])%mod;
				}
			}
		}
		d[n] = (d[n]%mod + mod) % mod;
		printf("%lld\n",d[n]);
	}
	return 0;
}


