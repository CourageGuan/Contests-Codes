#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e7 + 10;
int T,R,N,M,tot;

bool vis[maxn];
int primes[maxn],fac[maxn],inv[maxn];
LL ans[maxn];

LL pow_m(LL a,LL n,LL mod)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return res;
}

void init()
{
	int tot=0;
	for(int i=2;i<=maxn;++i){
		if(!vis[i]) primes[tot++]=i;
		for(int j=0;j<tot;++j){
			int t=i*primes[j];
			if(t>maxn) break;
			vis[t]=1;
			if(i%primes[j]==0) break;
		}
	}
	inv[1] = 1;
	F(i,2,maxn-1) inv[i] = (R - R/i)*(LL)inv[R%i]%R;
	fac[0] = 1;
	F(i,1,maxn-1) fac[i] = 1LL*fac[i-1]*i%R;
	ans[1] = 1;
	F(i,2,maxn-1)
	{
		ans[i] = ans[i-1];
		if(!vis[i]) ans[i] = ans[i-1]*(i-1)%R*inv[i]%R;
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&T,&R);	
	init();
	R(z,T)
	{
		scanf("%d %d",&N,&M);
		printf("%lld\n",ans[M]*fac[N]%R);
	}
	return 0;
}
