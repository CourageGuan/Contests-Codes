//区间dp 四边形不等式优化
#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;

#define POW(a) ((a)*(a))

const int maxn = 10010;
const int maxm = 5010;
const int INF = 0x3f3f3f3f;
int n,m;

int save[maxn];
int d[maxm][maxn],K[maxm][maxn];



int main()
{
    //freopen("test.txt","r",stdin); 
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;++kase)
	{
		scanf("%d %d",&n,&m);

		for(int i=1;i<=n;++i) scanf("%d",save+i);

		if(n<=m) 
		{
			printf("Case %d: %d\n",kase,0);
			continue;
		}

		sort(save+1,save+1+n);

		for(int i=0;i<=m;++i)
		{
			K[i][i] = i;
			d[i][i] = 0;
		}

		for(int L=1;L<=n-m;++L)
		{
			int j;
			d[0][L] = INF;
			for(int i=1; (j=i+L)<=n && i<=m; ++i)
			{

				int &ans = d[i][j];
				ans = INF;

				if(i+1>m) K[i+1][j] = j;

				for(int k=K[i][j-1] ; k<=K[i+1][j]; ++k)
				{
					int t=d[i-1][k-1]+POW(save[j]-save[k]);
					if(ans>t)
					{
						K[i][j] = k;
						ans = t;
					}
				}
			}
		}

		printf("Case %d: %d\n",kase,d[m][n]);
	}
	return 0;
}

