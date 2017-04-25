//RE unknown error...
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define fi first
#define se second
const int maxn = 310;
const int INF = 0x3f3f3f3f;
int n,m,p;
vector<pair<int,int> > G[maxn*maxn];
int g[maxn][maxn],d[2][maxn*2][maxn][10],LOG[2*maxn];

void init()
{
	LOG[0] = -1;
	for(int i=1;i<maxn;++i) LOG[i] = LOG[i/2] + 1;
}

int query(int dir,int id,int L,int R)
{
	L = max(0,L);
	R = min(R,n-1);
//	printf("%d %d %d\n",L,R,R-L+1);
	//assert(R-L+1 != 0);
	int t = LOG[R-L+1];
	return min(d[dir][id][L][t],d[dir][id][R-(1<<t)+1][t]);
}

int main()
{
	//freopen("test.txt","r",stdin);
	init();
	scanf("%d %d %d",&n,&m,&p);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			int x;
			scanf("%d",&x);
			G[x].push_back(make_pair(i,j));
		}
	memset(g,INF,sizeof g);
	for(int i=0;i<=G[1].size();++i)
		g[G[1][i].fi][G[1][i].se] = G[1][i].fi+G[1][i].se;
	int ans = INF;
	for(int i=2;i<=p;++i)
	{
		memset(d,INF,sizeof d);

		for(int j=0;j<n;++j)
			for(int k=0;k<m;++k)
			{
				d[0][j+k][j][0] = d[1][j-k+maxn][j][0] = g[j][k];
			}
		for(int j=0;j<m+n-1;++j)
		{
			for(int k=1;(1<<k) <= n;++k)
				for(int l=0;l+(1<<(k-1))-1<n;++l)
				{
					d[0][j][l][k] = min(d[0][j][l][k-1],d[0][j][l+(1<<(k-1))][k-1]);
				}
		}
		for(int j=maxn-(m-1);j<maxn+n;++j)
		{
			for(int k=1;(1<<k)<= n;++k)
				for(int l=0;l+(1<<(k-1))-1<n;++l)
					d[1][j][l][k] = min(d[1][j][l][k-1],d[1][j][l+(1<<(k-1))][k-1]);
		}
		int len;
		for(int k=0;k<G[i].size();++k)
		{
			int mn = INF;
			int x = G[i][k].fi,y = G[i][k].se,cur = x+y;
			for(int j=0;j<m+n-1;++j)
			{
				if(j == cur) continue;
				len = abs(j-cur);
				printf("%d %d %d..%d\n",j-cur,x,x+len,mn);
				if(j > cur) mn = min(mn,query(0,j,x,x+len)+len);
				else mn = min(mn,query(0,j,x-len,x)+len);
			}
			cur = x-y+maxn;
			for(int j=maxn-(m-1);j<maxn+n;++j)
			{
				if(j == cur) continue;
				len = abs(j-cur);
				if(j > cur) mn = min(mn,query(1,j,x,x+len)+len);
				else mn = min(mn,query(1,j,x-len,x)+len);
			}
			g[x][y] = mn;
		}
		//for(int i=0;i<n;++i)
		//{
		//	for(int j=0;j<m;++j)
		//		printf("%d ",g[i][j]);
		//	puts("");
		//}
		//puts("");

		for(int k=0;k<G[i-1].size();++k)
			g[G[i-1][k].fi][G[i-1][k].se] = INF;
	}
	printf("%d\n",g[G[p][0].fi][G[p][0].se]);
	return 0;
}
