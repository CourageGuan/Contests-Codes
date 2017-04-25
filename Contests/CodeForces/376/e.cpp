#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e5 + 10;
int n;
LL a[maxn],d[maxn];

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	F(i,1,n) scanf("%lld",a+i),a[i] += a[i-1];
	d[n] = a[n];
	LL mx = d[n];
	for(int i=n-1;i>=1;--i)
	{
		d[i] = mx;
		mx = max(mx,a[i]-d[i]);
	}
	printf("%lld\n",d[1]);
	return 0;
}
