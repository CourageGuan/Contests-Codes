#include <bits/stdc++.h> 
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

LL d[55][3000];
int n,A;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&A);
	d[0][0] = 1;
	F(i,1,n)
	{
		int x;
		scanf("%d",&x);
		for(int j=i;j>0;--j)
		{
			for(int k=n*A;k-x>=0;--k)
			{
				d[j][k] += d[j-1][k-x];
			}
		}
	}
	LL ans = 0;
	F(i,1,n) ans += d[i][i*A];
	printf("%lld\n",ans);
	return 0;
}
