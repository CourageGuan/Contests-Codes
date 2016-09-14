//TLE
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 8e5 + 10;
int p;
LL n,k,times;
LL cnt[2][maxn],ans[maxn];

int dfs(LL x,LL y)
{
	if(x == 1) return 1;
	return (3*dfs(x-1,(y+1)/2) + !(y&1)) %k;
}

inline void cal(LL x,LL y,LL f)
{
	int cur = dfs(x,y);
//	printf("%lld %lld %lld %lld\n",x,y,f,cur);
	p = 0;
	fill(cnt[p],0);
	cnt[p][cur] = 1;
	while(x < f)
	{
		fill(cnt[p^1],0);
		R(i,k)
		{
			cnt[p^1][3*i%k] += cnt[p][i];
			cnt[p^1][(3*i+1)%k] += cnt[p][i];
		}
		p ^= 1;
		++x;
	}
	R(i,k) ans[i] += cnt[p][i];
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	R(z,T)
	{
		times = 0;
		scanf("%lld %lld",&n,&k);
		if(n == 0)
		{
			puts("0");
			continue;
		}
		int f = 1;
		p = 0;
		fill(ans,0);
		fill(cnt[p],0);
		cnt[p][1] = 1;
		while((1LL<<f)-1 <= n)
		{
			fill(cnt[p^1],0);
			R(i,k)
			{
				ans[i] += cnt[p][i];
				cnt[p^1][3*i%k] += cnt[p][i];
				cnt[p^1][(3*i+1)%k] += cnt[p][i];
			}
			p ^= 1;
			++f;
		}
	//	printf("!!%d\n",f);
	//	R(i,k) 
	//		printf("%lld ",ans[i]);
	//	puts("");
		LL m = (n - (1LL<<(f-1)) + 1),dec = 0;
		for(int i=f-1;i >= 0;--i)
		{
			if(m >= 1LL<<i)
			{
		//		printf("%d\n",i);
				times += i;
				cal(f - i,1+(dec/(1LL<<i)),f);
				m -= 1LL<<i;
				dec += 1LL<<i;
			}
		}
		LL res = 0;
		R(i,k) 
		{
			//printf("%d ",ans[i]);
			res ^= ans[i];
		}
//		puts("");
		printf("%lld\n",res);
	}
	return 0;
}
