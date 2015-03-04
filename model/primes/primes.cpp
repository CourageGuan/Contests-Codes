#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;
const int maxn=100000000 + 7;

bool vis[maxn];
ll primes[maxn/2];

void shai(ll n){
	memset(vis,0,sizeof(vis));
	ll m=sqrt(n+0.5);
	for(ll i=2;i<=m;++i) if(!vis[i])
		for(ll j=i*i;j<=n;j+=i) vis[j]=1;
}

int main()
{
	freopen("primes.txt","w",stdout);
	ll n,cnt=0;
	scanf("%lld",&n);
	shai(n);
	for(int i=2;i<=n;++i)
		if(!vis[i]) primes[cnt++]=i;
	printf("const int primes[%lld] = { ",cnt);
	for(int i=0;i<cnt;++i){
		printf("%lld",primes[i]);
		printf((i==cnt-1)?" }":",");
		if((i+1) % 20 == 0) printf("\n");
	}
	return 0;
}
