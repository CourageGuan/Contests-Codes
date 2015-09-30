#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 5010;

vector<int> G[maxn];
int d[maxn][maxn][2];

void check(int &a,int b)
{
	if(a>b) a=b;
}

int dfs(int u,int fa)
{
	int num = G[u].size(),tot = 0,now = 0;
	d[u][0][0] = 0;
	d[u][0][1] = 0;
	if(num == 1)
	{
		d[u][0][1] = INF;
		d[u][1][1] = 0;
		return 1;
	}
	for(int i=0;i<num;++i)
	{
		int v = G[u][i];
		if(v == fa) continue;
		now = dfs(v,u);
		tot += now;
		for(int j=tot;j>=0;--j)
		{
			int mn0,mn1;
			mn0 = mn1 = INF;
			for(int k=0;k<=now;++k)
			{
				check(mn0,min(d[u][j-k][0]+d[v][k][0],d[u][j-k][0]+d[v][k][1]+1));
				check(mn1,min(d[u][j-k][1]+d[v][k][0]+1,d[u][j-k][1]+d[v][k][1]));
			}
			d[u][j][0] = mn0;
			d[u][j][1] = mn1;
		}
	}	
	return tot;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	if(n == 2)
	{
	   	puts("1");
		return 0;
	}
	int cnt = 0,p = 1;
	memset(d,INF,sizeof d);
	for(int i=1;i<=n;++i)
	{
		if(G[i].size() == 1) ++cnt;
		else p = i;
	}
	dfs(p,0);
	int ans = min(d[p][cnt/2][0],d[p][cnt/2][1]);
	printf("%d\n",ans);
	return 0;
}

