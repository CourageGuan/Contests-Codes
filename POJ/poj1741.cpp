#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define mp std::make_pair
#define fi first
#define se second

const int maxn = 1e5 + 10;
int n,k;
std::vector<std::pair<int,int> > G[maxn];
std::vector<int> dd;
int root,size,ans;
int sz[maxn],f[maxn],d[maxn],done[maxn];

void getroot(int u,int fa=0)
{
	sz[u] = 1,f[u] = 0;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i].fi;
		if(v == fa || done[v]) continue;
		getroot(v,u);
		sz[u] += sz[v];
		f[u] = std::max(f[u],sz[v]);
	}
	f[u] = std::max(f[u],size - sz[u]);
	if(f[u] < f[root]) root = u;
}

void getd(int u,int fa=0)
{
	dd.push_back(d[u]);
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i].fi;
		if(v == fa || done[v]) continue;
		d[v] = d[u] + G[u][i].se;
		getd(v,u);
	}
}

int cal(int u,int init)
{
	dd.clear(); d[u] = init;
	getd(u);
	sort(dd.begin(),dd.end());
	int res = 0,l,r;
	for(l=0,r=dd.size()-1;l<r;)
		if(dd[l] + dd[r] <= k) res += r-l,++l;
		else --r;
	return res;
}

void gao(int u)
{
	ans += cal(u,0);
	done[u] = 1;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i].fi; 
		if(done[v]) continue;
		ans -= cal(v,G[u][i].se);
		f[0] = size = sz[v];
		root = 0;
		getroot(v);
		gao(root);
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	while(~scanf("%d %d",&n,&k) && n+k)
	{
		F(i,1,n) G[i].clear();
		memset(done,0,sizeof done);
		F(i,1,n-1)
		{
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			G[u].push_back(mp(v,w));
			G[v].push_back(mp(u,w));
		}
		f[0] = size = n;
		root = 0;
		getroot(1);
		ans = 0;
		gao(root);
		printf("%d\n",ans);
	}
	return 0;
}
