#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fi first
#define se second

const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 1e5 + 10;

vector<pair<int,int> > G[maxn];
LL sum[maxn],d[maxn];
int q[maxn],tmp[maxn];
int sz[maxn],f[maxn],fa[maxn],vis[maxn];
int n,p,r,size,root;

void dfs(int u)
{
    for(int i=0;i<G[u].size();++i)
    {
        int v = G[u][i].fi;
        sum[v] = sum[u] + G[u][i].se;
        dfs(v);
        fa[v] = u;
    }
}

void getroot(int u)
{
    sz[u] = 1;
    f[u] = 0;
    int v;
    for(int i=0;i<G[u].size();++i)
        if(!vis[v = G[u][i].fi]) 
            getroot(v),sz[u] += sz[v],f[u] = max(f[u],sz[v]);
    f[u] = max(f[u],size - sz[u]);
    if(f[u] < f[root]) root = u;
}

inline void upd(int u,int v)
{
    d[u] = min(d[u],d[v] + (sum[u]-sum[v])*(sum[u]-sum[v]) + p);
}

inline double slope(int j,int i)
{
    return (double)(d[i]-d[j]+sum[i]*sum[i]-sum[j]*sum[j])/(double)(sum[i]-sum[j]);
}

inline void cal(int u)
{
    int L = 1,R = r - 1,res = q[r];
    while(L <= R)
    {
        int m = L+R>>1;
        if(slope(q[m],q[m+1]) >= 2.0*sum[u])
            res = q[m],R = m-1;
        else
            L = m+1;
    }
    upd(u,res);
}

void cal1(int u)
{
    cal(u);
    int v;
    for(int i=0;i<G[u].size();++i) if(!vis[v=G[u][i].fi]) cal1(v);
}

void cal2(int u,int rt)
{
    upd(u,rt);
    int v;
    for(int i=0;i<G[u].size();++i) if(!vis[v=G[u][i].fi]) cal2(v,rt);
}

void gao(int u)
{
	size = f[0] = sz[u];
	root = 0;
	getroot(u);
	int rt=root,v;
	if(rt == u)
	{
		for(int i=0;i<G[u].size();++i)
			if(!vis[v = G[u][i].fi]) 
				cal2(v,u),gao(v);
	}
	else
	{
		vis[rt] = 1;
		gao(u);
		int t=rt,l;
		l = r = 0;
		do tmp[++l] = t = fa[t]; while(t != u);
		for(int i=l;i>=1;--i)
		{
			while(r-1 >= 1 && slope(q[r-1],q[r]) > slope(q[r],tmp[i])) --r;
			q[++r] = tmp[i];
		}
		if(rt != 1) cal(rt);
		while(r-1 >= 1 && slope(q[r-1],q[r]) > slope(q[r],rt)) --r;
		q[++r] = rt;
		for(int i=0;i<G[rt].size();++i) if(!vis[v = G[rt][i].fi]) cal1(v);
		for(int i=0;i<G[rt].size();++i) if(!vis[v = G[rt][i].fi]) vis[v]=1,gao(v);
	}
}

void init(int n)
{
    F(i,1,n) G[i].clear();
    memset(vis,0,sizeof vis);
    memset(d,INF,sizeof d);
    d[1] = -p;
    sz[1] = n;
    fa[1] = 1;
}

const int BUF=40000000;
char Buf[BUF],*buf=Buf;
inline void read(int&a){for(a=0;*buf<48;buf++);while(*buf>47)a=a*10+*buf++-48;}

int main()
{
    //freopen("input.txt","r",stdin);
    fread(Buf,1,BUF,stdin);
    int T;
    read(T);
    F(z,1,T)
    {
        read(n);
        read(p);
        init(n);
        F(i,1,n-1)
        {
            int u,v,w;
            read(u);
            read(v);
            read(w);
            G[u].push_back(make_pair(v,w));
        }
        dfs(1);
        gao(1);
        LL ans = 0;
		F(i,2,n) ans = max(ans,d[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
