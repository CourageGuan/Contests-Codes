//由于有n条边，性质比较特殊
//若存在一条回路，首先图必须是连通的
//我们来分析度数为1的点的个数
// 0  环 ， YES
// 1  露出一端的环, YES
// 2  从度数为1的点dfs一遍看是否能构成一条链
// >= 3  无法构成, NO
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 1010;
int d[maxn];
bool vis[maxn];
vector<int> G[maxn];
int n;

bool dfs(int u,int fa,int cnt)
{
	if(vis[u]) return false;
	vis[u] = 1;
	if(cnt == n) return true;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v != fa)
		{
			if(dfs(v,u,cnt+1)) return true;
		}
	}
	vis[u] = 0;
	return false;
}

bool yes()
{
	int cnt = 0;
	for(int i=1;i<=n;++i) 
		if(d[i]==1) ++cnt;
		else if(!d[i]) return false;
	if(cnt <= 1) return true;
	if(cnt>=3) return false;
	for(int i=1;i<=n;++i) if(d[i]==1)
	{
		memset(vis,0,sizeof vis);
		if(dfs(i,-1,1)) return true;
	}
	return false;
}

int main()
{
 	freopen("test.txt","r",stdin);
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<=n;++i) G[i].clear();
		memset(d,0,sizeof d);
        for(int i=0;i<n;++i)
        {
            int u,v;
            scanf("%d %d",&u,&v);
			if(u==v) continue;
			++d[u]; ++d[v];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        puts(yes()?"YES":"NO");
    }
    return 0;
}

