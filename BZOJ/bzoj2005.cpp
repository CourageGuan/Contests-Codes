//NOI2010 莫比乌斯反演
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

typedef long long LL;
const int maxn=100010;
int primes[maxn],mu[maxn],cnt[maxn];
bool vis[maxn];

void Mobius(int n){
	memset(vis,0,sizeof vis);
	int tot=0;mu[1]=1;
	for(int i=2;i<=n;++i){
		if(!vis[i]){
			primes[tot++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<tot;++j){
			int t=i*primes[j];
			if(t>n) break;
			vis[t]=1;
			if(i%primes[j]==0){
				mu[t]=0;
				break;
			}else mu[t]=-mu[i];
		}
	}
}


int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(m>n) swap(n,m);
	Mobius(n);
	LL ans=-(LL)m*n;
	for(int i=1;i<=n;++i){
		int tn=n/i,tm=m/i;
		LL res=0;
		for(int j=1;j<=tm;++j) res+=(LL)mu[j]*(tn/j)*(tm/j);
		ans+=res*2*i;
	}
	printf("%lld\n",ans);
	return 0;
}

