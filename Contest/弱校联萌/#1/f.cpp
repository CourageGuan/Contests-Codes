//dp 先预处理出每个数的因子
//d[i][j] 表示满足最小改变率的序列的第i个数改为j的最大消耗 转移方程为
//	d[i][j] = min(d[i][j],max(d[i-1][k],change)); k 为 j 的因子
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;

const int maxn = 200010;
vector<int> fac[maxn];
double d[22][maxn];
int n,a[22];

void init()
{
	for(int i=1;i<maxn;++i)
	{
		for(int j=i;j<maxn;j+=i)
		{
			fac[j].push_back(i);
		}
	}
}

int main()
{
	init();
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;++i) scanf("%d",a+i);

		int m = maxn;

		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				d[i][j] = 1e9;

		for(int j=1;j<=m;++j)
		{
			d[1][j] = fabs((double)(a[1]-j)/a[1]);
		}
		for(int i=2;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				double change = fabs((double)(a[i]-j)/a[i]);
				for(int k=0;k<fac[j].size();++k)
				{
					d[i][j] = min(d[i][j],max(d[i-1][fac[j][k]],change));
				}
			}
		}
		double ans = 1e9;
		for(int i=1;i<=m;++i) ans=min(ans,d[n][i]);
		printf("%.10lf\n",ans);
	}
	return 0;
}

