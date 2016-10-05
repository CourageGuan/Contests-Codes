#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const LL mod = 1e9 + 7;

LL C[66][66],p2[66],P[66][66],n;
int bit[66],len;

void init()
{
	F(i,0,65)
	{
		C[i][0] = 1;
		F(j,1,i) C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
	}
	p2[0] = 1;
	F(i,1,65) p2[i] = p2[i-1]*2%mod;
	F(i,1,65)
	{
		P[i][0] = 2*p2[i-1]%mod*p2[i-1]%mod;
		F(j,1,i-1)
			F(k,0,j)
				P[i][k] = (P[i][k] + C[j][k]*2%mod*p2[i-j-1]%mod*p2[i-j-1]%mod)%mod;
	}
}

LL cal(LL n)
{
	LL res = 0;
	int cnt = 0;
	for(int i=len-1;i>=0;--i)
	{
		if(bit[i])
		{
			F(j,cnt == 0,i)
				res = (res + (j+cnt)*C[i][j]%mod) %mod;
			++cnt;
		}
	}
	res = (res+cnt)%mod;
	n %= mod;
	res = res*n%mod;
	return res;
}

LL cal1(LL n)
{
	LL res = 0;
	int cnt = 0;
	for(int i=len-1;i>=0;--i)
	{
		if(bit[i])
		{
			n -= 1LL << i;
			res = (res + (n+1)%mod*p2[i]%mod*2*cnt%mod)%mod;
			F(j,0,i-1)
				res = (res + (cnt+j)*P[i][j]%mod)%mod;
			++cnt;
		}
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	init();
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%lld",&n);
		len = 0;
		LL t = n;
		while(t)
		{
			bit[len++] = t&1;
			t >>= 1;
		}
		LL ans = ((cal(n) - cal1(n))%mod + mod)%mod;
		printf("Case #%d: %lld\n",z,ans);
	}
	return 0;
}

