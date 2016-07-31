#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
const double eps = 1e-9;
double A[maxn],B[maxn],C[maxn],K[maxn],E[maxn];

vector<int> G[maxn];

void dfs(int u,int fa = 1)
{
	int m = G[u].size();
	double t = 1 - K[u] - E[u],b=0;
	A[u] = K[u];
	B[u] = t/m;
	C[u] = t;
//	printf("%lf %lf %lf\n",A[u],B[u],C[u]);
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u);
		A[u] += t/m*A[v];
		C[u] += t/m*C[v];
		b += t/m*B[v];
	}
	A[u] /= 1-b;
	B[u] /= 1-b;
	C[u] /= 1-b; 
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n,T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i) G[i].clear();
		for(int i=1;i<n;++i) 
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=n;++i) scanf("%lf %lf",K+i,E+i),K[i]/=100,E[i]/=100;
		printf("Case %d: ",z);
		dfs(1);
		if(1-A[1] < eps)
		{
			puts("impossible");
			continue;
		}
		printf("%.6lf\n",C[1]/(1-A[1]));
	}
	return 0;
}

