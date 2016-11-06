#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define mp std::make_pair
#define fi first
#define se second

const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;

struct node {
	int u,num,w;
	node(int u,int n,int w):u(u),num(n),w(w) {}
	node() {}
	bool operator<(const node& rhs) const {
		return num < rhs.num;
	}
};

int n,m,k;
std::vector<std::pair<int,int> > G[maxn];
std::vector<node> tmp;
int root,size,ans;
int sz[maxn],color[maxn],f[maxn],d[maxn],g[maxn],done[maxn];

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

int getn(int u,int fa=0)
{
	int res = 0;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i].fi;
		if(done[v] || v == fa) continue;
		res = std::max(res,getn(v,u));
	}
	return res + color[u];
}

void getg(int u,int dep,int w,int fa=0)
{
	g[dep] = std::max(g[dep],w);
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i].fi;
		if(done[v] || v == fa) continue;
		getg(v,dep+color[v],w+G[u][i].se,u);
	}
}

void cal(int u)
{
	//printf("..%d\n",u);
	tmp.clear();
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i].fi;
		if(done[v]) continue;
		int t = getn(v);
		tmp.push_back(node(v,t,G[u][i].se));
	}
	sort(tmp.begin(),tmp.end());
	int limit = k - color[u]; 
	if(tmp.size()) F(i,0,tmp[tmp.size()-1].num) d[i] = -INF;
	for(int i=0;i<tmp.size();++i)
	{
		F(j,0,tmp[i].num) g[j] = -INF;
		getg(tmp[i].u,color[tmp[i].u],tmp[i].w);
//		printf("..%d\n",tmp[i].u);
		if(i)
		{
			F(j,0,tmp[i].num)
			{
				if (j>limit) break;
				int t = std::min(tmp[i-1].num,limit - j);
				if(d[t] == -INF) break;
				ans = std::max(ans,g[j] + d[t]);
//				printf("%d %d %d %d\n",j,t,g[j],d[t]);
			}
		}
		F(j,0,tmp[i].num)
		{
			if (j>limit) break;
			d[j] = std::max(d[j],g[j]);
			if(j) d[j] = std::max(d[j],d[j-1]);
			ans = std::max(d[j],ans);
		}
//		puts("");
	}
}

void gao(int u)
{
	done[u] = 1;
	cal(u);
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i].fi; 
		if(done[v]) continue;
		f[0] = size = sz[v];
		root = 0;
		getroot(v);
		gao(root);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d %d %d",&n,&k,&m);
	F(i,1,m)
	{
		int c;
		scanf("%d",&c);
		color[c] = 1;
	}
	F(i,1,n-1)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		G[u].push_back(mp(v,w));
		G[v].push_back(mp(u,w));
	}
	memset(d,-INF,sizeof d);
	f[0] = size = n;
	root = 0;
	getroot(1);
	ans = 0;
	gao(root);
	printf("%d\n",ans);
	return 0;
}
