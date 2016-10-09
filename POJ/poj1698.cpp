#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 100;
const int INF = 0x3f3f3f3f;
int n;
int G[10],mx[10];

struct Edge
{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f) {}
};

struct Dinic
{
    int s,t;
    vector<int> G[maxn];
    vector<Edge> edges;
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];


    void init()
    {
        for(int i = 0;i <= maxn;++i) G[i].clear();
        edges.clear();
    }

    void addEdge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        int m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS()
    {
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();
            for(int i = 0;i < G[u].size();++i)
            {
                Edge& e = edges[G[u][i]];
                if(!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[u] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a)
    {
        if(x == t || a == 0) return a;
        int flow = 0,f;
        for(int& i = cur[x];i < G[x].size();++i)
        {
            Edge&e = edges[G[x][i]];
            if(d[x] +1 == d[e.to] &&
                (f = DFS(e.to,min(a,e.cap-e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        return flow;
    }

    int getRes(int s,int t)
    {
        this-> s = s; this->t = t;
        int flow = 0;
        while(BFS())
        {
            memset(cur,0,sizeof(cur));
            flow += DFS(s,INF);
        }
        return flow;
    }
} flow;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int s = 0,t = n+7+1,wk = 0,sum = 0;
		flow.init();
		memset(mx,0,sizeof mx);
		for(int i=0;i<n;++i)
		{
			int d,w;
			for(int j=0;j<7;++j) scanf("%d",&d),G[j] = d;
			scanf("%d %d",&d,&w);
			flow.addEdge(i+7+1,t,d);
			for(int j=0;j<7;++j) if(G[j])
			{
			   	flow.addEdge(j+1,i+7+1,w);
				mx[j] = max(mx[j],w); 
			}
			sum += d;
		}
		for(int i=1;i<=7;++i) flow.addEdge(s,i,mx[i-1]);
		int ans = flow.getRes(s,t);
		puts(ans == sum?"Yes":"No");
	}
	return 0;
}
