#include<cstdio>
using namespace std;

const int maxn = 1010;
const int maxm = 33;
double p[maxn][maxm];

int m,t,n;

double dp[maxn][maxm][maxm];
double sum[maxn][maxm];

int main()
{
	//freopen("test.txt","r",stdin);

	while(scanf("%d %d %d",&m,&t,&n) == 3 && m+t+n)
	{
		double s = 1,d = 1;

		for(int i=1;i<=t;++i)
			for(int j=1;j<=m;++j)
				for(int k=0;k<=j;++k)
					dp[i][j][k] = 0;

		for(int i=1;i<=t;++i)
		{
			dp[i][0][0] = 1;
			for(int j=1;j<=m;++j)
			{
				scanf("%lf",&p[i][j]);
				dp[i][j][0] = dp[i][j-1][0]*(1-p[i][j]);
				for(int k=1;k<=j;++k)
				{
					dp[i][j][k] += dp[i][j-1][k]*(1-p[i][j]);
					if(k) dp[i][j][k] += dp[i][j-1][k-1]*p[i][j];
				}
			}
			sum[i][0] = dp[i][m][0];
			for(int k=1;k<=m;++k) sum[i][k] = sum[i][k-1] + dp[i][m][k];
			s *= (1-sum[i][0]);
			d *= (sum[i][n-1] - sum[i][0]);
		}
//		printf("%lf %lf\n",s,d[n][0]);
		printf("%.3f\n",s-d);
	}
	return 0;
}

