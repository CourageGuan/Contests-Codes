//经典的TSP问题
//集合dp
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 15;
const int INF = 0x3f3f3f3f;
int d[maxn][1<<11];
int G[maxn][maxn],n;

int dp()
{
	memset(d,INF,sizeof d);
	for(int i=0;i<n;++i) d[i][1<<i] = G[0][i];
	for(int S=0;S<(1<<n);++S)
	{
		for(int i=0;i<n;++i)
		{
			if(d[i][S] == INF) continue;
			for(int j=0;j<n;++j)
			{
				if(j==i || (S&(1<<j))) continue;
				d[j][S|(1<<j)] = min(d[j][S|(1<<j)],d[i][S]+G[i][j]);
			}
		}
	}
	return d[0][(1<<n)-1];
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&n)==1 && n)
	{
		++n;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&G[i][j]);
		for(int k = 0 ; k < n ; ++k)
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
					
		printf("%d\n",dp());	
	}
	return 0;
}

