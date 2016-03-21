//概率dp
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

const int maxn = 1010;
vector<int> G[maxn];
int p[maxn][maxn],n,m;
bool vis[maxn][maxn];
double d[maxn][maxn];


void bfs(int s)
{
	bool vis[maxn];
	memset(vis,0,sizeof vis);
	vis[s] = 1;
	queue<int> Q,ID;
	for(int i=0;i<G[s].size();++i)
	{
		Q.push(G[s][i]);
		ID.push(G[s][i]);
		vis[G[s][i]] = 1;
	}
	while(!Q.empty())
	{
		int q = Q.front(),id = ID.front() ;
		Q.pop(); ID.pop();
		p[s][q] = id;
//		printf("%d %d %d\n",s,q,id);
		for(int i=0;i<G[q].size();++i)
		{
			if(vis[G[q][i]]) continue;
			vis[G[q][i]] = 1;
			Q.push(G[q][i]);
			ID.push(id);
		}
	}
}

double dp(int u,int v)
{
	if(u == v) return 0;
	double &ans = d[u][v];
	if(vis[u][v]) return ans;
	vis[u][v] = 1;
	ans = 0;
	if(p[u][v] != v && p[p[u][v]][v] != v)
	{
		ans += dp(p[p[u][v]][v],v);
		for(int i=0;i<G[v].size();++i)
		{
			ans += dp(p[p[u][v]][v],G[v][i]);	
		}
		ans /= (G[v].size()+1);
	}
	return ans += 1;
}


int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d",&n,&m)==2)
	{
		int cong,ke;
		scanf("%d %d",&cong,&ke);
		for(int i=0;i<maxn;++i) G[i].clear();
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=n;++i) sort(G[i].begin(),G[i].end());
		for(int i=1;i<=n;++i) bfs(i);

/*
 		 for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				printf("%d %d %d\n",i,j,p[i][j]);
*/

			
		memset(vis,0,sizeof vis);
		printf("%.3f\n",dp(cong,ke));
	}
	return 0;
}
