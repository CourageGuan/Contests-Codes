#include<cstdio>

typedef long long LL;
LL p[33];

int main()
{
	LL n;
	scanf("%lld",&n);
	p[0] = 1;
	for(int i=1;i<=n;++i) p[i] = p[i-1]*4;
	LL res = 4*(2*3*p[n-3] + (n-3)*3*3*p[n-4>=0?n-4:0]);
	printf("%lld\n",res);
	return 0;
}
