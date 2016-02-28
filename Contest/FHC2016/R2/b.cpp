#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 3010;
long double C[maxn][maxn];
long double d[maxn];
long double re[maxn][maxn],sum[maxn][maxn];
int n,k;
long double p;

void init(int n)
{
	for(int i = 0;i <= n;++i)
	{
		C[i][0] = 1;
		for(int j = 1;j <= i;++j) C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
}

long double solve()
{
	if(n<k) return 0;

	for(int t=k;t<=n;++t)
	{
		long double pa = pow(p,k),pb = pow(1-p,t-k);
		for(int i=k;i<=t;++i)
		{
			re[t][i] = C[t][i]*pa*pb;
			pa *= p;
			pb /= 1-p;
		}
		sum[t][t] = re[t][t];
		for(int i=t-1;i>=k;--i)
		{
			sum[t][i] = sum[t][i+1] + re[t][i];
		}
	}
	for(int i=0;i<=n;++i) d[i] = 0;
	for(int i=k;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			d[j] = max(d[j],d[j-i]+sum[i][k]);
		}
	}
	return d[n];
}

int main()
{
	//freopen("test.txt","r",stdin);
    freopen("carnival_coins.txt","r",stdin);
	freopen("ans_b.txt","w",stdout);
	init(maxn-5);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d %d %Lf",&n,&k,&p);
		printf("Case #%d: %.10Lf\n",z,solve());
	}
	return 0;
}
