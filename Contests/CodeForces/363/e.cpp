#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,k;
const double eps = 1e-3;
double d[1<<20],p[22],ans[22];

int main()
{
	//freopen("test.txt","r",stdin);
	int tot = 0;
	cin >> n >> k;
	for(int i=0;i<n;++i) scanf("%lf",p+i);
	d[0] = 1;
	for(int i=1;i<(1<<n);++i)
	{
		double s = 0;
		for(int j=0;j<n;++j)
			if(i&(1<<j)) s += p[j];

		if(__builtin_popcount(i) > k) continue;

		for(int j=0;j<n;++j)
		{
			if(1-s+p[j] < eps) continue;
			if(i&(1<<j))
			{
				d[i] += d[i^(1<<j)]*p[j]/(1-s+p[j]);
				ans[j] += d[i^(1<<j)]*p[j]/(1-s+p[j]);
			}
		}
	}
	for(int i=0;i<n;++i) printf("%.10lf ",ans[i]);
	puts("");
	return 0;
}
