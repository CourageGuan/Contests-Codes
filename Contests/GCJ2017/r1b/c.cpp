#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 110;
const double INF = 1e12;
int D[maxn][maxn];
LL sum[maxn];
double d[maxn];
int n,q;
int E[maxn],S[maxn],U[maxn],V[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		printf("Case #%d:",z);
		scanf("%d %d",&n,&q);
		for(int i=1;i<=n;++i) scanf("%d %d",E+i,S+i);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&D[i][j]);
		sum[1] = 0;
		for(int i=2;i<=n;++i) sum[i] = sum[i-1] + D[i-1][i];
		for(int i=0;i<q;++i)
		{
			scanf("%d %d",U+i,V+i);
			int t = 0;
			for(int i=0;i<=n;++i) d[i] = INF;
			d[1] = 0;
			for(int i=2;i<=n;++i)
			{
				for(int j=1;j<i;++j)
				{
					LL dis = sum[i] - sum[j];
					if(dis <= E[j]) 
						d[i] = min(d[i],d[j]+1.0*dis/S[j]);
				}
			}
			printf(" %.10lf",d[n]);
		}
		puts("");
	}
	return 0;
}
