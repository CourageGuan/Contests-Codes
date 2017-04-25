#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1e5 ;
int a[maxn];

int main()
{
	int n;
	LL k;
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	int res = 0;
	LL cur = 0;
	for(int i=1;i<=n;++i)
	{
		cur += i;
		if(cur >= k)
		{
			res = i;
			break;
		}
	}
	k -= (cur-res);
	printf("%d\n",a[k-1]);
	return 0;
}
