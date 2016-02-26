#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 510;
int n,m;
int G[maxn][maxn];
int vis[maxn];
char res[maxn];

void dfs(int u,char c)
{
	vis[u] = 1;
	bool flag = false;
	for(int i=1;i<=n;++i)
	{
		if(i == u) continue;
		if(!G[u][i])
		{
			if(!vis[i]) dfs(i,c == 'c'?'a':'c');
			flag = true;
		}
	}
	if(flag) res[u] = c;
	else vis[u] = 0;
}

bool judge()
{
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,'a');
	for(int i=1;i<=n;++i) if(!vis[i]) res[i] = 'b';
	res[n+1] = '\0';
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(G[i][j] && ((res[i] == 'a' && res[j] == 'c') ||  (res[i] == 'c' && res[j] == 'a')))return false;
			if(!G[i][j] && !((res[i] == 'a' && res[j] == 'c') ||  (res[i] == 'c' && res[j] == 'a')))return false;
		}
	}
	puts("Yes");
	puts(res+1);
	return true;
}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	memset(G,0,sizeof G);
	for(int i=0;i<m;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u][v] = G[v][u] = 1;
	}
	if(!judge()) puts("No");
	return 0;
}
