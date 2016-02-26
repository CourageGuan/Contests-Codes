#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 4e5 + 10;
int n,m;
struct Node{
	LL mark,bit;
} node[maxn<<2];

int col[maxn],q[maxn],l[maxn],r[maxn],tot = 0;
vector<int> G[maxn];

void dfs(int u,int fa)
{
	l[u] = ++tot;
	q[tot] = u;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v,u);
	}
	r[u] = tot;
}

void pushdown(int u)
{
	if(node[u].mark)
	{
		node[u<<1].bit = node[u<<1|1].bit = node[u<<1].mark = node[u<<1|1].mark = node[u].mark;
		node[u].mark = 0;
	}
}

void pushup(int u)
{
	node[u].bit = node[u<<1].bit | node[u<<1|1].bit;
}

void build(int L,int R,int u)
{
	node[u].mark = 0;
	if(L == R)
	{
		node[u].bit = 1LL << col[q[L]-1];
		return ;
	}	
	int m = (L+R)>>1;
	build(L,m,u<<1);
	build(m+1,R,u<<1|1);
	pushup(u);
}

void update(int cL,int cR,int col,int L,int R,int u)
{
	if(cL <= L && R <= cR)
	{
		node[u].bit = node[u].mark = 1LL<<col;
		return ;
	}
	pushdown(u);
	int m = (L+R)>>1;
	if(m >= cL) update(cL,cR,col,L,m,u<<1);
	if(m < cR) update(cL,cR,col,m+1,R,u<<1|1);
	pushup(u);
}

LL query(int cL,int cR,int L,int R,int u)
{
	if(cL <= L && R <= cR)
		return node[u].bit;
	pushdown(u);
	LL res = 0;
	int m = (L+R)>>1;
	if(m >= cL) res |= query(cL,cR,L,m,u<<1);
	if(m < cR) res |= query(cL,cR,m+1,R,u<<1|1);
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i) scanf("%d",col+i);
	for(int i=0;i<n-1;++i) 
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,1);
	build(1,n,1);
	for(int i=0;i<m;++i)
	{
		int op,u,col;
		scanf("%d",&op);
		if(op == 1)
		{
			scanf("%d %d",&u,&col);
			update(l[u],r[u],col,1,n,1);
		}
		else
		{
			scanf("%d",&u);
			printf("%d\n",__builtin_popcountll(query(l[u],r[u],1,n,1)));
		}
	}
	return 0;
}

