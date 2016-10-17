#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 10000007;
LL C[66][66];
LL res[66],n;
int bit[66],tot;

void init()
{
	for(int i=0;i<66;++i)
	{
		C[i][0] = 1;
		for(int j=1;j<=i;++j)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
}

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

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	init();
	while(~scanf("%lld",&n))
	{
		for(tot=0;n;n >>= 1)
			bit[++tot] = n&1;
		int cnt = 0;
		memset(res,0,sizeof res);
		for(int i=tot;i;--i)
		{
			if(bit[i] == 1)
			{
				for(int j=(cnt==0);j<i;++j)
					res[cnt+j] = (res[cnt+j] + C[i-1][j]);
			}
			cnt += bit[i];
		}
		LL ans = cnt;
		for(int i=1;i<=tot;++i)
		   	ans = ans*pow_m(i,res[i])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
