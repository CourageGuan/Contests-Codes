#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
int a[maxn],vis[maxn],s[maxn],cnt;
vector<int> C;

LL pow_m(LL a,LL n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return res;
}

void dfs(int u,int k)
{
	vis[u] = -1;
	s[u] = k;
	if(vis[a[u]] == -1)
	{
		cnt = k - s[a[u]] + 1;
		vis[u] = 1;
		return ;
	}
	if(vis[a[u]] == 1)
	{
		cnt = -1;
		vis[u] = 1;
		return ;
	}
	dfs(a[u],k+1);
	vis[u] = 1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	LL res = 1,un = n;
	F(i,1,n)
	{
		if(!vis[i])
		{
			cnt = 0;
			dfs(i,1);
			if(cnt != -1)
			{
				un -= cnt;
//				printf("%d\n",cnt);
				res = (res * (pow_m(2,cnt) - 2 + mod)%mod)%mod;
			}
		}
	}
	res = res*pow_m(2,un)%mod;
	printf("%lld\n",res);
	return 0;
}
