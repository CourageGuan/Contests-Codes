#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
vector<int> G[maxn];
LL ans,k;
int m,n,fa[maxn];
LL a[maxn],b[maxn],q[maxn*2];
int bit[maxn*2];

void add(int x,int d)
{
	for(;x < 2*maxn;x += x&-x) bit[x] += d;
}

int query(int x)
{
	int res = 0;
	for(;x>0;x -= x&-x) res += bit[x];
	return res;
}

void dfs(int u,int fa)
{
	R(i,G[u].size())
	{
		int v = G[u][i];
		if(v == fa) continue;
		LL p = query(b[v]);
		ans += p;
		add(a[v],1);
		dfs(v,u);
		add(a[v],-1);
	}
}

void init(int n)
{
	m = 0;
	fill(fa,0);
	F(i,1,n) G[i].clear(); 
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	R(z,T)
	{
		scanf("%d %lld",&n,&k);	
		init(n);
		R(i,n) scanf("%lld",a+i+1),b[i+1] = a[i+1]?(k/a[i+1]):k,q[m++] = a[i+1],q[m++] = b[i+1];
		sort(q,q+m);
		int pm = unique(q,q+m) - q;
		F(i,1,n) a[i] = (lower_bound(q,q+pm,a[i]) - q) + 1,b[i] = (lower_bound(q,q+pm,b[i]) - q)+ 1;
//		F(i,1,n) printf("%d %d\n",a[i],b[i]);
		R(i,n-1)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			fa[v] = u;
			G[u].push_back(v);
		}
		int root = 1;
		R(i,n) if(fa[i+1] == 0) { root = i+1; break; } 
		ans = 0;
		add(a[root],1);
		dfs(root,-1);
		add(a[root],-1);
		printf("%lld\n",ans);
	}
	return 0;
}
