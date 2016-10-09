#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;
int n,m,K;

struct Edge
{
    int from,to,cap,flow,cost;
    Edge(int u,int v,int c,int f,int w):
        from(u),to(v),cap(c),flow(f),cost(w) {}
};

struct MCMF
{
    int n;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];

    void init(int n)
    {
        this-> n = n;
        for(int i = 0;i <= n;++i) G[i].clear();
        edges.clear();
    }

    void addEdge(int from,int to,int cap,int cost)
    {
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        int m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BellmanFord(int s,int t,int& flow,int& cost)
    {
        memset(d,INF,sizeof(d));
        memset(inq,0,sizeof(inq));
        d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;

        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            for(int i = 0;i < G[u].size();++i)
            {
                Edge& e = edges[G[u][i]];
                if(e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u],e.cap-e.flow);
                    if(!inq[e.to])
                    {
                        Q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if(d[t] == INF) return false;
        flow += a[t];
        cost += d[t]*a[t];
        int u = t;
        while(u != s)
        {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    int getRes(int s,int t)
    {
        int flow = 0,cost = 0;
        while(BellmanFord(s,t,flow,cost));
        return cost;
    }
} mfmc;

int need[maxn][maxn],have[maxn][maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	while(~scanf("%d %d %d",&n,&m,&K) && n+m+K)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<K;++j) scanf("%d",&need[i][j]);
		for(int i=0;i<m;++i)
			for(int j=0;j<K;++j) scanf("%d",&have[i][j]);
		int ans = 0;
		for(int k=0;k<K;++k)
		{
			int s = 0,t = n + m + 1,hv,nd;
			hv = nd = 0;
			for(int i=0;i<n;++i) nd += need[i][k];
			for(int i=0;i<m;++i) hv += have[i][k];
//			printf("%d %d\n",hv,nd);
			if(hv < nd)	ans = -1;
			mfmc.init(t);
			for(int i=0;i<n;++i)
				mfmc.addEdge(s,i+1,need[i][k],0);
			for(int i=0;i<n;++i)
				for(int j=0;j<m;++j)
				{
					int c;
					scanf("%d",&c);
					mfmc.addEdge(i+1,j+1+n,INF,c);
				}
			if(ans == -1) continue;
			for(int i=0;i<m;++i)
				mfmc.addEdge(i+1+n,t,have[i][k],0);
			ans += mfmc.getRes(s,t);
		}
		printf("%d\n",ans);
	}
	return 0;
}
