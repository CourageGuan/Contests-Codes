#include<bits/stdc++.h>
using namespace std;

int n,k;
const double pi = acos(-1);
double l[22];

int main()
{
	while(scanf("%d %d %lf",&n,&k,&l[0]) == 3)
	{
		double ta = (n-2)*pi/n/2;
		double ans = (n-1)*l[0]+l[0]/2;
		for(int i=1;i<=k;++i)
		{
			l[i] = sin(ta)*l[i-1];
			ans += (n-1)*l[i]+l[i]/2;
		}
		ans -= l[k]/2;
		printf("%.9lf\n",ans);
	}
	return 0;
}
