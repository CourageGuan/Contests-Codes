#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,k;

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("C-large.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%lld %lld",&n,&k);
		LL a,b,s,sa,cnt = 1,mn = (n-1)/2,mx = n/2;
		a = n/2;
		b = (n-1)/2;
		s = 2;
		if(a == b) sa = 2;
		else sa = 1;
		for(;cnt < k;)
		{
			if(cnt + s >= k)
			{
				//printf("%lld %lld\n",cnt,s);
				k -= cnt;
				if(k <= sa)
				{
					mn = (a-1)/2;
					mx = a/2;
				}
				else
				{
					mn = (b-1)/2;
					mx = b/2;
				}
				break;
			}
			cnt += s;
			LL ta1 = (a-1)/2,ta2 = a/2,tb1 = (b-1)/2,tb2 = b/2;
			if(a == b)
			{
				if(ta1 == ta2)
					a = b = ta2,sa <<= 1;
				else
					a = ta2,b = ta1;
			}
			else
			{
				a = ta2,b = tb1;
				if(ta2 == tb2)
					sa = (s-sa) + (sa<<1);
			}
			s <<= 1;
		}
		printf("Case #%d: %lld %lld\n",z,mx,mn);
	}
	return 0;
}
