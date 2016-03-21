#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N = 500005;
const double pi = acos(-1.0);
const double eps = 1e-8;

int len,n;
int save[N];
LL num[N],sum[N];

struct Complex
{
	double r,i;
	Complex(double r=0,double i=0):r(r),i(i) {};
	Complex operator+(const Complex &rhs)
	{
		return Complex(r + rhs.r,i + rhs.i);
	}
	Complex operator-(const Complex &rhs)
	{
		return Complex(r - rhs.r,i - rhs.i);
	}
	Complex operator*(const Complex &rhs)
	{
		return Complex(r*rhs.r - i*rhs.i,i*rhs.r + r*rhs.i);
	}
} F[N];

void rader(Complex F[],int len)	//len = 2^M,reverse F[i] with  F[j] j为i二进制反转
{
	int j = len >> 1;
	for(int i = 1;i < len - 1;++i)
	{
		if(i < j) swap(F[i],F[j]);	// reverse
		int k = len>>1; 
		while(j>=k)
		{
			j -= k;
			k >>= 1;
		}
		if(j < k) j += k;
	}
}

void FFT(Complex F[],int len,int t)
{
	rader(F,len);
	for(int h=2;h<=len;h<<=1)
	{
		Complex wn(cos(-t*2*pi/h),sin(-t*2*pi/h));
		for(int j=0;j<len;j+=h)
		{
			Complex E(1,0);		//旋转因子
			for(int k=j;k<j+h/2;++k)
			{
				Complex u = F[k];
				Complex v = E*F[k+h/2];
				F[k] = u+v;
				F[k+h/2] = u-v;
				E=E*wn;
			}
		}
	}
	if(t==-1)	//IDFT 逆DFT
		for(int i=0;i<len;++i)
			F[i].r /= len;
}

void Conv(Complex F[],int len) //求卷积(多项式乘法)
{
	FFT(F,len,1);
	for(int i=0;i<len;++i) F[i] = F[i]*F[i]; 
	FFT(F,len,-1);
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);

		memset(num,0,sizeof num);
		for(int i=0;i<n;++i)
		{
			scanf("%d",save+i);
			++num[save[i]];
		}

		sort(save,save+n);

		int len1 = save[n-1] + 1;
		len = 1;

		while(len < 2*len1) len <<= 1;

		for(int i=0;i<len1;++i)
		{
		   	F[i] = Complex(num[i],0);
		}

		for(int i=len1;i<len;++i)
		{
			F[i] = Complex(0,0);
		}

		Conv(F,len);

		for(int i=0;i<len;++i)
		{
			num[i] = (LL)(F[i].r+0.5);
		}

		len = 2*save[n-1];
		
		for(int i=0;i<n;++i)
			--num[save[i]+save[i]];	 //remove which two is same

		for(int i=1;i<=len;++i)
		{
			num[i] >>= 1;
		}

		sum[0] = 0;
		for(int i=1;i<=len;++i)
			sum[i] = sum[i-1] + num[i];

		LL all = (LL)n*(n-1)*(n-2)/6,cnt = 0;

		for(int i=0;i<n;++i)
		{
			cnt += sum[len]-sum[save[i]];
			cnt -= (LL)(n-i-1)*i;
			cnt -= (n-1);
			cnt -= (LL)(n-i-1)*(n-i-2)/2;
		}

//		printf("%lld %lld\n",cnt,all);

		printf("%.7f\n",(double)cnt/all);
	}
	return 0;
}
