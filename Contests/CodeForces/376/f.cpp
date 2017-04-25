#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e5 + 10;
int n;
int a[maxn],cnt[2*maxn],sum[2*maxn];

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);		
	int mn = maxn,mx = 0;
	F(i,1,n) scanf("%d",a+i),cnt[a[i]]++,mx=max(mx,a[i]),mn=min(mn,a[i]);
	F(i,1,2*mx+1) sum[i] = sum[i-1] + cnt[i];
	LL ans = 0;
	F(i,mn,mx)
	{
		if(!cnt[i]) continue;
		LL cur = 0,t = 1;
		for(int j=i;j<=mx;j+=i)
		{
			cur += i*t*(sum[j+i-1] - sum[j-1]);
			++t;
		}
		ans = max(ans,cur);
	}
	printf("%lld\n",ans);
	return 0;
}

