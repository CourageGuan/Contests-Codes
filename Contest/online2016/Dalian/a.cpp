#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int mod = 1e9 + 7;
const int maxn = 4e4 + 10;
int n,tot;
LL ephi[maxn],primes[maxn];
bool vis[maxn];

const int SIZE = 2;
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


} M,A,B,C;

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


void init()
{
	M.clear(); B.clear();
	M.m[0][0] = M.m[0][1] = M.m[1][0] = 1;
	B.m[0][0] = 3;
	B.m[1][0] = 1;

	tot=0; ephi[1]=1;
	for(int i=2;i<maxn;++i){
		if(!vis[i]){
			primes[tot++]=i;
			ephi[i]=i-1;
		}
		for(int j=0;j<tot;++j){
			int t=i*primes[j],p=primes[j];
			if(t>maxn) break;
			vis[t]=1;
			if(i%p==0){
				ephi[t]=ephi[i]*p;
				break;
			}
			else ephi[t]=ephi[i]*(p-1);
		}
	}
}

LL phi(int n){
	if(n < maxn) return ephi[n];
	LL res=n;
	for(int i=0;i<tot;++i){
		LL p = primes[i];
		if(n%p==0){
			res=res/p*(p-1);
			while(n%p==0) n/=p;
		}
		if(n<=1) break;
	}
	if(n>1) res*=res/n*(n-1);
	return res;
}

LL cal(int n)
{
	if(n == 1) return 1;
	C = M^(n-2);
	A = C*B;
	return A.m[0][0];
}

int main()
{
	//freopen("test.txt","r",stdin);
	init();
	while(scanf("%d",&n) == 1)
	{
		if(n == 1)
		{
			puts("2");
			continue;
		}
		LL res = 0;
		for(LL i=1;i*i<=n;++i)
		{
			if(n%i) continue;
			res = (res + cal(i)*phi(n/i)%mod) %mod;
			if(i != n/i)
				res = (res + cal(n/i)*phi(i)%mod)%mod;
		}
		res = res * pow_m(n,mod-2) %mod;
		printf("%lld\n",res);
	}
	return 0;
}
