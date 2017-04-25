#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int maxn = 210;
const int INF = 0x3f3f3f3f;
int d[maxn][maxn],a[maxn],b[maxn],n;

int dp(int l,int r)
{
	if(l > r) return 0;
	if(d[l][r] != -1) return d[l][r];
	int& ans = d[l][r];
	ans = INF;
	if(l == r)
	{
		return ans = b[l-1]+b[r+1];
	}
	for(int i=l;i<=r;++i)
	{
		ans = min(ans,dp(l,i-1)+dp(i+1,r)+b[l-1]+b[r+1]);
	}
//	printf("%d %d %d\n",l,r,ans);
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		LL ans = 0;
		memset(d,-1,sizeof d);
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",a+i),ans += a[i];
		for(int i=1;i<=n;++i) scanf("%d",b+i);
//		printf("%d\n",ans);
		printf("Case #%d: %d\n",z,ans+dp(1,n));
	}
	return 0;
}
