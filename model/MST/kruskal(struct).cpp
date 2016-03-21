#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1000 + 5;

struct Edge{
	int from,to,dist;
	bool operator<(const Edge& rhs) const {
		return dist<rhs.dist;
	}

	Edge(int u,int v,int w) : from(u),to(v),dist(w) {}
};

struct Kruskal{
	int n,m;
	vector<Edge> edges;
	vector<int> anse;
	int p[maxn];

	int find(int x) { return (p[x]==x)?x:p[x]=find(p[x]);};

	void init(int n,int m)
	{
		this->n=n;
		this->m=m;
		edges.clear();
		anse.clear();
		for(int i=0;i<n;++i) p[i]=i;
	}

	void addedge(int u,int v,int w,int id)
	{
		edges.push_back(Edge(u,v,w,id));
	}

	int kruskal()
	{
		sort(edges.begin(),edges.end());
		int ans=0,cnt=n;
		for(int i=0;i<m;++i){
			int x=find(edges[i].from),y=find(edges[i].to);
			if(x!=y) {
				ans+=edges[i].dist; p[x]=y ; anse.push_back(i); 
				if(--cnt<=1) break;
			}
		}
		return ans;
	}

	void print()
	{
		for(int i=0;i<anse.size();++i)
		{
			printf("%d %d\n",edges[anse[i]].from,edges[anse[i]].to);
		}
	}
};

int main()
{
	//freopen("test","r",stdin);
	int n,m;
	Kruskal solve;
	scanf("%d %d",&n,&m);
	solve.init(n,m);
	int u,v,w;
	for(int i=0;i<m;++i){
		scanf("%d %d %d",&u,&v,&w);
		solve.addedge(u,v,w);
	}
	printf("%d\n",solve.kruskal());
	solve.print();
	return 0;
}

