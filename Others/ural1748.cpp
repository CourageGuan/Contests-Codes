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
	for(int i=2;primes.size()<16;++i)
	{
		if(!vis[i])
		{
			primes.push_back(i);
			for(int j=i+i;j<1000;j+=i) vis[j] = 1;
		}
	}
}

void dfs(int k,int limit,int p,ULL cur)
{
	if(cur > n) return ;
	if(rec < k || (rec==k && ans > cur ))
	{
		rec = k;
		ans = cur;
	}
	for(int i=1;i<=limit;++i)
	{
		if((double)cur * primes[p] > n) break;
		dfs(k*(i+1),i,p+1,cur *= primes[p]);
	}
}

int main()
{
	init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%llu",&n);
		rec = 1;
		ans = n;
		dfs(1,60,0,1);
		printf("%I64u %d\n",ans,rec);
	}
	return 0;
}
