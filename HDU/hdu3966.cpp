//树链剖分
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int maxn = 50010;

vector<int> G[maxn];

int son[maxn],size[maxn],deep[maxn],top[maxn],fa[maxn],id[maxn],save[maxn];
int idx,n,m,q;

void dfs1(int u,int f,int dp)
{
	fa[u] = f;
	size[u] = 1;
	deep[u] = dp;

	int Max=0,temp=0;
	for(int i=0;i<G[u].size();++i)
	{
		int v=G[u][i];
		if(v!=f)
		{
			dfs1(v,u,dp+1);
			size[u] += size[v];
			if(size[v] > Max)
			{
				Max = size[v];
				temp = v;
			}
		}
	}
	son[u] = temp;
}

void dfs2(int u,int f,int tp)
{
	id[u] = idx++;
	top[u] = tp;
	if(son[u]!=0) dfs2(son[u],u,top[u]);

	for(int i=0;i<G[u].size();++i)
	{
		int v = G[u][i];
		if(v!=f && v!=son[u])
		{
			dfs2(v,u,v);
		}
	}
}

int num[maxn<<2];

void update(int cL,int cR,int val,int L,int R,int u)
{
	if(cL <= L && R <= cR)
	{
		num[u] += val;
	}
	else
	{
		int m = (L+R)>>1;
		if(cL <= m)
			update(cL,cR,val,L,m,u<<1);
		if(cR > m)
			update(cL,cR,val,m+1,R,u<<1|1);
	}
}

int query(int p,int L,int R,int u,int add)
{
	if(L==R) return num[u] + add;
	int m = (L+R)>>1;
	if(p<=m)
		return  query(p,L,m,u<<1,add+num[u]);
	else
	 	return  query(p,m+1,R,u<<1|1,add+num[u]);
}

void add(int u,int v,int val)
{
	int fu = top[u],fv = top[v] ;
	while(fu!=fv)
	{
		if(deep[fu] < deep[fv])
		{
			swap(fu,fv);
			swap(u,v);
		}
		update(id[fu],id[u],val,1,n,1);
		u = fa[fu],fu = top[u];
	}
	if(deep[u] > deep[v]) swap(u,v);
	update(id[u],id[v],val,1,n,1);
}

int get(int u)
{
	return query(id[u],1,n,1,0) + save[u];
}

void init()
{
	memset(num,0,sizeof num);
	dfs1(1,0,0);
	idx = 1;
	dfs2(1,0,1);
}

int main()
{
    //freopen("test.txt","r",stdin);
	while(scanf("%d%d%d",&n,&m,&q)==3){
		for(int i=1;i<=n;++i) scanf("%d",save+i);
		for(int i=1;i<=n;++i) G[i].clear();
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		init();
		for(int i=0;i<q;++i)
		{
			char s[2];
			scanf("%s",s);
			int u,v,val;

			if(s[0]=='Q')
			{
				scanf("%d",&u);
				printf("%d\n",get(u));
				continue;
			}
			scanf("%d %d %d",&u,&v,&val);
			if(s[0]=='D') val=-val;
			add(u,v,val);
		}
	}
	return 0;
}

