#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const LL INF = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 5010;
LL dp[2][maxn][3];
LL a[maxn],b[maxn],c[maxn],d[maxn],x[maxn];
int n,s,e;

inline void _min(LL& a,LL b)
{
	if(a > b) a = b;
}

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> s >> e;
	F(i,1,n) scanf("%lld",x+i);
	F(i,1,n) scanf("%lld",a+i);
	F(i,1,n) scanf("%lld",b+i);
	F(i,1,n) scanf("%lld",c+i);
	F(i,1,n) scanf("%lld",d+i);
	fill(dp,INF);

	int p = 0;

	if(s == 1)
	{
		dp[p][1][1] = d[1] - x[1];
	}
	else if(e == 1)
	{
		dp[p][1][2] = b[1] - x[1];
	}
	else dp[p][1][0] = b[1] + d[1] - 2*x[1];

	F(i,1,n-1)
	{
		p ^= 1;
		fill(dp[p],INF);
		F(j,1,i)
		{
			if(i+1 == s)
			{
				if(dp[p^1][j][0] < INF)
				{
					_min(dp[p][j+1][1],dp[p^1][j][0] - x[i+1] + d[i+1]);
					_min(dp[p][j][1],dp[p^1][j][0] + x[i+1] + c[i+1]);
				}

				if(dp[p^1][j][2] < INF)
				{
					_min(dp[p][j][0],dp[p^1][j][2] - x[i+1] + d[i+1]);
					_min(dp[p][j-1][0],dp[p^1][j][2] + x[i+1] + c[i+1]);
				}
			}
			else if(i+1 == e)
			{
				if(dp[p^1][j][0] < INF)
				{
					_min(dp[p][j][2],dp[p^1][j][0] + x[i+1] + a[i+1]);
					_min(dp[p][j+1][2],dp[p^1][j][0] - x[i+1] + b[i+1]);
				}

				if(dp[p^1][j][1] < INF)
				{
					_min(dp[p][j-1][0],dp[p^1][j][1] + x[i+1] + a[i+1]);
					_min(dp[p][j][0],dp[p^1][j][1] - x[i+1] + b[i+1]);
				}
			}
			else
			{
				R(k,3)
				{
					if(dp[p^1][j][k] >= INF) continue;

					if(!(k == 1 && j == 1)) _min(dp[p][j][k],dp[p^1][j][k] + c[i+1] + b[i+1]);
					if(!(k == 2 && j == 1)) _min(dp[p][j][k],dp[p^1][j][k] + d[i+1] + a[i+1]);

					_min(dp[p][j-1][k],dp[p^1][j][k] + 2*x[i+1] + c[i+1] + a[i+1]);
					_min(dp[p][j+1][k],dp[p^1][j][k] - 2*x[i+1] + b[i+1] + d[i+1]);
				}
			}
		}
	}
	printf("%lld\n",dp[p][0][0]);
	return 0;
}
