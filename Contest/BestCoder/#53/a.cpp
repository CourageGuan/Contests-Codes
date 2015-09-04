#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	while(scanf("%d %d",&n,&m)==2)
	{
		memset(G,0,sizeof G);
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u][v] = G[v][u] = 1;
		}
		if(!G[1][n])
		{
			printf("%d %d\n",1,1);
		}
		else
		{
			printf("%d %d\n",1,n*(n-1)/2);
		}
	}
	return 0;
}
