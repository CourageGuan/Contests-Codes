#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
LL a[maxn];
int n;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	R(i,n) scanf("%lld",a+i);
	a[n] = 0;
	LL ans = 0,cur = 0;
	R(i,n+1)
	{
		if(a[i] != 0)
		{
			cur += a[i];
		}
		else
		{
			ans += cur/2;
			cur = 0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
