#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e5 + 10;
int u[maxn],v[maxn],in[maxn],n,m;
vector<int> G[maxn];

bool topo_sort(int k)
{
	queue<int> Q;
	F(i,1,n) G[i].clear();
	memset(in,0,sizeof in);
	F(i,1,k)
	{
		G[u[i]].push_back(v[i]);
		++in[v[i]];
	}
	int cnt = 0,zero = 0;
	for(int i=1;i<=n;++i) if(!in[i]) Q.push(i),++zero;
	if(zero > 1) return 0;
	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();
	//	if(k == 4) printf("%d %d\n",u,zero);
		--zero;
		++cnt;
		for(int i=0;i<G[u].size();++i)
		{
			int v = G[u][i];
			in[v]--;
			if(!in[v]) Q.push(v),++zero;
		}
		if(zero > 1) return 0;
	}
	return cnt == n;
}


int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	F(i,1,m) scanf("%d %d",u+i,v+i);
	int l = 1,r = m,res = -1;
	while(l <= r)
	{
		int m = (l+r) >> 1;
		if(topo_sort(m))
		{
			res = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	printf("%d\n",res);
	return 0;
}
