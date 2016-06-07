#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 20;
const int SIZE = 2;
int n,x[maxn];
double p;


struct Matrix
{
	double m[SIZE][SIZE];

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
				t.m[i][j] = (m[i][j] + rhs.m[i][j]);
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
					c.m[i][j] = (c.m[i][j] + m[i][k] * rhs.m[k][j]);
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


} A,B;

void init()
{
	A.clear();
	A.m[0][0] = p;
	A.m[1][0] = 1;
	B.clear();
	B.m[0][0] = p;
	B.m[0][1] = 1-p;
	B.m[1][0] = 1;
}

double cal(int n)
{
	if(n <= 1) return 1;
	Matrix t = (B^(n-2))*A;
	return t.m[0][0];
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(cin >> n >> p)
	{
		init();
		double ans = 1;
		for(int i=1;i<=n;++i)
			scanf("%d",x+i);
		x[0] = 0;
		sort(x+1,x+n+1);
		for(int i=1;i<=n;++i)
			ans *= (1-cal(x[i]-x[i-1]));
		printf("%.7f\n",ans);
	}
	return 0;
}
