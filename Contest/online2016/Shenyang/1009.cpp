#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 303;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll k[maxn],v[maxn],d[maxn][maxn][2],g[maxn][maxn];
ll n;

ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}

char *ch, buf[20*1024000+5];

bool read(ll &x) {
	for (++ch; (*ch) &&
			!(((*ch) >= '0' && (*ch) <= '9') || (*ch) == '-' ); ++ch);
	if(!(*ch)) return false;
	bool sign = 0;
	if((*ch) == '-') { sign = 1; ++ch; }
	for (x = 0; '0' <= *ch; ch++)	x = x * 10 + *ch - '0';
	if(sign) x = -x;
	return true;
}

inline void update(ll &a,ll b)
{
	if(a < b)
		a = b;
}

int main()
{
	//freopen("test.txt","r",stdin);
	ch = buf - 1;
	fread(buf, 1, 1000 * 18 * 1024, stdin);

	ll T;
	read(T);
	F(z,1,T)
	{
		read(n);
		F(i,1,n) read(k[i]);
		F(i,1,n) read(v[i]);
		F(i,1,n) F(j,1,n) g[i][j] = gcd(k[i],k[j]);
		memset(d,-INF,sizeof(d));
		F(i,1,n) d[i][i][0] = 0;
		F(len,2,n)
			for(ll l=1;l+len-1<=n;++l)
			{
				ll r = l+len-1;
				F(i,l,r)
				{
					if(i+1 <= r)
					{
						ll maxl = max(d[l][i][0],d[l][i][1]);
						ll maxr = max(d[i+1][r][0],d[i+1][r][1]);
						update(d[l][r][0],maxl+maxr);
					}
					if(i != l && g[l][i] != 1)
					{
						ll cur = v[i] + v[l];
						if(l+1 <= i-1) cur += d[l+1][i-1][1];
						if(i+1 <= r)  cur += d[i+1][r][1];
						update(d[l][r][1],cur);

						cur = v[i] + v[l];
						if(l+1 <= i-1) cur += d[l+1][i-1][1];
						if(i+1 <= r) cur += d[i+1][r][0];
						update(d[l][r][0],cur);
					}
					if(i != r && g[i][r] != 1)
					{
						ll cur = v[i] + v[r];
						if(i+1 <= r-1) cur += d[i+1][r-1][1];
						if(l <= i-1) cur += d[l][i-1][0];
						update(d[l][r][0],cur);
					}
				}
			}
		ll ans = d[1][n][0];
		update(ans,d[1][n][1]);
		printf("%lld\n",ans);
	}
	return 0;
}
