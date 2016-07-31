#include<cstdio>
#include<cstring>

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = (1<<7) + 1;
int n,m,vis[1<<8][maxn];
double p[maxn][maxn],d[1<<8][maxn];

double dfs(int k,int t,int l,int r)
{
	if(vis[k][t]) return d[k][t];
	vis[k][t] = 1;
	d[k][t] = 0;
	int m = (l+r)>>1;
	if(t > m)
		F(i,l,m) d[k][t] += dfs((k<<1)+1,t,m+1,r)*dfs(k<<1,i,l,m)*p[t][i];
	else
		F(i,m+1,r) d[k][t] += dfs((k<<1)+1,i,m+1,r)*dfs(k<<1,t,l,m)*p[t][i];

	return d[k][t];
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&n) == 1 && n != -1)
	{
		fill(vis,0);
		m = 1<<n;
		for(int i=1;i<=m;++i)
		{
			for(int j=1;j<=m;++j)
				scanf("%lf",&p[i][j]);
			d[m+i-1][i] = 1;
			vis[m+i-1][i] = 1;
		}
		double mx = 0;
		int res = 1;
		for(int i=1;i<=m;++i)
		{
			if(dfs(1,i,1,m) - mx > 1e-3)
			{
				mx = d[1][i];
				res = i;
			}
//			printf("%lf\n",d[1][i]);
		}
		printf("%d\n",res);
	}
	return 0;
}

