#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;

#define lt L,m,u<<1
#define rt m+1,R,u<<1|1

const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 1e5 + 10;
vector<int> G[maxn];
LL val[maxn];
int w[maxn],in[maxn],out[maxn],n,m,cnt;

struct Node
{
	LL mx;
	LL lazy;
} p[maxn<<2];

void dfs(int u,int fa,LL we)
{
	in[u] = ++cnt;
	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v != fa)
		{
			dfs(v,u,we+w[v]);
		}
	}
	val[in[u]] = we;
	out[u] = cnt;
}

void pushup(int u)
{
	p[u].mx = max(p[u<<1].mx,p[u<<1|1].mx);
}

void pushdown(int u)
{
	if(p[u].lazy)
	{
		p[u<<1].mx += p[u].lazy;
		p[u<<1|1].mx += p[u].lazy;
		p[u<<1].lazy += p[u].lazy;
		p[u<<1|1].lazy += p[u].lazy;
		p[u].lazy = 0;
	}
}

void build(int L,int R,int u)
{
	p[u].lazy = 0;
	if(L == R)
	{
		p[u].mx = val[L];
		return;
	}
	int m = L+R >> 1;
	build(lt);
	build(rt);
	pushup(u);
}

void update(LL v,int cL,int cR,int L,int R,int u)
{
	if(cL <= L && R <= cR)
	{
		p[u].mx += v;
		p[u].lazy += v;
		return ;
	}
	pushdown(u);
	int m = L+R >> 1;
	if(m >= cL) update(v,cL,cR,lt);
	if(m < cR) update(v,cL,cR,rt);
	pushup(u);
}

LL query(int cL,int cR,int L,int R,int u)
{
	if(cL <= L && R <= cR)
	{
		return p[u].mx;
	}
	LL res = -INF;
	pushdown(u);
	int m = L+R >> 1;
	if(m >= cL) res = max(res,query(cL,cR,lt));
	if(m < cR) res = max(res,query(cL,cR,rt));
	return res;
}


int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;++i) G[i].clear();
		for(int i=0;i<n-1;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=0;i<n;++i) scanf("%d",w+i);
		cnt = -1;
		dfs(0,0,w[0]);
		build(0,cnt,1);
		printf("Case #%d:\n",z);
		for(int i=0;i<m;++i)
		{
			int op,x,y;
			scanf("%d %d",&op,&x);
			if(op)
			{
				cout << query(in[x],out[x],0,cnt,1) << '\n';
			}
			else
			{
				scanf("%d",&y);
				update(y-w[x],in[x],out[x],0,cnt,1);
				w[x] = y;
			}
		}
	}
	return 0;
}

