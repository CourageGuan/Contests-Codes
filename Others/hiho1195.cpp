#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
const int maxn = 1010;
double a[maxn][maxn],ans[maxn];
bool freeX[maxn];
int n,m;

void getAns(int n,int m,int r)
{
	for(int i = r-1;i >= 0; --i)
		for(int j = 0;j < m; ++j)
		{
			if(fabs(a[i][j]) < eps) continue;
			ans[j] = a[i][m];
			for(int k = j+1; k < m; ++k)
				ans[j] -= a[i][k]*ans[k];
			ans[j] /= a[i][j];
			break;
		}
}


int gauss(int n,int m)
{
	for(int i=0;i<m;++i) freeX[i] = 0;
	int r = 0,c = 0;
	for(;r < n && c < m; ++r,++c)
	{
		int maxR = r;
		for(int i = r+1;i < n; ++i)
			if(fabs(a[i][c]) > fabs(a[maxR][c])) maxR = i;
		if(r != maxR) swap(a[r],a[maxR]);
		if(fabs(a[r][c]) < eps) { --r,freeX[c] = 1; continue; } 

		for(int i = r+1;i < n; ++i)
		{
			if(fabs(a[i][c]) > eps)
			{
				double delta = a[i][c]/a[r][c];
				for(int j=c;j<=m;++j) a[i][j] -= delta*a[r][j];
			}
		}
	}
	for(int i = r;i < n; ++i) if(fabs(a[i][m]) > eps) return -1;

	return r;
}


int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d%d",&m,&n) == 2)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<=m;++j)
				scanf("%lf",&a[i][j]);
		int r = gauss(n,m);
		if(r == -1)
			puts("No solutions");
		else if(r < m)
			puts("Many solutions");
		else
		{
			getAns(n,m,r);
			for(int i=0;i<m;++i) printf("%d\n",(int)round(ans[i]));
		}
	}
	return 0;
}
