//求拓扑排序方案数
//由于n较大而m较小，可以分联通块求解，每个联通块最多有m+1个结点
//最后分别乘在一起并乘上相应的组合数 C(remain,size) 即可
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef long long LL;
const LL mod = (LL)1e9+7;
const int maxn = 50;
int G[maxn][maxn];
int pic[maxn];
bool vis[maxn];
vector<int> link[maxn];
int n,m,cnt;
LL d[1<<21];
LL C[maxn][maxn];

void init()
{
	for(int i=0;i<maxn;++i)
	{
		C[i][0] = 1;
		for(int j=1;j<=i;++j) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}
}

LL dp(int num,int pic[])
{
	memset(d,0,sizeof d);
	d[0] = 1;
	for(int i=0;i<(1<<num);++i)
	{
		if(!d[i]) continue;
		for(int j=0;j<num;++j)
		{
			if((pic[j]&i) == 0) d[i|(1<<j)] = (d[i|(1<<j)]+d[i]) %mod;
		}
	}
	return d[(1<<num)-1];
}

void dfs(int u)
{
	link[cnt].push_back(u);
	vis[u] = 1;
	for(int i=1;i<=n;++i) if(!vis[i] && G[u][i]) dfs(i);
}

int main()
{
	//freopen("test.txt","r",stdin);
	init();
	while(scanf("%d %d",&n,&m)==2)
	{
		memset(G,0,sizeof G);
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u][v] = 1;
			G[v][u] = -1;
		}
		memset(vis,0,sizeof vis);
		cnt = 0;
		for(int i=0;i<n;++i) link[i].clear();
		for(int i=1;i<=n;++i)
		{
			if(!vis[i]) dfs(i);
			if(link[cnt].size()) ++cnt;
		}
		LL ans = 1;
		for(int k=0;k<cnt;++k)
		{
			memset(pic,0,sizeof pic);
			for(int i=0;i<link[k].size();++i)
			{
				int t = link[k][i];
				pic[i] |= 1<<i;
				for(int j=0;j<link[k].size();++j)
				{
					if(j==i) continue;
					int p = link[k][j];
					if(G[t][p]==1) pic[i] |= 1<<j;
				}
			}
			if(n>=2) ans = (ans*dp(link[k].size(),pic)) % mod;
			ans = ans*C[n][link[k].size()] %mod;
			n -= link[k].size();
		}
		printf("%I64d\n",ans);	
	}
	return 0;
}

