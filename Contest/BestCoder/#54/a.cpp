#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

typedef long long LL;
int n;
const int maxn = 110;
const int N = 100000;
vector<int> primes;
int vis[N*10];

LL gcd(LL a,LL b)
{
	return !b?a:gcd(b,a%b);
}

void init()
{
	primes.clear();
	memset(vis,0,sizeof vis);
	for(int i=2; i<N ;++i)
	{
		if(!vis[i])
		{
			primes.push_back(i);
			for(int j = i+i ; j <N ;j+=i) vis[j] = 1;
		}
	}
}

void solve(int x)
{
	for(int i=0;i<primes.size();++i)
	{
		int t = primes[i];
		if(x%t == 0)
		{
			int cnt = 0;
			while(x%t==0) x/=t,++cnt;
			vis[i] += cnt;
		}
		if(x == 1) break;
	}
	if(x!=1)
	{
	   	vis[primes.size()] = 1;
		primes.push_back(x);
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(vis,0,sizeof vis);
		LL mx = 9;
		for(int i=0;i<n;++i)
		{
			int x;
			scanf("%d",&x);
			solve(x);
		}
		LL res = 1;
		int cnt = 1;
		for(int i=0;i < primes.size();++i)
		{
			while(vis[i] && cnt<3)
			{
				--vis[i];
				++cnt;
				res*=primes[i];
			}
			if(cnt>=3) break;
		}
		if(cnt<3) res = -1;
		printf("%lld\n",res);
	}
	return 0;
}




