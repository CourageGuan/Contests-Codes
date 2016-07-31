#include<bits/stdc++.h>
using namespace std;

#define mp make_pair

const int maxn = 2016;
const double eps = 1e-5;

int n,m,k;
double p[5],pp[maxn];
double p2,p3,p4;

double d[maxn][maxn];
double c[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d%d%d",&n,&m,&k) == 3)
	{
		for(int i=1;i<=4;++i) scanf("%lf",p+i);
		if(p[4] < eps)
		{
			puts("0.00000");
			continue;
		}
		d[1][1] = p[4]/(1-p[1]-p[2]);
		p2 = p[2]/(1-p[1]);
		p3 = p[3]/(1-p[1]);
		p4 = p[4]/(1-p[1]);
		pp[0] = 1;
		for(int i=1;i<=n;++i) pp[i] = pp[i-1]*p2;
		for(int i=2;i<=n;++i)
		{
			c[1] = p4;
			double cur = c[1];
			for(int j=2;j<=i;++j)
			{
				c[j] = p3*d[i-1][j-1] ;
				if(j <= k) c[j] += p4;
				cur += c[j]*pp[i-j+1];
			}
			d[i][1] = cur/(1-pp[i]);
			for(int j=2;j<=i;++j)
				d[i][j] = p2*d[i][j-1] + c[j];
		}
		printf("%.5lf\n",d[n][m]);
	}
	return 0;
}
