#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int cnt[12];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		++cnt[x];
	}
	LL ans = 0;
	for(int i=1;i<=10;++i)
	{
		ans += (n-cnt[i])*cnt[i];
	}
	printf("%lld\n",ans/2);
	return 0;
}
