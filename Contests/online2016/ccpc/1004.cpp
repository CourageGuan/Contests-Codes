#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

int a[20];

int main()
{
//	freopen("test.txt","r",stdin);
	int T,n;
	scanf("%d",&T);
	F(z,1,T)
	{
		int sum = 0,ans = 0;
		scanf("%d",&n);
		R(i,n) scanf("%d",a+i),sum += a[i];
		if(n == 1)
		{
			printf("Case #%d: %d\n",z,min(1,sum/2));
			continue;
		}
		int cur = a[0];
		F(i,1,n-1)
		{
			ans += min(cur,a[i])*2;
			cur = abs(cur - a[i]);
		}
		printf("Case #%d: %d\n",z,min(ans,sum/2));
	}
	return 0;
}
