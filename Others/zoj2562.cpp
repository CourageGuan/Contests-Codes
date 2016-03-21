#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

typedef unsigned long long ULL;
vector<int> primes;
bool vis[1010];
ULL n,ans;
int rec;

void init()
{
	primes.clear();
	for(int i=2;primes.size()<54;++i)
	{
		if(!vis[i])
		{
			primes.push_back(i);
			for(int j=i+i;j<1000;j+=i) vis[j] = 1;
		}
	}
}

void dfs(int k,int p,ULL cur)
{
	if(rec < k || (rec==k && ans > cur ))
	{
		rec = k;
		ans = cur;
	}
	for(int i=1;i<55;++i)
	{
		if(cur * primes[p] > n) break;
		dfs(k*(i+1),p+1,cur *= primes[p]);
	}
}

int main()
{
	init();
	while(scanf("%llu",&n)==1)
	{
		rec = 1;
		ans = n;
		dfs(1,0,1);
		printf("%llu\n",ans);	
	}
	return 0;
}
