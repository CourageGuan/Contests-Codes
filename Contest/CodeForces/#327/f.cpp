#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 150 + 10;
int a[maxn],tmp[maxn];
int d[2][maxn][maxn*maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,k,s;
	scanf("%d %d %d",&n,&k,&s);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	int ans,cnt = 0;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(a[i] > a[j]) ++cnt;
	if(s >= cnt)
	{
		for(int i=0;i<n;++i) tmp[i] = a[i];
		sort(tmp,tmp+n);
		ans = 0;
		for(int i=0;i<k;++i) ans += tmp[i];
		printf("%d\n",ans);
		return 0;
	}
	int sum = s + k*(k+1)/2,cur = 1;
	memset(d,INF,sizeof d);
	d[cur][0][0] = 0;
	ans = INF;
	for(int i=1;i<=n;++i)
	{
		cur ^= 1;
		memset(d[cur],INF,sizeof d[cur]);
		for(int j=0; j <= k;++j)
		{
			for(int t=0; t <= sum;++t)
			{
				if(j+1<=k && t+i <= sum) d[cur][j+1][t+i] = min(d[cur][j+1][t+i],d[cur^1][j][t]+a[i-1]);
				d[cur][j][t] = min(d[cur][j][t],d[cur^1][j][t]);
				if(j==k) ans = min(ans,d[cur][j][t]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
