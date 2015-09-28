#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL cal(LL n)
{
	if(n<0) return 0;
	return (n+1)*(n+2)/2;
}


int main()
{
	LL a,b,c,l;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&l);
	LL ans = (l+3)*(l+2)*(l+1)/6;
	for(int i=0;i<=l;++i)
	{
		ans -= cal(min(l-i,a-b-c+i));
		ans -= cal(min(l-i,b-a-c+i));
		ans -= cal(min(l-i,c-a-b+i));
	}
	printf("%lld\n",ans);
	return 0;
}
