//用到了等比数列二分求和
//A^B的约数和等于A^B唯一分解p1^B*a1+p2*B*a2+...+pn^B*an后
//∑sum(pi,B*ai),sum表示等比数列求和
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;
const int mod=9901;
bool vis[10000];
int p[10000],e[10000];
vector<int> primes;
ll m;

void init()
{
	memset(vis,0,sizeof vis);
	int len=sqrt(50000000+0.5);
	primes.push_back(2);
	for(int i=3;i<=len;i+=2) if(!vis[i]){
		primes.push_back(i);
		for(int j=i+i;j<=len;j+=i) vis[j]=1;
	}
}

int fac(ll m,ll n)
{
	int cnt=0;
	memset(e,0,sizeof(e));
	for(int i=0;i<primes.size();++i){
		while(m%primes[i]==0){
			m/=primes[i];
			++e[cnt];
		}
		if(e[cnt]){
			p[cnt]=primes[i];
			e[cnt]*=n;
			++cnt;
		}
		if(m==1) break;
	}
	if(m!=1){
	   	p[cnt]=m;
		e[cnt]=n;
		++cnt;
	}
	return cnt;
}


ll qpow(ll a,ll n)
{
	if(!n) return 1;
	ll x=qpow(a,n/2);
	x=(x*x)%mod;
	if(n&1) x=(x*a)%mod;
	return x%mod;
}

ll sum(ll p,ll n)
{
	if(n==0) return 1;
	if(n&1)	return (1+qpow(p,n/2+1))*sum(p,n/2)%mod;
	else return ((1+qpow(p,n/2+1))*sum(p,(n-1)/2)%mod+qpow(p,n/2))%mod;
}

int main()
{
	init();
	ll n;
	while(~scanf("%lld %lld",&m,&n)){
		int len=fac(m,n);
		ll ans=1;
		for(int i=0;i<len;++i)
			ans=(ans*sum(p[i],e[i]))%mod;
		printf("%lld\n",ans);
	}
	return 0;
}


