#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	LL n;
	scanf("%lld",&n);
	LL l = 0,r = sqrt(2*n)+1,t=0;
	while(l <= r)
	{
		LL m = (l+r)>>1;
		if(m*(m+1)/2 < n) l = m+1,t = m;
		else r = m-1;
	}
	printf("%lld\n",n-t*(t+1)/2);
	return 0;
}
