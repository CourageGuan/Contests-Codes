#include<cstdio>

typedef long long LL;

int main()
{
	int res = 0;
	LL a = 8,b = 9,c = 5,d = 7,lcm = a*b*c*d;
	long long n;
	scanf("%lld",&n);
	printf("%lld\n",n/lcm);
	return 0;
}
