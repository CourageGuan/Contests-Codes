#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long LL;
const int S = 22;

LL mul_mod(LL a,LL b,LL mod)
{
	a %= mod;
	b %= mod;

	LL res = 0;
	while(b)
	{
		if(b&1) res = (res+a) % mod;
		a <<= 1;
		if(a>=mod) a %= mod;
		b >>= 1;
	}
	return res;
}

LL pow_mod(LL a,LL n,LL mod)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = mul_mod(res,a,mod);
		a = mul_mod(a,a,mod);
		n>>=1;
	}
	return res;
}

//以a为基 n-1 = x * 2^t   a^(n-1) = 1(mod n)
//验证n是不是合数
bool check(LL a,LL n,LL x,LL k)
{
	LL res = pow_mod(a,x,n);
	LL last = res;
	for(int i=0;i<k;++i)
	{
		res = mul_mod(res,res,n);
		if(res == 1 && last != 1 && last != n-1) return true;
		last = res;
	}
	if(res!=1) return true;
	return false;
}

bool miller_rabin(LL n)
{
	if(n == 2) return 1;
	if(n<2 || !(n&1)) return 0;
	int k = 0;
	LL x;
	// 将n分解为 x*2^k
	x = n-1;
	while(!(x&1)) 
	{
		++k; x>>=1; 
	}
	for(int i=0;i<S;++i)
	{
		LL a = rand()%(n-1) + 1;	
		if(check(a,n,x,k)) return 0;
	}
	return 1;
}
/* pollard_rho */

LL fac[100];
int tot;

LL gcd(LL a,LL b)
{
	if(a == 0) return 1;
	if(a<0) return gcd(-a,b);

	while(b)
	{
		LL t = a%b;
		a = b;
		b = t;
	}
	return a;
}

LL pollard_rho(LL n,LL c)
{
	LL i = 1,k=2;
	LL x = rand()%n;
	LL y = x;
	while(1)
	{
		++i;
		x = (mul_mod(x,x,n)+c) % n;
		LL d = gcd(y-x,n);
		if(d!=1 && d!=x) return d;
		if(y == x) return n;
		if(i == k) { y=x; k<<=1; }
	}
	return n;
}

void findfac(LL n)
{
	if(miller_rabin(n))
	{
		fac[tot++] = n;
		return ;
	}
	LL p = n;
	while(p >= n) p = pollard_rho(p,rand()%(n-1)+1);
	findfac(p);
	findfac(n/p);
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL n;
		scanf("%lld",&n);
		if(miller_rabin(n)) puts("Prime");
		else
		{
			tot = 0;
			findfac(n);
			LL ans = fac[0];
			for(int i=1;i<tot;++i) ans = min(ans,fac[i]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}

