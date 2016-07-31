#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int R,C;

const double eps = 1e-6;
double d[maxn][maxn];
double p[maxn][maxn][3];

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d",&R,&C) == 2)
	{
		for(int i=1;i<=R;++i)
			for(int j=1;j<=C;++j)
				for(int k=0;k<3;++k)
					scanf("%lf",&p[i][j][k]);
		d[R][C] = 0;
		for(int i=R;i>=1;--i)
			for(int j=C;j>=1;--j)
			{
				if(i == R && j == C) continue;
				double t = 1-p[i][j][0];
				if(t < eps) continue;
				d[i][j] = p[i][j][1]*d[i][j+1]/t + p[i][j][2]*d[i+1][j]/t + 2/t;
			}
		printf("%.3lf\n",d[1][1]);
	}
	return 0;
}
