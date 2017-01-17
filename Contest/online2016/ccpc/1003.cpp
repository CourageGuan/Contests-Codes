#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
int n;
int a[maxn],d[maxn][2],f[maxn][2];
vector<int> G[maxn],C[maxn];

void dfs(int u,int fa,int c)
{
	if(fa != -1)
	{
		f[u][0] = f[u][1] = a[u];

		f[u][0] = max(f[u][0],a[u]+d[fa][0]-c);
		f[u][0] = max(f[u][0],a[u]+d[fa][1]-c);

		f[u][1] = max(f[u][1],a[u]+d[fa][1]-2*c);

//		printf("%d %d\n",u,f[u][0]);
	}
	R(i,G[u].size())
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u,C[u][i]);

		d[u][0] = max(d[u][0],a[v]+d[u][1]+d[v][1]-C[u][i]);
		d[u][0] = max(d[u][0],a[v]+d[u][1]+d[v][0]-C[u][i]);

		d[u][1] = max(d[u][1],a[v]+d[u][1]+d[v][1]-2*C[u][i]);
	}
}


int main()
{
	freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%d",&n);
		F(i,1,n) scanf("%d",a+i),G[i].clear();
		F(i,1,n-1)
		{
			int u,v,c;
			scanf("%d %d %d",&u,&v,&c);

			G[u].push_back(v);
			C[u].push_back(c);

			G[v].push_back(u);
			C[v].push_back(c);
		}
		fill(d,0);
		fill(f,0);
		f[1][0] = f[1][1] = a[1];
		dfs(1,-1,0);
		printf("Case #%d:\n",z);
		F(i,1,n)
		{
			printf("%d %d %d\n",i,d[i][0],d[i][1]);
		}
		F(i,1,n) printf("%d\n",max(d[i][0]+f[i][1],d[i][1]+f[i][0]));
	}
	return 0;
}

