#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1010;
int n,m;
double d[maxn][maxn],p;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	d[0][0] = 1;
	for(int i=1;i<=n;++i)
	{
	   	scanf("%lf",&p);
		for(int j=0;j<=min(i,m);++j)
		{
			if(j) d[i][j] += d[i-1][j-1]*p;
			d[i][j] += d[i-1][j]*(1-p);
		}
	}
	printf("%.5lf\n",d[n][m]);
	return 0;
}
