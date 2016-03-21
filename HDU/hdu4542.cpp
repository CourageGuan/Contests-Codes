#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

typedef long long ULL;

const ULL INF = (1LL<<62)+1;
const int maxn = 50010;
ULL ans;

bool vis[100];
vector<int> primes;
int d[maxn];

int n,type;

void init()
{
	memset(vis,0,sizeof vis);
	primes.clear();

	for(int i=2;primes.size()<16;++i)
	{
		if(!vis[i])
		{
			primes.push_back(i);
			for(int j=i+i;j<100;j+=i) vis[j] = 1;
		}
	}

	for(int i=1;i<maxn;++i) d[i] = i;
	for(int i=1;i<maxn;++i)
	{
		for(int j=i;j<maxn;j+=i) --d[j]; 
		if(!d[d[i]]) d[d[i]] = i;
		d[i] = 0;
	}
}

void dfs(int p,int k,ULL cur,int limit)
{
	if(k > n) return;
	if(k == n && ans > cur) ans = cur;
	for(int i = 1;i <= limit; ++i)
	{
		if(ans/primes[p] < cur || k*(i+1) > n) break;
		cur *= primes[p];
		if(n%(k*(i+1)) == 0)
			dfs(p+1,k*(i+1),cur,i);
	}
}


int main()
{
	init();
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d %d",&type,&n);
		printf("Case %d: ",z);
		if(type)
		{
			ans = d[n];
		}
		else
		{
			ans = INF;
		   	dfs(0,1,1,62);
		}
		if(ans == 0) puts("Illegal");
		else if(ans >= INF) puts("INF");
		else printf("%I64d\n",ans);
	}
	return 0;
}

