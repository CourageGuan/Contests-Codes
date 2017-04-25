#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
int a[maxn],n;
int cnt[maxn],vis[maxn];
vector<int> fac[maxn];

void init()
{
	fill(vis,0);
	F(i,2,maxn-1)
	{
		if(vis[i]) continue;
		for(int j=i;j<maxn;j += i)
		{
			fac[j].push_back(i);
		   	vis[j] = 1;
		}
	}
}

int main()
{
//  freopen("test.txt","r",stdin);
	init();
	int T;	
	scanf("%d",&T);
	R(z,T)
	{
		scanf("%d",&n);
		fill(cnt,0);
		R(i,n)
		{
		   	scanf("%d",a+i);
			if(a[i] == 1) continue;
			for(int j=1;j*j<=a[i];++j)
			{
				if(a[i]%j) continue;
				cnt[j]++;
				if(j != a[i]/j) cnt[a[i]/j]++;
			}
		}
		LL res = 0;
		R(i,n)
		{
			if(a[i] == 1) continue;
			int s = fac[a[i]].size();
			LL	cur = 0;
			F(j,1,(1<<s)-1)
			{
				int sum = 1,c = 0;
				R(k,s) if(j&(1<<k)) sum *= fac[a[i]][k],++c;
				if(c&1) cur += cnt[sum];
				else cur -= cnt[sum];
			}
//			printf("%d\n",s);
			res += (cur - 1)*(n - cur);
		}
		LL ans = 1LL*n*(n-1)*(n-2)/6 - res/2;
		printf("%lld\n",ans);
	}
    return 0;
}
