#include<bits/stdc++.h>
using namespace std;
typedef double DB;

#define f(i,a,b) for(int i=(a);i<=(b);++i)

const DB eps = 1e-12;
const int maxn = 5010;
const DB INF = 1e15;

struct edge
{
    int from,to;
	DB cap,flow;
    edge(int u,int v,DB c,DB f):from(u),to(v),cap(c),flow(f) {}
};

struct dinic
{
    int s,t;
    vector<int> g[maxn];
    vector<edge> edges;
    bool vis[maxn];
    DB d[maxn];
    int cur[maxn];


    void init()
    {
        for(int i = 0;i <= maxn;++i) g[i].clear();
        edges.clear();
    }

    void addedge(int from,int to,DB cap)
    {
        edges.push_back(edge(from,to,cap,0));
        edges.push_back(edge(to,from,0,0));
        int m = edges.size();
        g[from].push_back(m-2);
        g[to].push_back(m-1);
    }

    bool bfs()
    {
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            for(int i = 0;i < g[u].size();++i)
            {
                edge& e = edges[g[u][i]];
                if(!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    DB dfs(int x,DB a)
    {
        if(x == t || a == 0) return a;
        DB flow = 0,f;
        for(int& i = cur[x];i < g[x].size();++i)
        {
            edge& e = edges[g[x][i]];
            if(d[x] +1 == d[e.to] &&
                (f = dfs(e.to,min(a,e.cap-e.flow))) > 0)
            {
                e.flow += f;
                edges[g[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        return flow;
    }

    DB getres(int s,int t)
    {
        this-> s = s; this->t = t;
        DB flow = 0;
        while(bfs())
        {
            memset(cur,0,sizeof(cur));
            flow += dfs(s,INF);
        }
        return flow;
    }
} flow;

int n,m,s,t;
int p[maxn],d[maxn];
vector<pair<int,int> > P;

DB build(DB p)
{
	flow.init();
	f(i,1,n) flow.addedge(s,i,m),flow.addedge(i,t,m + 2*p - d[i]);
	f(i,0,P.size()-1) flow.addedge(P[i].second,P[i].first,1),flow.addedge(P[i].first,P[i].second,1);
	return n*m - flow.getres(s,t);

}

void dfs(int u)
{
	flow.vis[u] = 1;
	f(i,0,flow.g[u].size()-1)
	{
		int p = flow.g[u][i];
		int v = flow.edges[p].to;
		if(flow.edges[p].flow < flow.edges[p].cap && !flow.vis[v]) dfs(v);
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	f(z,1,T)
	{
		scanf("%d",&n);
		f(i,1,n) scanf("%d",p+i);

		P.clear();
		memset(d,0,sizeof(d));
		f(i,1,n)
		{
			f(j,i+1,n)
				if(p[i] > p[j])
				{
					P.push_back(make_pair(p[i],p[j]));
					d[p[i]]++;
					d[p[j]]++;
				}
		}
		m = P.size();
		if(m == 0) 
		{
			printf("Case #%d: %.10f\n",z,0.0);
			//printf("Case #%d: %.10f\n",z,0);
			continue;
		}
		s = 0,t = n + 1;
		DB l = 0,r = m;
		while(r - l >= 1.0/n/n)
		{
			DB m = (l+r)/2;
			if(build(m) < eps) r = m;
			else l = m;
		}
		build(l);
		flow.getres(s,t);
		memset(flow.vis,0,sizeof(flow.vis));
		dfs(s);
		DB down = 0,up = 0;
		f(i,1,n) if(flow.vis[i]) ++down;
		f(i,0,P.size()-1) if(flow.vis[P[i].first] && flow.vis[P[i].second]) ++up;
//		printf("%d %d\n",up,down);
		printf("Case #%d: %.10f\n",z,up/down);
	}
	return 0;
}
