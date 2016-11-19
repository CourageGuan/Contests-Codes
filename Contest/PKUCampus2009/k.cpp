#include<cstdio>
using namespace std;
typedef double DB;
typedef unsigned long long ULL;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
const int maxn = 5010;
ULL f[maxn],d[maxn];

void init()
{
	f[0] = f[1] = f[2] = 1;
	d[0] = d[1] = d[2] = 1;
	F(i,3,maxn-1)
	{
		F(j,2,i-1) d[i] += f[j]*f[i-j+1];
		f[i] = d[i];
		F(j,2,i-2) f[i] += f[j]*d[i-j+1];
	}
}

int main()
{
//	freopen("test.txt","r",stdin);
	init();
	int n;
	while(scanf("%d",&n) == 1) printf("%llu\n",f[n]);
	return 0;
}
