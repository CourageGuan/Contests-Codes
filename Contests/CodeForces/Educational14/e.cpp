#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 110;
const LL mod = 1e9 + 7;

const int SIZE = maxn;
int n;
LL k,a[maxn];

struct Matrix
{
	LL m[SIZE][SIZE];

	void clear()
	{
		memset(m,0,sizeof m);
	}

	void init()
	{
		memset(m,0,sizeof m);
		for(int i=0;i<SIZE;++i) m[i][i]=1;
	}

	void print()
	{
		for(int i=0;i<SIZE;++i){
			for(int j=0;j<SIZE;++j)
				printf("%lld ",m[i][j]);
			puts("");
		}
	}

	Matrix operator+(const Matrix rhs) const
	{
		Matrix t;
		for(int i=0;i<SIZE;++i)
			for(int j=0;j<SIZE;++j)
				t.m[i][j] = (m[i][j] + rhs.m[i][j]) % mod;
		return t;
	}

	Matrix operator*(const Matrix rhs) const
	{
		Matrix c;
		for(int i=0;i<SIZE;++i)
			for(int j=0;j<SIZE;++j)
			{
				c.m[i][j] = 0;
				for(int k=0;k<SIZE;++k)
					c.m[i][j] = (c.m[i][j] + m[i][k] * rhs.m[k][j]) % mod;
			}
		return c;
	}

	Matrix operator^(LL n) const
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


} M;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %lld",&n,&k);
	for(int i=0;i<n;++i) scanf("%lld",a+i);
	if(k == 1)
	{
		printf("%d\n",n);
		return 0;
	}
	M.clear();
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			if(__builtin_popcountll(a[i]^a[j]) %3 == 0)
			{
//				printf("%d %d %lld\n",i,j,a[i]^a[j]);
				M.m[i][j] = 1;
			}
		}
	k -= 1;
	M = M^k;
	LL ans = 0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			ans = (ans + M.m[i][j])%mod;
		}
	printf("%lld\n",ans);
	return 0;
}

