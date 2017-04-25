#include<stdio.h> 
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const LL mod = 1e8 + 7;
const int maxn = 1010;

int n;
int G[maxn][maxn];
LL d[2][maxn];

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

void init()
{
	for(int i=1;i<=1000;++i)
	{
		for(int j=1;j<=i;++j)
			G[i][j] = gcd(i,j);
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int cur = 0;
		scanf("%d",&n);
		memset(d,0,sizeof d);
		for(int i=0;i<n;++i)
		{
			cur ^= 1;
			memcpy(d[cur],d[cur^1],sizeof (d[0]));
			int x;
			scanf("%d",&x);
			for(int j=1;j<=1000;++j)
			{
				int t = G[max(j,x)][min(j,x)];
				d[cur][t] = (d[cur][t] + d[cur^1][j]) %mod;
			}
			++d[cur][x];
		}
		LL ans = 0;
		for(int i=1;i<=1000;++i) ans = (ans + d[cur][i]*i%mod)%mod;
		printf("%I64d\n",ans);
	}
	return 0;
}

