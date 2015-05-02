//非常经典的问题，n个1,m个0满足0的累加数始终小于1的累加数的01串种类
//答案为 C(m+n,n)-C(m+n,n+1)
//由于m,n很大，涉及分解质因子取模，和阶乘分解质因子优化
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;

const int maxn=2000000+10;
const int mod=20100501;
typedef long long ll;
int len,e[150000];
bool vis[maxn];
vector<int> primes;

void init()
{
	primes.clear();
	memset(vis,0,sizeof vis);
	primes.push_back(2);
	for(int i=3;i<maxn;i+=2) if(!vis[i]){
		primes.push_back(i);
		for(int j=i+i;j<maxn;j+=i) vis[j]=1;
	}
}

void mul(int n)	 //分解一个数质因子
{
	for(int i=0;i<primes.size();++i){
		while(n%primes[i]==0){
			n/=primes[i];
			++e[i];
		}
		if(n==1) break;
	}
}


void divf(int n,int op)	//分解阶乘质因子
{
	int i;
	for(i=0;i<primes.size();++i){
		if(primes[i]>n) break;
		int temp=n;
		while(temp){
			temp/=primes[i];
			if(op==1)
				e[i]+=temp;
			else
				e[i]-=temp;
		}
	}
	len=max(len,i);
}

ll qpow(int a,int n)
{
	if(!n) return 1;
	ll x=qpow(a,n>>1);
	x=(x*x)%mod;
	if(n&1)
		x=(x*a)%mod;
	return x;
}

ll solve()
{
	ll ans=1;
	for(int i=0;i<len;++i)
	{
		/*ll res=1,a=primes[i],b=e[i];
		while(b)
		{
			if(b&1) res*=a%mod;
			a=(a*a)%mod;
			b>>=1;
		}
		ans=ans*res%mod;
		*/
		ans=ans*qpow(primes[i],e[i])%mod;
	}
	return ans;
}

int main()
{
	init();
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		if(m>n){
			puts("0");
			continue;
		}
		memset(e,0,sizeof(e));
		len=0;
		mul(n-m+1);
		divf(m+n,1);
		divf(n+1,-1);
		divf(m,-1);
		printf("%lld\n",solve());
	}
	return 0;
}

