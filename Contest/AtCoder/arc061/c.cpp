#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fi first
#define se second
#define mp make_pair

const int maxn = 1e5 + 10;
vector<pair<int,int> > G[maxn];
map<pair<int,int>,int> vis;
queue<pair<int,int> > Q;
queue<int> res;
int n,m;

int solve()
{
	Q.push(mp(1,0));
	res.push(0);
	int ans = 0x3f3f3f3f;
	while(Q.size())
	{
		pair<int,int> u = Q.front(); Q.pop();
		int cur = res.front(); res.pop();
		if(u.fi == n)
		{
			ans = min(ans,cur);
			continue;
		}
		F(i,0,int(G[u.fi].size()) - 1)
		{
			pair<int,int> v = G[u.fi][i];
			if(!vis.count(v) || vis[v] > cur + (v.se != u.se))
			{
				 vis[v] = cur + (v.se != u.se);
				 Q.push(v);
				 res.push(cur + (v.se != u.se));
			}
		}
	}
	if(ans >= 0x3f3f3f3f)
		return -1;
	else
		return ans;
}

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&m);
	F(i,1,m)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		G[u].push_back(mp(v,c));
		G[v].push_back(mp(u,c));
	}
	printf("%d\n",solve());
	return 0;
}
