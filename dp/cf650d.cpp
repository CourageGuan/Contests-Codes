#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int INF = 0x3f3f3f3f;
const int maxn = 4e5 + 10;
int n,m,lis;
int d[4][maxn],h[maxn],g[maxn],ans[maxn];
map<pair<int,int>,int> vis;

struct P{
	int a,b,id;
	bool operator<(const P& rhs) const {
		return a < rhs.a;
	}
} p[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	F(i,0,n-1) scanf("%d",h+i);
	F(i,0,m-1) scanf("%d %d",&p[i].a,&p[i].b),p[i].a--,p[i].id = i;
	lis = 0;
	memset(g,INF,sizeof g);
	F(i,0,n-1)
	{
		int k = lower_bound(g+1,g+1+n,h[i]) - g;
		d[0][i] = k;
		g[k] = h[i];
		lis = max(lis,k);
	}
	memset(g,INF,sizeof g);
	for(int i=n-1;i>=0;--i)
	{
		int k = lower_bound(g+1,g+1+n,-h[i]) - g;
		d[1][i] = k;
		g[k] = -h[i];
		vis[make_pair(d[0][i],d[1][i])]++;
	}
	sort(p,p+m);
	int j = 0;
	memset(g,INF,sizeof g);
	F(i,0,n-1)
	{
		while(j < m && p[j].a <= i) 
		{
			int k = lower_bound(g+1,g+1+n,p[j].b) - g;
			d[2][j] = k;
			++j;
		}
		if(j >= m) break;
		int k = lower_bound(g+1,g+1+n,h[i]) - g;
		g[k] = h[i];
	}
	j = m-1;
	memset(g,INF,sizeof g);
	for(int i=n-1;i>=0;--i)
	{
		while(j >= 0 && p[j].a >= i)
		{
			int k = lower_bound(g+1,g+1+n,-p[j].b) - g;
			d[3][j] = k;
			--j;
		}
		if(j < 0) break;
		int k = lower_bound(g+1,g+1+n,-h[i]) - g;
		g[k] = -h[i];
	}
//	F(i,0,m-1) printf("%d %d\n",d[2][i],d[3][i]);
	F(i,0,m-1)
	{
		int a = p[i].a;
		ans[p[i].id] = (d[0][a] + d[1][a] -1 == lis && vis[make_pair(d[0][a],d[1][a])] == 1)?lis-1:lis;
		ans[p[i].id] = max(ans[p[i].id],d[2][i]+d[3][i]-1);
	}
	F(i,0,m-1) printf("%d\n",ans[i]);
	return 0;
}
