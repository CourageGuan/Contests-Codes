#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod = 1e9 + 7;
const LL mod2 = 2LL*(mod-1);
const int maxn = 2e5 + 10;
int p[maxn],vis[maxn],cnt[maxn],m;

LL pow_mod(LL a,LL n)
{
	LL res = 1;
	while(n)
	{
		if(n & 1) res = res*a % mod;
		a = a*a %mod;
		n>>=1;
	}
	return res;
}

LL cal()
{
	LL n = 1,ans = 1;
	memset(vis,0,sizeof vis);
	for(int i=0;i<m;++i)
	{
		int t = p[i];
		if(vis[t]) continue;
		vis[t] = 1;
		n = n*(cnt[t] + 1) % mod2;
	}
	memset(vis,0,sizeof vis);
	for(int i=0;i<m;++i)
	{
		int t = p[i];
		if(vis[t]) continue;
		vis[t] = 1;
		ans = ans* pow_mod(t,(n*cnt[t]/2)%mod2) %mod;
	}
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&m);
	
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<m;++i)
	{
		int t;
		scanf("%d",p+i);
		++cnt[p[i]];
	}
	printf("%lld\n",cal());
	return 0;
}

