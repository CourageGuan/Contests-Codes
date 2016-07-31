#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<n;++i)

const int maxn = 310;
const int maxm = 33;
const int INF = 0x3f3f3f3f;

int n,m;

int d[maxm][maxn],cost[maxn][maxn],x[maxn],s[maxm][maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	while(~scanf("%d %d",&n,&m))
	{
		R(i,n) scanf("%d",x+i+1);
		F(i,1,n)
			F(j,i+1,n)
				cost[i][j] = cost[i][j-1] + x[j] - x[(i+j)>>1];
		memset(d,INF,sizeof d);
		F(i,1,n)
		{
			d[1][i] = cost[1][i];
			s[1][i] = 0;
		}
		F(i,2,m)
		{
			s[i][n+1] = n;
//			F(j,i+1,n)
			for(int j=n;j>i;--j)
			{
		//		printf("%d %d %d %d\n",i,j,s[i-1][j],s[i][j+1]);
				F(k,s[i-1][j],s[i][j+1])
				{
					if(d[i][j] > d[i-1][k] + cost[k+1][j])
					{
						d[i][j] = d[i-1][k] + cost[k+1][j];
						s[i][j] = k;
					}
				}
				//printf("%d %d %d\n",j,i,s[i][j]);
			}
		}
		printf("%d\n",d[m][n]);
	}
	return 0;
}

