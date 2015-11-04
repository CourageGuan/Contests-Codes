#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const int LOG = 17;

struct Node
{
	int a[11];
	int sz;
	Node() {sz=0;}
} d[maxn][LOG],node[maxn];

Node merge(Node a,Node b)
{
	Node res;
	int l1 , l2;
	l1 = l2 = res.sz = 0;
	while(res.sz<10 && (l1 < a.sz || l2 < b.sz))	
	{
		while(res.sz < 10 && l1<a.sz && (l2 >= b.sz || b.a[l2] >= a.a[l1]))
		{
			res.a[res.sz++] = a.a[l1];
			++l1;
		}
		while(res.sz<10 && l2<b.sz && (l1 >= a.sz || b.a[l2] <= a.a[l1]))
		{
			res.a[res.sz++] = b.a[l2];
			++l2;
		}
	//	printf("%d %d\n",l1,l2);
	}
	return res;
}

vector<int> G[maxn];
int p[maxn][LOG],deep[maxn];
int n,m,q;

void dfs(int u,int fa,int dep)
{
	p[u][0] = fa;
	if(fa!=-1) d[u][0] = node[fa];
	deep[u] = dep;

	for(int i=1;i<LOG;++i)
	{
		if(p[u][i-1] != -1)
		{
			p[u][i] = p[p[u][i-1]][i-1];
		}
	}

	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u,dep+1);
	}
}

Node query(int u,int v)
{
	//printf("%d %d --> %d %d\n",u,v,deep[u],deep[v]);
	if(deep[u] < deep[v]) swap(u,v);
	Node resu = node[u],resv = node[v];
	for(int i=LOG-1;i>=0;--i)
	{
		if(p[u][i]!=-1 && deep[p[u][i]] >= deep[v])
		{
			resu = merge(resu,d[u][i]);
			u = p[u][i];
		}
	}
	if( u == v) return resu;
	for(int i=LOG-1;i>=0;--i)
	{
		if(p[u][i] != p[v][i])
		{
			resu = merge(resu,d[u][i]);
			u = p[u][i];
			resv = merge(resv,d[v][i]);
			v = p[v][i];
		}
	}
	return merge(d[u][0],merge(resu,resv)); 
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&q);	
	for(int i=0;i<n-1;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=m;++i)
	{
		int x;
		scanf("%d",&x);
		if(node[x].sz >= 10)
		{
			node[x].a[10] = i;
			sort((node[x].a),(node[x].a)+10);
		}
		else node[x].a[node[x].sz++] = i;
	}
	memset(p,-1,sizeof p);
	dfs(1,-1,1);
	for(int i=1;i<LOG;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(p[j][i-1]!=-1)
			{
				d[j][i] = merge(d[j][i-1],d[p[j][i-1]][i-1]);
			}
		}
	}
	while(q--)
	{
		int u,v,a;
		scanf("%d %d %d",&u,&v,&a);
		Node now = query(u,v);
		int sz = min(a,now.sz);
		printf("%d",sz);
		for(int i=0;i<sz;++i) printf(" %d",now.a[i]);
		puts("");
	}
	return 0;
}
