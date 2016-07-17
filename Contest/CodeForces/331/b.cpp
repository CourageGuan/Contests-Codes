#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;
LL b[maxn];

int main()
{
//	freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	LL cur = 0,ans = 0;
	for(int i=0;i<n;++i)
	{
		LL x;
		scanf("%lld",&x);
		ans += abs(x - cur);
		cur = x;
	}
	printf("%lld\n",ans);
	return 0;
}
