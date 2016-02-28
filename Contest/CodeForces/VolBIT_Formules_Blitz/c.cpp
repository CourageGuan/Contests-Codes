#include<cstdio>

typedef long long LL;


int main()
{
	int n;
	LL ans = 0,cur = 2;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		ans += cur;
		cur*=2;
	}
	printf("%lld\n",ans);
	return 0;
}
