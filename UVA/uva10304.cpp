//区间dp + 四边形不等式优化
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define min(a,b) (a>b?b:a)

const int maxn=255;
const int INF=0x3f3f3f3f;

typedef long long LL;

LL d[maxn][maxn],w[maxn];
int save[maxn],K[maxn][maxn];
int n;

/*	
LL dp(int i,int j)
{
	LL &ans = d[i][j];
	if(ans!=-1) return ans;

	ans = INF;

	if(i==j)
	{
		return ans = 0;
	}

	
	for(int k=i;k<=j;++k)
	{
		int res = w[j] - w[i-1] - save[k] ;
		if(k-1>=i) res += dp(i,k-1);  
		if(k+1<=j) res += dp(k+1,j);
		ans = min(ans,res);
	}
	return ans;
}


int main()
{
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;++i) scanf("%d",save+i);

		w[0]=0;
		for(int i=1;i<=n;++i) w[i]=w[i-1]+save[i];

		memset(d,-1,sizeof d);

		printf("%lld\n",dp(1,n));	
	}
	return 0;
}
*/


int main()
{
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;++i) scanf("%d",save+i);

		w[0]=0;
		for(int i=1;i<=n;++i) w[i] = w[i-1] + save[i];

		memset(d,0,sizeof d);

		for(int i=1;i<=n;++i) K[i][i] = i;

		for(int L=2;L<=n;++L)
		{
			int j;
			for(int i=1;(j=i+L-1)<=n;++i)
			{
				LL& res = d[i][j];
				res = INF;
				for(int k=K[i][j-1];k<=K[i+1][j];++k)
				{
					LL t=w[j]-w[i-1]-save[k];
					if(k-1>=i) t+=d[i][k-1];
					if(k+1<=j) t+=d[k+1][j];

					if(t <= res)
					{
						K[i][j] = k;
						res = t;
					}
				}
			}
		}

		printf("%lld\n",d[1][n]);
	}
	return 0;
}

