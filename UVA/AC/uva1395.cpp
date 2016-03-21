//用了最小生成树的思想 求一颗最小生成树使   w=最大边-最小边 最小
//先把所有边从小到大排序，然后顺序选取，直至所有点都在树上
//这里先从左至右枚举边，然后从这条边接着枚举，直至所有边都在树上，此时比较ans于当前w
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=100 + 5;
const int INF=0x3f3f3f3f;

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

	int find(int x) { return p[x]==x ? x:p[x]=find(p[x]);}

	void init(int n,int m)
	{
		this->n=n;
		this->m=m;
		edges.clear();
		for(int i=1;i<=n;++i) p[i]=i;
	}

	void addedge(int u,int v,int w)
	{
		edges.push_back(Edge(u,v,w));
	}

	int kruskal()
	{
		sort(edges.begin(),edges.end());
		int ans=INF;
		for(int l=0;l<m;++l){
			for(int i=1;i<=n;++i) p[i]=i;
			int cnt=n;
			for(int r=l;r<m;++r){
				int x=find(edges[r].from),y=find(edges[r].to);
				if(x!=y) {
					p[x]=y ; 
					if(--cnt==1) {
						ans=min(ans,edges[r].dist-edges[l].dist);
						break;
					}
				}
			}
		}
		return (ans==INF)?-1:ans;
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
	Kruskal solve;
	int n,m;	
	while(scanf("%d %d",&n,&m) && n){
		solve.init(n,m);
		int u,v,w;
		for(int i=0;i<m;++i){
			scanf("%d %d %d",&u,&v,&w);
			solve.addedge(u,v,w);
		}
		printf("%d\n",solve.kruskal());
	}
	return 0;
}

