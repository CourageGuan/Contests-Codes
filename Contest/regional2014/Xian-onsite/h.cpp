#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 110;
int n,m,x,y;
int G[maxn][maxn],d[maxn][maxn][2],o[maxn],cnt[maxn][maxn];

struct P{
	int b,a,t;
	P(int b,int a,int t):b(b),a(a),t(t) {}
	P() {}
};

int bfs()
{
	queue<P> Q;
	memset(d,-1,sizeof d);
	memset(cnt,0,sizeof cnt);
	F(i,1,n)
	{
		d[i][i][0] = d[i][i][1] = 0;
		Q.push(P(i,i,0));
		Q.push(P(i,i,1));
		if(o[i] == 0) F(j,1,n)
		{
			if(i == j) continue;
			d[i][j][0] = 0;
			Q.push(P(i,j,0));
		}
	}
	while(Q.size())
	{
		P p = Q.front(); Q.pop();
		if(p.t == 0)
		{
			F(i,1,n)
				if(G[i][p.a])
				{
					if(!d[p.b][i][1]) continue;
					d[p.b][i][1] = 0;
					Q.push(P(p.b,i,1));
				}
		}
		else
		{
			F(i,1,n)
				if(G[i][p.b])
				{
					++cnt[i][p.a];
					if(cnt[i][p.a] == o[i])
					{
						if(!d[i][p.a][0]) continue;
						d[i][p.a][0] = 0;
						Q.push(P(i,p.a,0));
					}
				}
		}
	}
	return d[x][y][0];
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%d %d",&n,&m);
		memset(G,0,sizeof(G));
		memset(o,0,sizeof(o));
		F(i,0,m-1)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u][v] = 1;
			o[u]++;
		}
		scanf("%d %d",&x,&y);
		int res = bfs();
		printf("Case #%d: %s\n",z,res?"Yes":"No");
	}
	return 0;
}
