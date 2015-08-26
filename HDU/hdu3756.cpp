//三分求极值
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int maxn = 10010;
double X[maxn],Y[maxn];
double INF = 1e10;
double eps = 1e-9;
int n;

double getR(double h)
{
	double R = 0;
	for(int i=0;i<n;++i)
	{
		if(R*(h-Y[i])<h*X[i])
			R = X[i]*h/(h-Y[i]);	
	}
	return R;
}

void solve(double l)
{
	double low = l ,high = INF;
	while(high - low > eps)
	{
		double mid = (low+high)/2;
		double mmid = (mid + high)/2;
		double R0 = getR(mid),R1 = getR(mmid); 
		if(R0*R0*mid < R1*R1*mmid)
		{
			high = mmid;		
		}
		else
		{
			low = mid;		
		}
	}
	printf("%.3lf %.3lf\n",low+eps,getR(low)+eps);
}


int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		double l = 0;
		for(int i=0;i<n;++i)
		{
			double x,y,z;
		   	scanf("%lf%lf%lf",&x,&y,&z);
			X[i] = sqrt(x*x+y*y);
			Y[i] = z;
			l = max(l,z);
		}
		solve(l);
	}
	return 0;
}

