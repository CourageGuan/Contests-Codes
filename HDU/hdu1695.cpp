#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

typedef long long ll;
const int maxn=1000000;
int mu[maxn+10],primes[maxn];
bool vis[maxn+10];

void Mobius(){
	memset(vis,0,sizeof (vis));
	int tot=0; mu[1]=1;
	for(int i=2;i<=maxn;++i){
		if(!vis[i]){
			primes[tot++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<tot;++j){
			if(i*primes[j]>maxn) break;
			vis[i*primes[j]]=1;
			if(i%primes[j]==0){
				mu[i*primes[j]]=0;
				break;
			}
			else{
				mu[i*primes[j]]=-mu[i];
			}
		}
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	Mobius();
	int T,a,b,c,d,k;
	scanf("%d",&T);
	for(int kase=1;kase<=T;++kase){
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		if(!k){
			printf("Case %d: 0\n",kase);
			continue;
		}
		b/=k;d/=k;
		int ran=min(b,d);
		ll ans=0,rep=0;
		for(int i=1;i<=ran;++i) ans+=(ll)mu[i]*(b/i)*(d/i);
		for(int i=1;i<=ran;++i) rep+=((ll)mu[i]*(ran/i)*(ran/i));
		printf("Case %d: %lld\n",kase,ans-rep/2);
	}
	return 0;
}


