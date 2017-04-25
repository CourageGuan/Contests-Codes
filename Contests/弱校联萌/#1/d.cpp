//直接拿分布列搞
//发现每个人跑完的时间满足二项分布
//最后枚举每个人跑完的时间的概率，然后再依次乘上其他人跑完时间比他大的概率
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long LL;

const int maxm = 55;
const int maxn = 110;
LL C[maxm][maxm];
double base[maxn][maxm],add[maxn][maxm];
int p[maxn],t[maxn],v[maxn];
int m,n;

void init()
{
	C[1][0] = C[1][1] = 1;
	for(int i=2;i<=50;++i)
	{
		C[i][0] = 1;
		for(int j=1;j<=i;++j)
		{
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}
}


int main()
{
	init();
	//freopen("test.txt","r",stdin);
	int n,m,L;
	while(scanf("%d %d %d",&n,&m,&L)==3)
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%d %d %d",p+i,t+i,v+i);
			double q = (double)p[i]/100;
			base[i][0] = (double)L/v[i];
			add[i][0] = pow(1-q,m);
			for(int j=1;j<=m;++j)
			{
				add[i][j] = add[i][j-1] + C[m][j]*pow(q,j)*pow(1-q,m-j);
				base[i][j] = base[i][j-1] + t[i];
			}
		}
/*		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=m;++j)
				printf("%lf %lf\n",base[i][j],add[i][j]);
			puts("");
		}
*/
		for(int i=1;i<=n;++i)
		{
			double res = 0;
			for(int j=0;j<=m;++j)
			{
				double cur = add[i][j] - (j?add[i][j-1]:0);
				double now = base[i][j];
//				printf("%lf %lf\n",cur,now);
				for(int k=1;k<=n;++k)
				{
					if(k==i) continue;
					int d = upper_bound(base[k],base[k]+m,now) - base[k];
		//			printf("%d\n",d);
					if(base[k][d]<=now) ++d;
					if(d==0)
					{
						cur *= add[k][m];
					}
					else cur *= add[k][m] - add[k][d-1];
				}
				res += cur;
			}
			printf("%lf\n",res);
		}
	}
	return 0;
}


