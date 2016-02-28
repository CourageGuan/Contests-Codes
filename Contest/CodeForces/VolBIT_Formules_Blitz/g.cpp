#include<cstdio>

typedef long long LL;

LL C(LL n,LL m)
{
	m = m < (n-m)? m:n-m;
	LL res = 1;
	for(int i=1;i<=m;++i) res = res*(n-i+1)/i;
	return res;
}

int main()
{
	LL n;
	scanf("%lld",&n);
	printf("%lld\n",C(n+2,3)*C(n+4,5));
}
