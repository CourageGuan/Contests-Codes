#include<cstdio>

typedef long long LL;


int main()
{
	LL n;
	LL f5 = 120,cur = 1;
	scanf("%lld",&n);
	for(int i=1;i<=5;++i) cur*=n,--n;
	cur /= f5;
	cur*=cur;
	cur*=f5;
	printf("%lld\n",cur);
}
