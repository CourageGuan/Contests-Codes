#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 410;
int G[maxn][maxn];
int d1[maxn][maxn],d2[maxn][maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u][v] = G[v][u] = 1;
	}
	memset(d1,INF,sizeof d1);
	memset(d2,INF,sizeof d2);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(G[i][j]) d1[i][j] = 1;
			else d2[i][j] = 1;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				if(d1[i][k]<INF && d1[k][j]<INF)
				{
					d1[i][j] = min(d1[i][j],d1[i][k]+d1[k][j]);
				}
				if(d2[i][k]<INF && d2[k][j]<INF)
				{
					d2[i][j] = min(d2[i][j],d2[i][k]+d2[k][j]);
				}
			}
	int ans = max(d1[1][n],d2[1][n]);
	if(ans == INF) puts("-1");
	else printf("%d\n",ans);
	return 0;
}
