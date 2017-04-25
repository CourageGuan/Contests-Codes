#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2010;

LL cnt[2][maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<n;++i)
	{ 
		int x,y;
		scanf("%d %d",&x,&y);
		++cnt[0][x+y];
		++cnt[1][y-x+1000];
	}
	LL ans = 0;
	for(int i=0;i<maxn;++i)
	{
		ans += (cnt[0][i])*(cnt[0][i]-1)/2;
		ans += (cnt[1][i])*(cnt[1][i]-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}
