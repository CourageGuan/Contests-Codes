#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 110;
int a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	LL sum = 0;
	F(i,1,n) scanf("%d",a+i),sum += a[i];
	sum /= n;
	LL res = 1e9;
	F(i,-1,1)
	{
		LL cur = 0;
		F(j,1,n)
		{
			cur += (sum+i - a[j])*(sum+i - a[j]);
		}
		res = min(res,cur);
	}
	printf("%lld\n",res);
	return 0;
}
