#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define gcd __gcd

map<LL,LL> vis;

LL pow_m(LL a,LL n,LL mod)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a %mod;
		a = a*a %mod;
		n >>= 1;
	}
	return res;
}

LL bsgs(int a,int b,int m)
{
	a %= m,b %= m;
	if(b == 1) return 0;
	int n = int(sqrt(1.0*m) + 1),cnt = 0;
	LL t = 1;
	for(int g = gcd(a,m);g != 1;g = gcd(a,m))
	{
		if(b % g) return -1;
		m /= g, b /= g, t = a/g*t %m;
		++cnt;
		if(b == t) return cnt;
	}

	vis.clear();
	LL base = b;
	R(i,n) vis[base] = i,base = base*a %m;
	base = pow_m(a,n,m);
	F(i,1,n+1)
	{
		t = t * base %m;
		if(vis.count(t))
			return 1LL*n*i - vis[t] + cnt;
	}
	return -1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int a,m,b;
	while(scanf("%d %d %d",&a,&m,&b),a)
	{
		LL ans = bsgs(a,b,m);
		if(ans == -1) puts("No Solution"); 
		else printf("%lld\n",ans);
	}
	return 0;
}
