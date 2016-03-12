#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxn = 2;
LL n,p,a,b,mod;

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
		for(int i=0;i<maxn;++i) m[i][i]=1;
	}

	void print()
	{
		for(int i=0;i<maxn;++i){
			for(int j=0;j<maxn;++j)
				printf("%d ",m[i][j]);
			puts("");
		}
	}

	Matrix operator+(const Matrix rhs) const
	{
		Matrix t;
		for(int i=0;i<maxn;++i)
			for(int j=0;j<maxn;++j)
				t.m[i][j] = (m[i][j] + rhs.m[i][j]) % mod;
		return t;
	}

	Matrix operator*(const Matrix rhs) const
	{
		Matrix c;
		for(int i=0;i<maxn;++i)
			for(int j=0;j<maxn;++j)
			{
				c.m[i][j] = 0;
				for(int k=0;k<maxn;++k)
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


} ;

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

LL qpow(LL a,int n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a%mod;
		a = a*a %mod;
		n>>=1;
	}
	return res;
}


LL solve()
{
	if(n == 1) return a%p;
	if(n == 2) return b%p;
	if(n == 3) return a*b%p;
	--n;
	mod = p;
	if(n <= 31)
	{
		int p = 1,q = 1,t;
		for(int i=0;i<n-2;++i)
		{
			t = q;
			q = p+q;
			p = t;
		}
		return (LL)qpow(a,p)*qpow(b,q)%mod;
	}
	else
	{
		int phi = 0;
		for(int i=1;i<=p;++i) if(gcd(i,p)==1) ++phi;
		mod = phi;
		Matrix t,r;
		t.clear();
		r.clear();
		t.m[0][0] = 1;
		t.m[0][1] = 1;
		t.m[1][0] = 1;
		t = t^(n-2);
		r.m[0][0]  = r.m[1][0] = 1;
		r = t*r;
		mod = p;
		return (LL)qpow(a,r.m[1][0]+phi)*qpow(b,r.m[0][0]+phi)%mod;
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&p,&n);
		printf("Case #%d: %lld\n",z,solve());
	}
	return 0;
}


