#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;

const LL mod = 1e9 + 7;
const int SIZE = 2;

LL k[3],A[3],x,y,z,a[3],b[3],c[3];

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

	Matrix operator*(const Matrix rhs) const
	{
		Matrix t;
		t.clear();
		for(int k=0;k<SIZE;++k)
			for(int i=0;i<SIZE;++i)
			{
				if(m[i][k])
				{
					for(int j=0;j<SIZE;++j)
						t[i][j] = (t[i][j] + m[i][k]*rhs.m[k][j]%mod)%mod;
				}
			}
		return t;
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

	LL *const operator[](int i)
	{
		return m[i];
	}


} m,M;

LL pow_m(LL a,LL n)
{
	LL res = 1;
	a %= mod;
	while(n)
	{
		if(n&1) res = res*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return res;
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%lld %lld",k+1,k+2);
	m.clear();
	m[0][0] = k[1];
	m[0][1] = k[2];
	m[1][0] = 1;
	scanf("%lld%lld%lld%lld",&x,&y,A+1,A+2);
	c[1] = A[1], c[2] = A[2];
	M = m^(x-2);
	a[1] = M[0][0],b[1] = M[0][1];
	M = m^(y-2);
	a[2] = M[0][0],b[2] = M[0][1];
	M.clear();
	M[0][0] = (b[1]*c[2]%mod - b[2]*c[1]%mod + mod)%mod*pow_m((a[2]*b[1]%mod-a[1]*b[2]%mod+mod)%mod,mod-2)%mod;
	M[1][0] = (a[1]*c[2]%mod - a[2]*c[1]%mod + mod)%mod*pow_m((a[1]*b[2]%mod-a[2]*b[1]%mod+mod)%mod,mod-2)%mod;
	scanf("%lld",&z);
	M = (m^(z-2))*M;
	printf("%lld\n",M[0][0]);
	return 0;
}
