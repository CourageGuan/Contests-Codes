#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const LL INF = 1e18;
const DB eps = 1e-9;

int main()
{
//	freopen("test.txt","r",stdin);
	LL n,m,k;
	scanf("%lld",&n);
	if(n < 3)
	{
		puts("-1");
		return 0;
	}
	if(n&1)
	{
		LL a = n;
		printf("%lld %lld\n",(a*a-1)/2,(a*a+1)/2);
	}
	else
	{
		LL a = n/2;
		printf("%lld %lld\n",(a*a-1),(a*a+1));
	}
	return 0;
}
