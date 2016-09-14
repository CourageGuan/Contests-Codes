#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 65537 + 10;
LL d[63][maxn];
int bit[63];
LL n,k;

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	R(z,T)
	{
		scanf("%lld %lld",&n,&k);
		fill(d,0);
		fill(bit,0);
		for(int i=60;i>=0;--i) bit[i] = n&1,n>>=1;
		int l = 0;
		R(i,60) if(bit[i]) {l = i; break; }
		LL x = 0;
		F(i,l,60)
		{
			if(bit[i]) d[i][3*x%k]++;
			x = (3*x+bit[i])%k;
			R(j,k)
			{
				d[i+1][3*j%k] += d[i][j];
				d[i+1][(3*j+1)%k] += d[i][j];
			}
		}
		d[60][x]++;
		d[60][0]--;

		LL res = 0;
		R(i,k) res ^= d[60][i];
		printf("%lld\n",res);
	}
	return 0;
}
