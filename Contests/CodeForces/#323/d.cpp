#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
int a[2*maxn*maxn],cnt[maxn*3];
int d[2][2*maxn*maxn],dp[2][maxn*3];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,T;
	scanf("%d %d",&n,&T);
	int m = min(n,T);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	memset(cnt,0,sizeof cnt);
	memset(d,0,sizeof d);

	if(m*2 >= T) m = T;

	for(int i=0;i<n;++i)
	{
		++cnt[a[i]];
		for(int j=1;j<m;++j) a[i+n*j] = a[i];
	}

	for(int i=0;i<n*m;++i)
	{
		d[0][i] = 1;
		for(int j=0;j<i;++j)
		{
			if(a[i] >= a[j])
			{
				d[0][i] = max(d[0][i],d[0][j]+1);
			}
		}
		dp[0][a[i]] = d[0][i];
	}

	int ans = 0,t = T-m*2;
	if(m == T)
	{
		for(int i=1;i<=300;++i) ans = max(ans,dp[0][i]);
		printf("%d\n",ans);
		return 0;
	}

	for(int i=n*m;i>=0;--i)
	{
		d[1][i] = 1;
		for(int j=i+1;j<n*m;++j)
		{
			if(a[i] <= a[j])
			{
				d[1][i] = max(d[1][i],d[1][j]+1);
			}
		}
		dp[1][a[i]] = d[1][i];
	}

	for(int i=1;i<=300;++i)
	{
		if(!cnt[i]) continue;
		for(int j=i;j<=300;++j)
		{
			if(cnt[j])
			{
				ans = max(ans,dp[0][i]+dp[1][j]+max(cnt[i],cnt[j])*t);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
