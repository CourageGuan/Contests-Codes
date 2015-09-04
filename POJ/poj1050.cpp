//poj1050 最大/最小 权和矩阵
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;
const int maxn = 710;
const LL INF = 0x3f3f3f3f3f3f3f3f;

LL sum[maxn][maxn],arr[maxn];

LL find_max(int a[maxn][maxn],int n,int m)
{
	if(n == 0 || m == 0) return 0;
	int i,j,up,down;
	LL res = -INF;
	memset(sum,0,sizeof sum);

	for(i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			sum[i][j] = sum[i-1][j] + a[i][j];

	arr[0] = 0;

	for(up = 1;up<=n;++up)
		for(down = up;down<=n;++down)
		{
			for(i=1;i<=m;++i)
				arr[i] = arr[i-1] + (sum[down][i] - sum[up-1][i]);
			LL mini = 0;
			for(i=1;i<=m;++i)
			{
				res = max(res,arr[i] - mini);
				mini = min(mini,arr[i]);
			}
		}
	//if(res<0) return 0;
	return res;
}

int find_min(int a[maxn][maxn],int n,int m)
{
	int i,j;
	for(i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j] = -a[i][j];
	LL res = -find_max(a,n,m);
	for(i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j] = -a[i][j];
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	int m[maxn][maxn];
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&m[i][j]);
		printf("%d\n",find_max(m,n,n));
	}
	return 0;
}
