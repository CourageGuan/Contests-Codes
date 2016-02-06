#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int n,p;
int l[maxn],r[maxn];
double rng[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&p);
	for(int i=0;i<n;++i) scanf("%d %d",l+i,r+i);
	l[n] = l[0]; r[n] = r[0];
	for(int i=0;i<=n;++i)
		rng[i] = (double)((r[i]/p) - ((l[i]-1)/p))/(r[i]-l[i]+1);
	double ans = 0;
	for(int i=1;i<=n;++i)
	{
		//printf("%d %lf\n",i-1,rng[i-1]);
		ans += 2*(rng[i-1]*rng[i] + (1-rng[i-1])*rng[i] + rng[i-1]*(1-rng[i]));
	}
	printf("%.12lf\n",ans*1000);
	return 0;
}
