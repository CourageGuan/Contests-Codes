#include<bits/stdc++.h>
using namespace std;
typedef double DB;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define mp make_pair
#define fi first
#define se second

const LL INF = 0x3f3f3f3f;
const int maxn = 2010;
const int maxm = 2e4 + 10;

struct Edge{
	int u,v,w;
	Edge(int u,int v,int w):u(u),v(v),w(w) {}
	Edge() {}
};

vector<int> G[maxn];
vector<Edge> edges,saves;
LL d[maxn],U[maxm],V[maxm],W[maxm];
int inq[maxn];

int n,m,L,s,t,tot;

void addEdge(int u,int v,int w)
{
	if(w == 0)
	{
		w = -(++tot);
		U[tot] = u;
		V[tot] = v;
	}
	edges.push_back(Edge(u,v,w));
	int m = edges.size();
	G[u].push_back(m-1);
}

LL Dijkstra(int s,int t)
{
	priority_queue<pair<LL,int> > Q;
	memset(d,INF,sizeof d);
	d[s] = 0;
	memset(inq,0,sizeof inq);
	Q.push(mp(0,s));
	while(Q.size())
	{
		pair<int,int> x = Q.top(); Q.pop();
		int u = x.se;
		inq[u] = 0;
		for(int i=0;i<G[u].size();++i)
		{
			Edge& e = edges[G[u][i]];
			int w = e.w;
			if(w < 0) w = W[-w];
			if(d[e.v] > d[u]+w)
			{
				d[e.v] = d[u] + w;
				if(!inq[e.v]) Q.push(mp(-d[e.v],e.v));
			}
		}
	}
	return d[t];
}

LL check(int p)
{
	F(i,1,2*p) W[i] = 1;
	F(i,2*p+1,tot) W[i] = INF;
	LL res = Dijkstra(s,t);
	return res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d %d %d %d %d",&n,&m,&L,&s,&t);
	F(i,1,m)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		addEdge(u,v,w);
		addEdge(v,u,w);
		saves.push_back(Edge(u,v,w));
	}
	if(check(tot/2) > L || check(0) < L)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int l = 1,r = tot/2,res = tot/2 + 1;
	while(l <= r)
	{
		int mid = (l+r)>>1;
		if(check(mid) <= L)
		{
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	W[2*res] = W[2*res-1] = 1 + L - check(res);
//	printf("%lld\n",Dijkstra(s,t));
	int cnt = 1;
	for(auto it: saves)
		printf("%d %d %lld\n",it.u,it.v,it.w?it.w:W[2*(cnt++)-1]);
	return 0;
}
