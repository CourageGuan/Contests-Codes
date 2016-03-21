// phi(n) 小于n的正整数且于n互质的个数
// phi(n)= n(1-1/p1)(1-1/p2)...(1-1/pk)
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;
const int maxn=100000;

ll phi(ll x)
{
	ll ans=x;
	for(int i=2;i<=(int)sqrt(x+0.5);++i) if(x%i==0) {
		ans=ans/i*(i-1);
		while(x%i==0) x/=i;
	}
	if(x>1) ans=ans/x*(x-1);
	return ans;
}

void phi_table(ll x,int phi[])
{
	memset(phi,0,sizeof(phi));
	phi[1]=1;
	for(ll i=2;i<=x;++i) if(!phi[i])
		for(ll j=i;j<=x;j+=i){
			if(!phi[j]) phi[j]=j;
			phi[j]=phi[j]/i*(i-1);
		}
}

int main()
{
	ll n;
	int tphi[maxn];
	//while(scanf("%lld",&n)==1) printf("%lld\n",phi(n));
	scanf("%lld",&n);
	phi_table(n,tphi);
	for(int i=1;i<=n;++i) printf("%d ",tphi[i]);
	return 0;
}


