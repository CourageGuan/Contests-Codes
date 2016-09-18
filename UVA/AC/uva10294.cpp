#include<bits/stdc++.h>

typedef long long LL;

LL n,t,p[100];

int main()
{
//	freopen("test.txt","r",stdin);
	while(scanf("%lld %lld",&n,&t) == 2)
	{
		LL a = 0,b = 0;
		p[0] = 1;
		for(int i=1;i<=n;++i) p[i] = p[i-1]*t;
		for(int i=0;i<n;++i) a += p[std::__gcd(1LL*i,n)];
		if(n&1) b = n*p[(n+1)/2];
		else b = n/2*(p[n/2+1] + p[n/2]);
		printf("%lld %lld\n",a/n,(a+b)/n/2);
	}
	return 0;
}
