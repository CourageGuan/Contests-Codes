//反素数
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

typedef unsigned long long ULL;
ULL ans ;
bool vis[1010];
int n;
vector<int> primes;

void init()
{
	primes.clear();
	memset(vis,0,sizeof vis);
	for(int i=2; primes.size()<60 ;++i)
	{
		if(!vis[i])
		{
			primes.push_back(i);
			for(int j=i+i;j<1000;j+=i) vis[j] = 1;
		}
	}
}

void dfs(int num,int p,ULL res)
{
	if(num>n) return;
	if(num==n && res<ans) ans = res;
	for(int i=1;i<60;++i)
	{
		if(res*primes[p] > ans) break;
		dfs(num*(i+1),p+1,res *= primes[p]);
	}
}

int main()
{
	init();
	while(scanf("%d",&n)==1)
	{
		ans = 1e19;
		dfs(1,0,1);
		printf("%llu\n",ans);	
	}
	return 0;
}


