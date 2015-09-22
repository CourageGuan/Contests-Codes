//背包，注意有负值
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;
const int maxn = 1010;
LL d[maxn][maxn*2];


int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		int n,p;
		scanf("%d %d",&n,&p);
		memset(d,0,sizeof d);
		d[0][p] = 1;
		for(int i=1;i<=n;++i)
		{
			int x;
			scanf("%d",&x);
			for(int j=-p+1;j<p;++j)
			{
				d[i][j+p] = d[i-1][j+p];
			}
			for(int j=-p+1;j<p;++j)
			{
				int t = (j+x)%p;
				d[i][t+p] = (d[i][t+p] + d[i-1][j+p]) % mod;
			}
		}
		printf("%lld\n",d[n][p]);
	}
	return 0;
}
