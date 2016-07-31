#include<bits/stdc++.h>
using namespace std;

const int maxn = 300;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
int sum[maxn],e[maxn],n;
int d[maxn][maxn],s[maxn][maxn];


int main()
{
	while(~scanf("%d",&n))
	{
		sum[0] = 0;
		F(i,1,n) scanf("%d",e+i),sum[i] = sum[i-1] + e[i],s[i][i] = i;
		F(l,1,n-1)
		{
			F(i,1,n)
			{
				int j = i+l;
				if(j > n) break;
				d[i][j] = 0x3f3f3f3f;
				F(k,s[i][j-1],s[i+1][j])
				{
					if(d[i][j] > d[i][k-1] + d[k+1][j] + sum[j] - sum[i-1] - e[k])
					{
						d[i][j] = d[i][k-1] + d[k+1][j] + sum[j] - sum[i-1] - e[k];
						s[i][j] = k;
					}
				}
			}
		}
		printf("%d\n",d[1][n]);
	}
	return 0;
}
