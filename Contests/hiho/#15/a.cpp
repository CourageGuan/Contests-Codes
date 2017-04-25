#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1010;
const int INF = 0x3f3f3f3f;
int pic[maxn][maxn];
int d1[maxn][maxn],d2[maxn][maxn];

inline int gao(int a,int n)
{
	int cnt = 0;
	while(a%n == 0)
	{
		a/=n;
		++cnt;
	}
	return cnt;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&pic[i][j]);
		memset(d1,INF,sizeof d1);
		memset(d2,INF,sizeof d2);

		d1[0][0] = gao(pic[0][0],2);
		d2[0][0] = gao(pic[0][0],5);

		for(int t=1;t<=2*(n-1);++t)
		{
			for(int x=0;x<=min(t,n-1);++x)
			{
				int y = t - x;
				if(pic[x][y] == 0 || y>=n) continue;
				if(x-1 >=0)
				{
					d1[x][y] = min(d1[x][y],d1[x-1][y]+gao(pic[x][y],2));
					d2[x][y] = min(d2[x][y],d2[x-1][y]+gao(pic[x][y],5));
				}
				if(y-1 >= 0)
				{
					d1[x][y] = min(d1[x][y],d1[x][y-1]+gao(pic[x][y],2));
					d2[x][y] = min(d2[x][y],d2[x][y-1]+gao(pic[x][y],5));
				}
			}
		}
		int ans = min(d1[n-1][n-1],d2[n-1][n-1]);
		printf("%d\n",ans);
	}
	return 0;
}


