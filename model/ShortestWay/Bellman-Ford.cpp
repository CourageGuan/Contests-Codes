#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=1000;

struct Edge{
	int from,to,dist;
	Edge(int u,int v,int w):from(u),to(v),dist(w) {}
};

struct Spfa{
	int	m,n;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool inq[maxn];
	int	cnt[maxn];
	int d[maxn];
	int p[maxn];

	void init(int n)
	{
		this->n=n;
		for(int i=0;i<n;++i) G[i].clear();
		edges.clear();
	}

	void AddEdge(int u,int v,int w)
	{
		edges.push_back(Edge(u,v,w));
		m=edges.size();
		G[u].push_back(m-1);
	}

	bool spfa(int s)
	{
		queue<int> Q;
		memset(inq,0,sizeof(inq));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;++i) d[i]=INF;
		d[s]=0;inq[s]=1;
		Q.push(s);
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			inq[u]=0;
			for(int i=0;i<G[u].size();++i){
				Edge& e=edges[G[u][i]];
				if(d[u]<INF && d[e.to]>d[u]+e.dist ){
					d[e.to] = d[u]+e.dist;
					p[e.to]=G[u][i];
					if(!inq[e.to]){
						Q.push(e.to);
						inq[e.to]=1;
						if(++cnt[e.to]>n) return false;	//存在负环，不存在最短路
					}
				}
			}
		}
		return true;
	}


	void dprint(int u,int v)
	{
		if(v==u){
			printf("%d",u);
			return;
		}
		dprint(u,edges[p[v]].from);
		printf(" %d",v);
	}

	void print(int u,int v)
	{
		if(d[v]>=INF){ 
			puts("No Way");
			return;
		}
		dprint(u,v);
		printf("\nDist: %d\n",d[v]);
	}
};


int main()
{
	Spfa solve;
	int n,m;
	scanf("%d %d",&n,&m);
	solve.init(n);
	int u,v,w;
	for(int i=0;i<m;++i){
		scanf("%d %d %d",&u,&v,&w);
		solve.AddEdge(u,v,w);
	}
	if(solve.spfa(0)) solve.print(0,4);
	else printf("There is a Negative Loop\n");
	return 0;
}

