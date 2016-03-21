#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod = 1e9 +7;
const int maxn = 110;
int n,N,b,k,x;
int cnt[12];

struct Matrix
{
	LL m[maxn][maxn];

	void clear()
	{
		memset(m,0,sizeof m);
	}

	void init()
	{
		memset(m,0,sizeof m);
		for(int i=0;i<n;++i) m[i][i]=1;
	}

	void print()
	{
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				printf("%d ",m[i][j]);
			puts("");
		}
	}

	Matrix operator+(const Matrix rhs) const
	{
		Matrix t;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				t.m[i][j] = (m[i][j] + rhs.m[i][j]) % mod;
		return t;
	}

	Matrix operator*(const Matrix rhs) const
	{
		Matrix c;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				c.m[i][j] = 0;
				for(int k=0;k<n;++k)
					c.m[i][j] = (c.m[i][j] + m[i][k] * rhs.m[k][j]) % mod;
			}
		return c;
	}

	Matrix operator^(int n) const
	{
		Matrix a,b;
		a = *this;
		b.init();
		while(n)
		{
			if(n&1) b = b*a;
			n>>=1;
			a = a*a;
		}
		return b;
	}


} M,A;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d %d",&N,&b,&k,&x);
	n = x;
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<N;++i)
	{
		int x;
		scanf("%d",&x);
		++cnt[x];
	}
	M.clear();
	for(int j=0;j<x;++j)
	{
		for(int z=1;z<=9;++z)
		{
			M.m[(j*10 + z)%x][j] += cnt[z];
		}
	}
	A.clear();
	A.m[0][0] = 1;
	M = M^b;
	A = M*A;
	printf("%lld\n",A.m[k][0]);
	return 0;
}


