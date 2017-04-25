#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;
typedef int Matrix[maxn][maxn];

int a[maxn],n,T;

void Mul(Matrix a,Matrix b,Matrix c)
{
	Matrix res;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			res[i][j] = -INF;
			for(int k=0;k<n;++k)
			{
				if(a[i][k] > -INF && b[k][j] > -INF)
					res[i][j] = max(res[i][j],a[i][k]+b[k][j]);
			}
		}
	memcpy(c,res,sizeof res);
}

void Pow(Matrix A,int n,Matrix c)
{
	Matrix res,a;
	memcpy(a,A,sizeof(a));
	memset(res,0,sizeof res);

	while(n)
	{
		if(n&1) Mul(res,a,res);
		n>>=1;
		Mul(a,a,a);
	}
	memcpy(c,res,sizeof res);
}

int main()
{
	//freopen("test.txt","r",stdin);
	Matrix d,res;
	scanf("%d %d",&n,&T);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(a[j] < a[i]) d[i][j] = -INF;
			else
			{
				d[i][j] = 1;
				for(int k=0;k<j;++k)
				{
					if(a[k] <= a[j]) d[i][j] = max(d[i][j],d[i][k]+1);
				}
			}
//			printf("%d %d %d\n",i,j,d[i][j]);
		}
	}
	Pow(d,T,res);
	int ans = 0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			ans = max(ans,res[i][j]);

	printf("%d\n",ans);
	return 0;
}
