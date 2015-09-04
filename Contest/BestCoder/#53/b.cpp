//dfs 出跟到每个结点的距离，若有两个距离相等的结点，且至少一个有子结点则满足条件
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 1010;
vector<int> G[maxn];
int d[maxn];

void dfs(int u,int fa,int dis)
{
	d[u] = dis;
	for(int i=0;i<G[u].size();++i)
	{
		if(G[u][i] == fa) continue;
		dfs(G[u][i],u,dis+1);
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<maxn;++i) G[i].clear();
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,-1,0);
		bool flag = true;
		for(int i=2;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				if(d[i] == d[j] && (G[i].size()>1 || G[j].size()>1))
				{
				   	flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}
