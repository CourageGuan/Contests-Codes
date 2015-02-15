#include<cstdio>

typedef long long LL;

const LL mod=1e9+7;

LL qpow(LL a,LL n,LL m)
{
	if(n==0) return 1;
	LL x=qpow(a,n/2,m);
	LL res=x*x%m;
	if(n&1) res=res*a%m;
	return res;
}

int main()
{
	LL a,n,m;
	scanf("%lld %lld",&a,&n);
	printf("%lld\n",qpow(a,n,mod));
	return 0;
}
