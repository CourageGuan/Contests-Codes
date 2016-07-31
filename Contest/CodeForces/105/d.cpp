#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a));

const int maxn = 1010;

DB d[maxn][maxn];


int main()
{
//	freopen("test.txt","r",stdin);
	int w,b;
	cin >> w >> b;
	d[w][b] = 1;
	double res = 0;
	for(int i=w;i>=1;--i)
	{
		for(int j=b;j>=0;--j)
		{
			if((i+j)%3 == (w+b)%3)
			{
				if(j) d[i][j-1] += d[i][j]*j/(i+j);
				res += d[i][j]*i/(i+j);
			}
			else if((i+j)%3 == (w+b-1)%3)
			{
				if(j) d[i][j-1] += d[i][j]*j/(i+j);
			}
			else
			{
				if(i) d[i-1][j] += d[i][j]*i/(i+j);
				if(j) d[i][j-1] += d[i][j]*j/(i+j);
			}
		}
	}
	printf("%.12lf\n",res);
	return 0;
}

