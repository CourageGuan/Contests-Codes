#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

typedef long long LL;
#define N 10000
const int maxn=10010;
const int mod=10007;
int map[maxn],f[maxn],cnt[maxn],primes[maxn],mu[maxn];
bool vis[maxn];

void Mobius(){
	memset(vis,0,sizeof vis);
	int tot=0;mu[1]=1;
	for(int i=2;i<N;++i){
		if(!vis[i]){
			primes[tot++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<tot;++j){
			int t=i*primes[j];
			if(t>N) break;
			vis[t]=1;
			if(i%primes[j]==0){
				mu[t]=0;
				break;
			}
			else mu[t]=-mu[i];
		}
	}
}


void init(){
	memset(map,0,sizeof map);
	memset(f,0,sizeof f);
	memset(cnt,0,sizeof cnt);
}

#define rep(i,n) for(int i=0;i<n;++i)


int main()
{
	//freopen("test.txt","r",stdin);
	int n,x;
	Mobius();
	while(~scanf("%d",&n)){
		init();
		rep(i,n){
		   	scanf("%d",&x);
			++map[x];
		}
		for(int i=2;i<=N;++i){
			for(int j=i;j<=N;j+=i)
				f[i]+=map[j];
			f[i]%=mod;
		}
		LL ans=0;
		for(int i=2;i<=N;++i){
			LL res=0;
			for(int j=i;j<=N;j+=i) res+=1LL*mu[j/i]*f[j]*f[j]%mod;
			ans=(ans+res*i*(i-1))%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}


