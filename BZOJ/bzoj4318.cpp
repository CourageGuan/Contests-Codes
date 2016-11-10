#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n;
double p[maxn],f[maxn],e1[maxn],e2[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lf",p+i);

	for(int i=1;i<=n;++i)
	{
		e1[i] = (e1[i-1] + 1)*p[i];
		e2[i] = (e2[i-1] + 2*e1[i-1] + 1)*p[i];
		f[i] = f[i-1] + (3*e2[i-1] + 3*e1[i-1] + 1)*p[i];
	}
	printf("%.1lf\n",f[n]);
	return 0;
}
