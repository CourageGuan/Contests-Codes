#include<cstdio>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int mod = 9901;

LL a,b;

LL pow_m(LL a,LL n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a %mod;
		a = a*a%mod;
		n >>= 1;
	}
	return res;
}

LL cal(LL a,LL n)
{
	return (pow_m(a,n)-1+mod)%mod*pow_m(a-1,mod-2)%mod;
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%lld %lld",&a,&b) == 2)
	{
		if(b == 0)
		{
			puts("1");
			continue;
		}
		if(a == 0)
		{
			puts("0");
			continue;
		}
		LL res = 1,t = a;
		for(LL i=2;i*i<=a;++i)
		{
			if(t%i == 0)
			{
				LL cnt = 0;
				while(t%i == 0)
				{
					t /= i;
					++cnt;
				}
				if(i%mod == 1)
					res = res*(cnt*b+1) %mod;
				else
					res = res*cal(i,b*cnt+1)%mod;
			}
			if(t == 1) break;
		}
		if(t != 1)
		{

			if(t%mod == 1)
				res = res*(b+1) %mod;
			else
				res = res*cal(t,b+1)%mod;
		}
		printf("%lld\n",res);
	}
	return 0;
}
