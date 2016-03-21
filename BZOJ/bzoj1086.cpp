#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

const int maxn = 1010;
int N,B;
vector<int> G[maxn];
stack<int> st;

int id[maxn],sz[maxn],cap[maxn],cnt;

void dfs(int u,int fa)
{
	st.push(u);
	sz[u] = 0;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u);
		sz[u] += sz[v];
		if(sz[u] >= B)
		{
			++cnt;
			int j = 0;
			while(!st.empty() && ++j <= sz[u])
			{
				id[st.top()] = cnt;
				if(j == sz[u]) cap[cnt] = st.top();
				st.pop();
			}
			if(!st.empty()) cap[cnt] = st.top();
			sz[u] = 0;
		}
	}
	sz[u] += 1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&N,&B);
	for(int i=1;i<N;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(sz,0,sizeof sz);
	cnt = 0;
	dfs(1,1);
	if(st.size() >= B) ++cnt;
	while(!st.empty())
	{
		id[st.top()] = cnt;
		if(st.size() == 1) cap[cnt] = st.top();
		st.pop();
	}
	printf("%d\n",cnt);
	for(int i=1;i<=N;++i) printf("%d%c",id[i],i == N?'\n':' ');
	for(int i=1;i<=cnt;++i) printf("%d%c",cap[i],i == N?'\n':' ');
	return 0;
}
