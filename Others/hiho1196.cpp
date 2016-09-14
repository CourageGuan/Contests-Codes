#include<bits/stdc++.h>
using namespace std;

typedef int LL;

const int maxn = 100;
const LL mod = 2;

LL a[maxn][maxn],ans[maxn];
bool freeX[maxn];

LL pow_m(LL a,LL n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return res;
}

LL inv(LL x)
{
	return pow_m(x,mod-2);
}

LL getAns(LL n,LL m,LL r)
{
	for(LL i = r-1;i >= 0; --i)
		for(LL j = 0;j < m; ++j)
		{
			if(!a[i][j]) continue;
			ans[j] = a[i][m];
			for(LL k = j+1; k < m; ++k)
			{
				ans[j] -= a[i][k]*ans[k];
				if((ans[j] %= mod) < 0) ans[j] += mod;
			}
			ans[j] = ans[j]*inv(a[i][j]) %mod;
			break;
		}
	LL res = 0;
	for(int i = 0;i < m;++i) res += ans[i];
	return res;
}

LL gauss(LL n,LL m)
{
	for(LL i=0;i<m;++i) freeX[i] = 0;
	LL r = 0,c = 0;
	for(;r < n && c < m; ++r,++c)
	{
		LL maxR = r;
		for(LL i = r+1;i < n; ++i)
			if(abs(a[i][c]) > abs(a[maxR][c])) maxR = i;
		if(r != maxR) swap(a[r],a[maxR]);
		if(!a[r][c]) { --r,freeX[c] = 1; continue; } 

		for(LL i = r+1;i < n; ++i)
		{
			if(a[i][c])
			{
				LL delta = a[i][c]*inv(a[r][c]);
				for(LL j=c;j<=m;++j)
				{
				   	a[i][j] -= delta*a[r][j];
					if((a[i][j] %= mod) < 0) a[i][j] += mod;
				}
			}
		}
	}
	for(LL i = r;i < n; ++i) if(a[i][m]) return -1;

	return r;
}

char s[10][10];

int main()
{
//	freopen("test.txt","r",stdin);
	LL n = 30,m = 30;
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
	LL r = gauss(n,m);
	LL res = getAns(n,m,r);
	printf("%d\n",res);
	for(int i=0;i<5;++i)
		for(int j=0;j<6;++j)
		{
			int id = i*6 + j;
			if(ans[id]) printf("%d %d\n",i+1,j+1);
		}
	return 0;
}
