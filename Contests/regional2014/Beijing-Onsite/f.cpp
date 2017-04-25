#include<stdio.h>
#include<cstring>

typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 55;
int n,m;
int a[maxn][maxn];
LL d[2][8];

int main()
{
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d %d",&n,&m);
		memset(a,0,sizeof a);
		for(int i=1;i<=m;++i)
		{
			scanf("%d",&a[i][0]);
			for(int j=1;j<=a[i][0];++j)
			{
				int x;
				scanf("%d",&x);
				a[i][x] = 1;
			}
		}
		LL ans = 0;
		for(int i=1;i<=n;++i)
			for(int j=i;j<=n;++j)
				for(int k=j;k<=n;++k)
				{
					memset(d,0,sizeof d);
					int p = 0;
					d[0][0] = 1;
					for(int l=1;l<=m;++l)
					{
						p^=1;
						memcpy(d[p],d[p^1],sizeof d[0]);
						for(int s=0;s<8;++s)
						{
							d[p][s^a[l][i]^(a[l][j]<<1)^(a[l][k]<<2)] = (d[p][s^a[l][i]^(a[l][j]<<1)^(a[l][k]<<2)] + d[p^1][s])%mod;
						}
					}
//					printf("%d %d\n",((i == j && j == k)?6:((i == j || i == k)?3:1)),d[p][7]);
					ans = (ans + d[p][7]*((i != j && j != k)?6:((i == j && i == k)?1:3))) %mod; 
				}
		printf("Case #%d: %I64d\n",z,ans);
	}
	return 0;
}
