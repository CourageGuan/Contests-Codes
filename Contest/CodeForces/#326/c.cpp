#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 10;
int w[maxn],cnt[maxn];

int main()
{
	int n,mx = 0;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",w+i),mx = max(mx,w[i]);
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<n;++i) ++cnt[w[i]];
	for(int i=0;i<=mx;++i)
	{
		if(cnt[i])
		{
		   	cnt[i+1] += cnt[i]/2;
			cnt[i] %= 2;
		}
	}
	for(int i=mx+1;;++i)
	{
		if(cnt[i])
		{
			mx = i;
		   	cnt[i+1] += cnt[i]/2;
			cnt[i] %= 2;
		}
		else break;
	}
	int ans = 0;
	for(int i=mx;i>=0;--i) while(cnt[i]) {cnt[i]/=2; ++ans;};
	printf("%d\n",ans);
	return 0;
}
