#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 3010;
const int INF = 1e5;
vector<int> G[2][maxn];
bool vis[maxn][maxn];
int d[2][maxn][maxn],id[2][maxn];
int n,m;

struct P{
	int v[3],id[3];
	P()
	{
		for(int i=0;i<3;++i) v[i] = -INF,id[i] = 0;
	}
	void update(int w,int t)
	{
		for(int i=0;i<3;++i)
		{
			if(w >= v[i])
			{
				for(int j=2;j>i;--j)
				{
					v[j] = v[j-1];
					id[j] = id[j-1];
				}
				v[i] = w;
				id[i] = t;
				break;
			}
		}
	}
} p[2][maxn];

void bfs(int t,int op)
{
	queue<int> Q;
	Q.push(t);
	d[op][t][t] = 0;
	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for(int i=0;i<G[op][u].size();++i)
		{
			int v = G[op][u][i];
			if(d[op][t][v] != -INF) continue;
			d[op][t][v] = d[op][t][u] + 1;
			Q.push(v);
		}
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		if(vis[u][v]) continue;
//		printf("%d %d\n",u,v);
		vis[u][v] = 1;
		G[0][u].push_back(v);
		G[1][v].push_back(u);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=0;k<2;++k)
				d[k][i][j] = -INF;

	for(int i=1;i<=n;++i)
	{
		bfs(i,0);
		bfs(i,1);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j) if(i != j)
		{
			for(int k=0;k<2;++k)
			{
				p[k][i].update(d[k][i][j],j);
			}
		}
	}
	int ans = 0,res[4];
	for(int u=1;u<=n;++u)
	{
		for(int v=1;v<=n;++v)
		{
			if(u == v) continue;
			for(int j=0;j<3;++j)
			{
				for(int k=0;k<3;++k)
				{
					if(ans < d[0][u][v] + p[1][u].v[j] + p[0][v].v[k] && p[1][u].id[j] != v && p[0][v].id[k] != u && p[1][u].id[j] != p[0][v].id[k])
					{
						ans = d[0][u][v] + p[1][u].v[j] + p[0][v].v[k];
						res[0] = p[1][u].id[j];
						res[1] = u;
						res[2] = v;
						res[3] = p[0][v].id[k];
					}
				}
			}
		}
	}
//	printf("%d\n",ans);
	for(int i=0;i<4;++i) printf("%d ",res[i]);
	puts("");
	return 0;
}
