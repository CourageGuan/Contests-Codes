#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e7 + 10;
int p[maxn],vis[maxn];
LL f[maxn],phi[maxn];
int n,tot;

void init()
{
	tot = 0;
	phi[1] = 1;
	for(int i=2;i < maxn;++i)
	{
		if(!vis[i])
		{
			p[tot++] = i;
			phi[i] = i - 1;
		}
		for(int j=0;j<tot;++j)
		{
			LL t = i*p[j];
			if(t >= maxn) break;
			vis[t] = 1;
			if(i%p[j]) phi[t] = phi[i] * (p[j]-1);
			else 
			{
				phi[t] = phi[i] * p[j];
				break;
			}
		}
	}
	f[1] = 1;
	for(int i=2;i<maxn;++i)
		f[i] = f[i-1] + (phi[i]<<1);
}

LL cal(int n)
{
	LL res = 0;
	for(int i=0;i < tot && p[i] <= n;++i)
		res += f[n/p[i]];
	return res;
}

int main()
{
//	freopen("test.txt","r",stdin);
	init();
	while(scanf("%d",&n) == 1)
	{
		printf("%lld\n",cal(n));
	}
	return 0;
}
