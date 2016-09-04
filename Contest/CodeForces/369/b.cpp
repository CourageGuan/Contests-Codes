#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 510;
LL a[maxn][maxn];
int n;

bool check(LL s)
{
	LL sum = 0;
	R(i,n)
	{
		sum = 0;
		R(j,n) sum += a[i][j];
		if(sum != s) return 0;
		sum = 0;
		R(j,n) sum += a[j][i];
		if(sum != s) return 0;
	}
	sum = 0;
	R(i,n) sum += a[i][i];
	if(sum != s) return 0;
	sum = 0;
	R(i,n) sum += a[i][n-i-1];
	if(sum != s) return 0;
	return 1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	int x,y;
	R(i,n)
	{
		R(j,n)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j] == 0)
			{
				x = i;
				y = j;
			}
		}
	}
	if(n == 1)
	{
		puts("1");
		return 0;
	}
	LL sumx,sumy,sum;
	sumx = sumy = sum = 0;
	R(i,n) sumx += a[x][i];
	R(i,n) sumy += a[i][y];
	if(sumx != sumy)
	{
		puts("-1");
		return 0;
	}
	int t = (y + 1) %n;
	R(i,n) sum += a[i][t];
	if(sum <= sumx)
	{
		puts("-1");
		return 0;
	}
	a[x][y] = sum - sumx;
	if(!check(sum)) puts("-1");
	else printf("%lld\n",a[x][y]);
	return 0;
}

