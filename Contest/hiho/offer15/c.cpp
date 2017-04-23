#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define fi first
#define se second
#define mp make_pair

const int INF = 0x3f3f3f3f;
int n,m,a,b,c;
int ta[22][22],tb[22][22],tc[22];
int ok[1<<17],vis[1<<17][2],at[22];
vector<int> boat;

int bfs()
{
	memset(vis,INF,sizeof vis);
	queue<pair<int,int>> Q;
	queue<int> S;
	int all = (1<<n)-1;
	if(!ok[all]) return -1;
	Q.push(mp(all,0));
	S.push(0);
	vis[all][0] = 0;
	while(!Q.empty())
	{
		auto u = Q.front(); Q.pop();
		int s = S.front(); S.pop();
		if(u.fi == 0) return s;
		for(int i=0;i<boat.size();++i)
		{
			int msk = boat[i];
			if(u.se == 0 && vis[u.fi^msk][0]>s+1 && (u.fi&msk) == msk && ok[u.fi^msk] && ok[all^u.fi^msk])
			{
				vis[u.fi^msk][0] = s+1;
				Q.push(mp(u.fi^msk,1));
				S.push(s+1);
			}
			if(u.se == 1 && vis[u.fi^msk][1]>s+1 && (u.fi&msk) == 0 && ok[u.fi^msk] && ok[all^u.fi^msk])
			{
				vis[u.fi^msk][1] = s+1;
				Q.push(mp(u.fi^msk,0));
				S.push(s+1);
			}
		}
	}
	return -1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(~scanf("%d %d",&n,&m))
	{
		scanf("%d %d %d",&a,&b,&c);
		memset(ta,0,sizeof ta);
		memset(tb,0,sizeof tb);
		memset(tc,0,sizeof tc);
		int x,y;
		for(int i=0;i<a;++i)
		{
			scanf("%d %d",&x,&y);
			ta[x][y] = 1;
		}
		for(int i=0;i<b;++i)
		{
			scanf("%d %d",&x,&y);
			tb[x][y] = 1;
		}
		for(int i=0;i<c;++i)
		{
			scanf("%d",&x);
			tc[x] = 1;
		}
		memset(ok,0,sizeof ok);
		boat.clear();
		for(int i=0;i<(1<<n);++i)
		{
			bool flag = 1;
			memset(at,0,sizeof at);
			for(int j=0;j<n;++j)
				for(int k=0;k<n;++k)
					if((i&(1<<j)) && (i&(1<<k)) && ta[j][k]) at[j] = 1;
			for(int j=0;j<n;++j)
				for(int k=0;k<n;++k)
					if((i&(1<<j)) && (i&(1<<k)) && tb[j][k]) at[k] = 0;
			for(int j=0;j<n;++j) if(at[j]) 
			{
				flag = 0;
				break;
			}
			if(flag)
			{
				ok[i] = 1;
				if(!i || __builtin_popcount(i) > m) continue;
				for(int j=0;j<n;++j) 
					if(tc[j] && (i&(1<<j)))
					{
						boat.push_back(i);
						break;
					}
			}
		}
		//for(int i=0;i<boat.size();++i) printf("%d\n",boat[i]);
		printf("%d\n",bfs());
	}
	return 0;
}
