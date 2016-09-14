#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;
int a[maxn][maxn],ans[maxn];

int xorGauss(int n,int m)
{
	int r = 0,c = 0;
	for(;r < n && c < m; ++r,++c)
	{
		int p = r;
		for(;p < n;++p) if(a[p][c]) break;
		if(p == n) { --r; continue; };
		swap(a[p],a[r]);

		for(int i=0;i < n;++i)
			if(i != r && a[i][c])
				for(int j=c;j <= m;++j)
					a[i][j] ^= a[r][j];
	}

	for(int i=r; i < n;++i) if(a[i][n]) return -1;

	for(int i=r-1; i >= 0;--i)
		for(int j=0; j < n; ++j)
			if(a[i][j]) { ans[j] = a[i][n]; break; }
	return r;
}

char s[10][10];

int main()
{
//	freopen("test.txt","r",stdin);
	int n = 30,m = 30;
	for(int i=0;i<5;++i)
	{
		scanf("%s",s[i]);
		for(int j=0;j<6;++j)
		{
			int id = i*6+j;
			a[id][30] = '1' - s[i][j];
			a[id][id] = 1;
			if(i-1 >= 0) a[id][(i-1)*6+j] = 1;
			if(i+1 < 5) a[id][(i+1)*6+j] = 1;
			if(j-1 >= 0) a[id][i*6+j-1] = 1;
			if(j+1 < 6) a[id][i*6+j+1] = 1;
		}
	}
	xorGauss(n,m);
	int cnt = 0;
	for(int i=0;i<30;++i) if(ans[i]) ++cnt;
	printf("%d\n",cnt);
	for(int i=0;i<5;++i)
		for(int j=0;j<6;++j)
		{
			int id = i*6 + j;
			if(ans[id]) printf("%d %d\n",i+1,j+1);
		}
	return 0;
}
