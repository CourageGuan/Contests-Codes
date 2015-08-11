#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;

const int maxn = 62;
int n;
LL d[maxn][2];

inline LL dp()
{
	memset(d,0,sizeof d);
	d[1][1] = 1;
	d[1][0] = 1;
	for(int i=2;i<=n;++i)
	{
		d[i][1] += d[i-1][0];
		d[i][1] -= d[i-2][1];
		d[i][0] += d[i-1][0]+d[i-1][1];
	}
	return d[n][0]+d[n][1]-1;
}


int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&n)==1)
	{
		printf("%I64d\n",dp());
	}
	return 0;
}
