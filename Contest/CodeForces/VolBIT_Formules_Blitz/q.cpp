#include<cstdio>
#include<cmath>
using namespace std;

#define P(x) (x*x*x)
const double pi = acos(-1.0);

int main()
{
	double l3,l4,l5;
	scanf("%lf%lf%lf",&l3,&l4,&l5);
	double v3,v4,v5;
	v3 = sqrt(2)/12*P(l3);
	v4 = sqrt(2)/6*P(l4);
	v5 = 5*tan(54.0/180*pi)*sqrt(1-1/(4*cos(54.0/180*pi)*cos(54.0/180*pi)))/12*P(l5);
	printf("%.12f\n",v3+v4+v5);
	return 0;
}
