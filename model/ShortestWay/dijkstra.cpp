#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=1000,maxm=1000;

struct Edge{
	int from,to,dist;
	Edge(int u,int v,int d):from(u),to(v),dist(d) {}
};

struct HeapNode{
	int d,u;
	HeapNode(int _d,int _u): d(_d),u(_u) {}
	bool operator <(const HeapNode& rhs) const {
		return d>rhs.d;
	}
};

struct Dijkstra{
	int m,n;
	vector<Edge> edges;		//存边
	vector<int> G[maxn];	//存边编号
	bool done[maxn];		//访问标记
	int d[maxn];			//s到各个节点距离
	int p[maxn];			//与父节点连接边编号

	void init(int n)
	{
		this->n=n;
		for(int i=0;i<n;++i) G[i].clear();
		edges.clear();
	}

	void AddEdge(int from,int to,int dist)
	{
		edges.push_back(Edge(from,to,dist));	
		m=edges.size();
		G[from].push_back(m-1);
	}

	void dijkstra(int s)
	{
		priority_queue<HeapNode> Q;
		for(int i=0;i<n;++i) d[i]=INF;
		d[s]=0;
		memset(done,0,sizeof(done));
		Q.push(HeapNode(0,s));
		while(!Q.empty()){
			HeapNode x=Q.top();Q.pop();
			int u=x.u;
			if(done[u]) continue;
			done[u]=1;
			for(int i=0;i<G[u].size();++i){
				Edge& e=edges[G[u][i]];
				if(d[e.to]>d[u]+e.dist){
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					Q.push(HeapNode(d[e.to],e.to));
				}
			}
		}
	}

	void dprint(int u,int v)
	{
		if(v==u){
			printf("%d",u); 
			return ;
		}
		dprint(u,edges[p[v]].from);
		printf(" %d",v);
	}

	void print(int u,int v)
	{
		if(d[v]>=INF) printf("No Way\n");
		else{
			dprint(u,v);
			printf("\nDist: %d\n",d[v]);
		}
	}
};

int main()
{
	Dijkstra solve;
	int m,n;
	scanf("%d %d",&n,&m);
	solve.init(n);
	int u,v,w;
	for(int i=0;i<n;++i){
		scanf("%d%d%d",&u,&v,&w);
		solve.AddEdge(u,v,w);
	}
	solve.dijkstra(0);
	solve.print(0,4);
	return 0;
}

