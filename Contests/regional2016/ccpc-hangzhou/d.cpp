#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define len(x) (int(log10(x))+1)

int x,K,st,cnt[22],a[22];
LL p[22][22];
LL ans;

inline void init()
{
	memset(p,0,sizeof p);
	F(i,1,10)
	{
		p[i][1] = i;
		F(j,2,10) p[i][j] = p[i][j-1]*i;
	}
	//printf("%lld\n",p[9][9]*2);
}

void dfs(int n,int k,int a[],LL y)
{

	if(k > 9 && n) return;
	if(!n)
	{
		if(y <= 0 || len(y) != st) return;
		memset(cnt,0,sizeof cnt);

		LL t = y;
		while(t)
		{
			cnt[t%10]++;
			t/=10;
		}
		int flag = 1;
		F(i,0,9) if(cnt[i] != a[i])
		{
		   	flag = 0;
			break;
		}
		ans += flag;

		return;
	}
	F(i,0,n)
	{
		a[k] = i;
		y += i*p[k][K];
		dfs(n-i,k+1,a,y);
		y -= i*p[k][K];
	}
	a[k] = 0;
}

inline void solve(int n)
{
	st = n;
	memset(a,0,sizeof a);
	dfs(n,0,a,-x);
}

int main()
{
	//freopen("input.txt","r",stdin);
	init();
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%d %d",&x,&K);
		ans = 0;
		F(i,1,11)
		{
			solve(i);
		}
		printf("Case #%d: %lld\n",z,ans);
	}
	return 0;
}
