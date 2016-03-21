#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1e6 + 10;
const LL mod = 1e9 + 7;

map<int,int> val;

int a[maxn],r[maxn];
LL dp[2][maxn];
vector<LL> d[maxn],sum[maxn];

int n,k;
LL l;

int main()
{
	//freopen("test.txt","r",stdin);

	scanf("%d %lld %d",&n,&l,&k);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	if(n>=l)
	{
	   	printf("%lld\n",l);
		return 0;
	}
	LL B = l/n,ans = l%mod;
	int rem = l%n;

	for(int i=0;i<rem;++i) r[i] = a[i];

	sort(a,a+n);
	for(int i=0;i<n;++i) val[a[i]] = i;

	memset(dp,0,sizeof dp);
	int cur = 0;
	for(int i=0;i<n;++i) dp[1][i] = 1;

	for(int i=2;i<=min(B+1,(LL)k);++i)
	{
		LL sum = 0;
		int cnt = 0;
		for(int j=0;j<n;++j)
		{
			while( cnt<n && a[j] >= a[cnt]) sum = (sum + dp[cur^1][cnt])%mod,++cnt;
			dp[cur][j] = sum;
			d[i].push_back(sum);
		}
		cur^=1;
	}

	for(int i=2;i<=min(B+1,(LL)k);++i)
	{
		LL s = 0;
		for(int j=0;j<n;++j) 
		{
	//		printf("%d %d %lld\n",i,j,d[i][j]);
			s = (s + d[i][j]) %mod;
			sum[i].push_back(s);
		}
	}

	for(int i=2;i<=min(B,(LL)k);++i) ans = (ans + (B-i+1)%mod*sum[i][n-1]%mod)%mod;
	for(int i=2;i<=min(B+1,(LL)k);++i)
		for(int j=0;j<rem;++j)
		{
			int p = val[r[j]];
			ans = (ans + d[i][p])%mod;
		}

	printf("%lld\n",ans);
	return 0;
}

