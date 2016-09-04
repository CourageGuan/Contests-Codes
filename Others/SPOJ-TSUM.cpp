#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const double pi = acos(-1.0);
const int maxn = 4e4 + 10;

struct Complex
{
    double real,imag;
    Complex(double r = 0,double i = 0):real(r),imag(i) {}

    Complex operator + (const Complex& A)
    {
        return Complex(real+A.real,imag+A.imag);
    }
    Complex operator - (const Complex& A)
    {
        return Complex(real-A.real,imag-A.imag);
    }
    Complex operator * (const Complex& A)
    {
        return Complex(real*A.real-imag*A.imag,imag*A.real+real*A.imag);
    }
};


void rader(Complex F[],int len)
{
    int j = len/2;
    for(int i = 1;i < len-1;++i)
    {
        if(i < j) swap(F[i],F[j]);
        int k = len/2;
        while(j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k) j += k;
    }
}


void FFT(Complex F[],int len,int op) //op = -1为IDFT
{
    rader(F,len);
    for(int h = 2;h <= len;h <<= 1)
    {
        Complex wn(cos(op*2*pi/h),sin(op*2*pi/h));
        for(int j = 0;j < len;j += h)
        {
            Complex E(1,0);
            for(int k = j;k < j+h/2;++k)
            {
                Complex u = F[k];
                Complex v = E*F[k+h/2];
                F[k] = u+v;
                F[k+h/2] = u-v;
                E = E*wn;
            }
        }
    }
    if(op == -1)
        for(int i = 0;i < len;++i)
            F[i].real /= len;
}

int n;
LL x[3][maxn<<2];
Complex x1[maxn<<2],x2[maxn<<2],x3[maxn<<2];

int main()
{
	//freopen("test.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		R(i,maxn<<2) 
		{
			x1[i].real = x2[i].real = x3[i].real = 0;
			x1[i].imag = x2[i].imag = x3[i].imag = 0;
		}
		fill(x,0);
		int len = 0;
		R(i,n)
		{
			int s;
			scanf("%d",&s);
			s += 20000;
			x[0][s]++;
			x[1][2*s]++;
			x[2][3*s]++;
			len = max(3*s,len);
		}
		int m = 1;
		while(m < len) m <<= 1;
		F(i,0,m) x1[i].real = x[0][i],x2[i].real = x[1][i];
		FFT(x1,m,1);
		FFT(x2,m,1);
		F(i,0,m) x3[i] = x1[i]*(x1[i]*x1[i] - x2[i]*Complex(3,0));
		FFT(x3,m,-1);
		F(i,0,m)
		{
			LL res = ((LL)(x3[i].real+0.5)+2*x[2][i])/6;
			if(res > 0) printf("%d : %lld\n",i - 60000,res);
		}
	}
	return 0;
}
