#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
const int maxn = 310;
const int INF = 0x3f3f3f3f;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n,m,p;
vector<pair<int,int> > G[maxn*maxn];
int d[maxn][maxn],dis[maxn][maxn],inq[maxn][maxn];

void update(int &x,int y)
{
//	printf("%d %d\n",x,y);
	if(x > y)
		x = y;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&p);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			int x;
			scanf("%d",&x);
			G[x].push_back(make_pair(i,j));
		}
	memset(d,INF,sizeof d);
	int ans = INF;
	queue<pair<int,int> > Q;
	for(int i=0;i<G[1].size();++i) d[G[1][i].fi][G[1][i].se] = G[1][i].fi+G[1][i].se;
	for(int i=2;i<=p;++i)
	{
		if(G[i-1].size()*G[i].size() <= m*n)
		{
			for(int k=0;k<G[i].size();++k)
				for(int j=0;j<G[i-1].size();++j)
					update(d[G[i][k].fi][G[i][k].se],d[G[i-1][j].fi][G[i-1][j].se]+abs(G[i-1][j].fi-G[i][k].fi)+abs(G[i-1][j].se-G[i][k].se));
		}
		else
		{
			memset(inq,0,sizeof inq);
			memset(dis,INF,sizeof dis);
			for(int j=0;j<G[i-1].size();++j) Q.push(G[i-1][j]),dis[G[i-1][j].fi][G[i-1][j].se] = d[G[i-1][j].fi][G[i-1][j].se];
			while(!Q.empty())
			{
				pair<int,int> cur = Q.front(); Q.pop();
				inq[cur.fi][cur.se] = 0;
				for(int j=0;j<4;++j)
				{
					int tx = cur.fi + dx[j],ty = cur.se + dy[j];
					if(tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
					if(dis[tx][ty] > dis[cur.fi][cur.se]+1)
					{
						dis[tx][ty] = dis[cur.fi][cur.se]+1;
						if(!inq[tx][ty])
							inq[tx][ty] = 1,Q.push(make_pair(tx,ty));
					}
				}
			}
			for(int j=0;j<G[i].size();++j) d[G[i][j].fi][G[i][j].se] = dis[G[i][j].fi][G[i][j].se];
		}
	}
	printf("%d\n",d[G[p][0].fi][G[p][0].se]);
	return 0;
}
