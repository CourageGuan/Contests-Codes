#pragma comment (linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;


const int maxn = 1e5 + 10;
vector<int> G[maxn];
int vis[maxn];
int topo[maxn],t,n,m;

void dfs(int u){
	vis[u]=1;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(!vis[v]) dfs(v);
	}
	topo[--t]=u;
//	printf("%d %d\n",t,u);
}

void topo_sort(){
	t = n;
	memset(vis,0,sizeof vis);
	for(int u=1; u<=n ; ++u) if(!vis[u]) dfs(u);
}


int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i) G[i].clear();
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
		}
		topo_sort();
		//for(int i=0;i<n;++i) printf("%d ",topo[i]);
		//puts("");
		int cur = topo[0];
                LL ans = 0;
		for(int i=0;i<n;++i) cur = min(cur,topo[i]),ans+=cur;
		cout << ans << '\n';
	}
	return 0;
}
