#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n,pn,cnt,b[maxn],fa[maxn];

struct Point{
	int x,y;
	int id;
	bool operator<(const Point& rhs) const
	{
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
} p[maxn];

struct Edge{
	int u,v;
	LL d;
	bool operator<(const Edge& rhs) const
	{
		return d < rhs.d;
	}
} e[maxn<<2];

void addEdge(int u,int v,LL d)
{
	e[cnt].u = u;
	e[cnt].v = v;
	e[cnt++].d = d;
}

struct Bit{
	int mn,pos;
	void init()
	{
		mn = INF;
		pos = -1;
	}
} bit[maxn];

inline int lowbit(int x)
{
	return x&-x;
}

void update(int x,int mn,int pos)
{
	for(int i=x;i>0;i-=lowbit(i))
	{
		if(bit[i].mn > mn)
		{
			bit[i].mn = mn;
			bit[i].pos = pos;
		}
	}
}

int query(int x)
{
	int mn = INF,pos = -1;
	for(int i = x;i<=pn;i+=lowbit(i))
	{
		if(bit[i].mn < mn)
		{
			mn = bit[i].mn;
			pos = bit[i].pos;
		}
	}
	return pos;
}

int find(int x)
{
	return fa[x] == x?x:fa[x] = find(fa[x]);
}

LL solve()
{
	cnt = 0;
	for(int dir = 0;dir<4;++dir)
	{
		if(dir&1) for(int i=0;i<n;++i) swap(p[i].x,p[i].y);
		if(dir == 2) for(int i=0;i<n;++i) p[i].x = -p[i].x;
		sort(p,p+n);
		for(int i=0;i<n;++i) b[i] = p[i].y - p[i].x;
		sort(b,b+n);
		pn = unique(b,b+n) - b;
		for(int i=1;i<=pn;++i) bit[i].init();
		for(int i=n-1;i>=0;--i)
		{
			int pos = lower_bound(b,b+pn,p[i].y - p[i].x) - b + 1;
			int po = query(pos);
			if(po != -1)
				addEdge(p[i].id,p[po].id,abs(p[i].x-p[po].x) + abs(p[po].y-p[i].y));
			update(pos,p[i].y + p[i].x,i);
		}
	}
	LL res = 0;
	for(int i=0;i<n;++i) fa[i] = i;
	sort(e,e+cnt);
	for(int i=0;i<cnt;++i)
	{
		int u = find(e[i].u),v = find(e[i].v);
		if(u != v)
		{
			fa[u] = v;
			res += e[i].d;
		}
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int kase = 1;
	while(scanf("%d",&n) == 1 && n)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d %d",&p[i].x,&p[i].y);
			p[i].id = i;
		}
		LL ans = solve();
		printf("Case %d: Total Weight = %lld\n",kase++,ans);
	}
	return 0;
}

