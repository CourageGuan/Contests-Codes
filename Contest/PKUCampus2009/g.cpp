#include<cstdio>
#include<cmath>
using namespace std;
typedef double DB;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const DB pi = acos(-1.0);
DB S;

DB geth(DB r)
{
	return sqrt((S/pi/r - 2*r)*(S/pi/r));
}

int main()
{
//	freopen("test.txt","r",stdin);
	while(~scanf("%lf",&S))
	{
		DB l = 0.01,r = sqrt(S/pi/2),V,R,H;
		F(i,0,1000)
		{
			DB mid = (l+r)/2,mmid = (mid + r)/2;
			DB h1 = geth(mid),h2 = geth(mmid);
			if(mid*mid*h1 > mmid*mmid*h2)
			{
				R = mid;
				H = h1;
				r = mmid;
			}
			else
			{
				R = mmid;
				H = h2;
				l = mid;
			}
		}
		V = pi*R*R*H/3;
		printf("%.2f\n%.2f\n%.2f\n",V,H,R);
	}
	return 0;
}
