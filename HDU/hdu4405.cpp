//最简单的一类概率dp
//转移很简单，按题目意思来即可
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 1e5 + 10;
double d[maxn];
int G[maxn];
bool vis[maxn];
int n,m;

double dp(int k)
{
	if(k>=n) return 0;
	if(vis[k]) return d[k];
	vis[k] = 1;
	d[k] = 0;
	if(G[k])
	{
		return d[k] = dp(G[k]);
	}
	for(int i=1;i<=6;++i)
	{
		d[k] += dp(i+k)+1;
	}
	return d[k]/=6;
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d",&n,&m)==2 && (n || m))
	{
		memset(G,0,sizeof G);
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u] = v;
		}
		memset(vis,0,sizeof vis);
		printf("%.4lf\n",dp(0));
	}
	return 0;
}
