#include<bits/stdc++.h>
using namespace std;
typedef double DB;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define P(x) (1LL*(x)*(x))

LL get(LL x)
{
	LL res = 1;
	for(LL i=2;i*i<=x;++i)
	{
		if(x%i == 0)
		{
			int cnt = 0;
			while(x %i == 0)
			{
				x /= i;
				cnt ++;
			}
			if(cnt&1) res *= i;
		}
		if(x == 1) break;
	}
	if(x != 1) res *= x;
	return res;
}

LL gett(LL x)
{
	LL res = 1;
	for(LL i=2;i*i<=x;++i)
	{
		if(x%i == 0)
		{
			int cnt = 0;
			while(x %i == 0)
			{
				x /= i;
				cnt ++;
			}
			F(j,1,(cnt+1)/2)
				res *= i;
		}
		if(x == 1) break;
	}
	if(x != 1) res *= x;
	return res;
}

int main()
{
//	freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	LL lst = 2;
	F(i,1,n)
	{
		LL t = get(i);
		LL res = t*P(i+1) - lst;
//		assert(res >= 0 && res <= LL(1e18));
		printf("%lld\n",res);
		lst = gett(i);
	}
	return 0;
}
