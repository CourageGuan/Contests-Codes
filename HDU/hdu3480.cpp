#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<n;++i)
#define P(n) (1LL*(n)*(n))

const int maxn = 1e4 + 10;
const int maxm = 5010;

int n,m;
int a[maxn],s[maxm][maxn],d[maxm][maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%d %d",&n,&m);	
		F(i,1,n) scanf("%d",a+i);
		if(m >= n)
		{
			printf("Case %d: %d\n",z,0);
			continue;
		}
		sort(a+1,a+1+n);
		memset(d,0x3f,sizeof d);
		F(i,1,n)
		{
			d[1][i] = P(a[i]-a[1]);
			s[1][i] = 0;
		}
		F(i,2,m)
		{
			s[i][n+1] = n;
			for(int j=n;j>i;--j)
			{
//				printf("%d %d %d %d \n",j,i,s[i-1][j],s[i][j+1]);
				F(k,s[i-1][j],s[i][j+1])
				{
					if(d[i][j] > d[i-1][k] + P(a[j]-a[k+1]))
					{
						d[i][j] = d[i-1][k] + P(a[j]-a[k+1]);
						s[i][j] = k;
					}
				}
//				printf("%d %d\n",d[i][j],s[i][j]);
			}
		}
		printf("Case %d: %d\n",z,d[m][n]);
	}
	return 0;
}

