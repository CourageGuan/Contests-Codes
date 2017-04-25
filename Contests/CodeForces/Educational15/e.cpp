#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct P
{
	int f;
	int mn;
	LL sum;
};

typedef P Matrix[maxn];

int n;
Matrix c;

void m_mul(Matrix a,Matrix b,Matrix res)
{
	R(i,n)
	{
		c[i].f = b[a[i].f].f;
		c[i].sum = a[i].sum + b[a[i].f].sum;
		c[i].mn = min(a[i].mn,b[a[i].f].mn);
	}
	memcpy(res,c,sizeof c);
}

void m_pow(Matrix A,LL m,Matrix res)
{
	Matrix a,r;

	memcpy(a,A,sizeof(a));
	R(i,n)
	{
		r[i].f = i;
		r[i].sum = 0;
		r[i].mn = INF;
	}

	while(m)
	{
		if(m&1) m_mul(r,a,r);
		m >>= 1;
		m_mul(a,a,a);
	}
	memcpy(res,r,sizeof r);
}

LL k;
int f[maxn],w[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> k;
	Matrix m;
	R(i,n) scanf("%d",f+i),m[i].f = f[i];
	R(i,n) scanf("%d",w+i),m[i].sum = m[i].mn = w[i];
	m_pow(m,k,m);
	R(i,n) printf("%lld %d\n",m[i].sum,m[i].mn);
	return 0;
}


