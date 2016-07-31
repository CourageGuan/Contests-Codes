#include<cstdio>
#include<cmath>

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		printf("%.11lf\n",n - n*pow(1.0*(n-1)/n,m));
	}
	return 0;
}
