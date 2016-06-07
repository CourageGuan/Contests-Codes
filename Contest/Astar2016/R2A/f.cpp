#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long LL;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int in[maxn];
int topo[maxn],t,n,m;

LL topo_sort()
{
	priority_queue<int> Q;
	for(int i=1;i<=n;++i) if(!in[i]) Q.push(i);
	int cnt = 0;
	while(!Q.empty())
	{
		int u = Q.top(); Q.pop();
		topo[cnt++] = u;
		for(int i=0;i<G[u].size();++i)
		{
			int v = G[u][i];
			in[v]--;
			if(!in[v]) Q.push(v);
		}
	}
	//for(int i=0;i<n;++i) printf("%d ",topo[i]);
	//puts("");
	int cur = topo[0];
	LL ans = 0;
	for(int i=0;i<n;++i) cur = min(cur,topo[i]),ans+=cur;
	return ans;
}


int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		memset(in,0,sizeof in);
		for(int i=1;i<=n;++i) G[i].clear();
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			in[v]++;
		}
		cout << topo_sort() << '\n';
	}
	return 0;
}

