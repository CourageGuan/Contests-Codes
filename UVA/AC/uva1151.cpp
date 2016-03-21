//也是最小生成树的思想，即先生成一个最小生成树
//然后在树上加入一些权值为0的边(套餐) 再求最小生成树
//所以说算法的思想是非常重要的
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=1000 + 5;
#define POW(n) (n)*(n)

struct Edge{
	int from,to;
	int dist;
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

	void init(int n)
	{
		this->n=n;
		edges.clear();
		anse.clear();
		for(int i=0;i<n;++i) p[i]=i;
	}

	void addedge(int u,int v,int w)
	{
		edges.push_back(Edge(u,v,w));
		m=edges.size();
	}

	int kruskal(bool flag)
	{
		if(flag) sort(edges.begin(),edges.end());
		int ans=0;
		int cnt=n;
		for(int i=0;i<m;++i){
			int x=find(edges[i].from),y=find(edges[i].to);
			if(x!=y) {
				ans+=edges[i].dist; p[x]=y ; if(flag) anse.push_back(i);
				if(--cnt<=1) break;
			}
		}
		return ans;
	}

	void print()
	{
		for(int i=0;i<anse.size();++i)
		{
			printf("%d %d %d\n",edges[anse[i]].from,edges[anse[i]].to,edges[anse[i]].dist);
		}
	}
};

int main()
{
	//freopen("test","r",stdin);
	int kase;
	Kruskal solve;
	scanf("%d",&kase);
	while(kase--){
		int n,q;
		scanf("%d %d",&n,&q);
		vector<int> subnet[10];
		int t,sub;
		int c[10];
		for(int i=0;i<q;++i){
			scanf("%d %d",&t,&c[i]);
			for(int j=0;j<t;++j){
				scanf("%d",&sub);
				subnet[i].push_back(sub);
			}
		}
		solve.init(n);
		int x[maxn],y[maxn];
		for(int i=0;i<n;++i) scanf("%d %d",&x[i],&y[i]);
		int w;
		for(int i=0;i<n-1;++i)
			for(int j=i+1;j<n;++j){
			w=(POW(x[i]-x[j])+POW(y[i]-y[j]));
			solve.addedge(i,j,w);
		}
		int ans=solve.kruskal(1);
		//solve.print();
		vector<Edge> mst;
		for(int i=0;i<solve.anse.size();++i) mst.push_back(solve.edges[solve.anse[i]]);
		for(int i=1;i<(1<<q);++i){
			int bit=i,cur,cnt=0,res=0;
			vector<Edge> ms;
			while(bit>0){
				cur=bit&1;
				bit=(bit>>1);
				if(cur){
					res+=c[cnt];
					for(int j=0;j<subnet[cnt].size()-1;++j)
						for(int k=j+1;k<subnet[cnt].size();++k)
							ms.push_back(Edge(subnet[cnt][j]-1,subnet[cnt][k]-1,0));
				}
				++cnt;
			}
			//cout<<res<<endl;
			solve.init(n);
			for(int i=0;i<ms.size();++i) solve.addedge(ms[i].from,ms[i].to,ms[i].dist);
			for(int i=0;i<mst.size();++i) solve.addedge(mst[i].from,mst[i].to,mst[i].dist);
			res+=solve.kruskal(0);
			//cout<<res<<endl<<endl;
			ans=min(ans,res);
		}
		printf("%d\n",ans);
		if(kase) puts("");
	}
	return 0;
}

