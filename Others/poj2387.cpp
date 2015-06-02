//裸Dijkstra
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second

const int maxn=1010;
const int INF=0x3f3f3f3f;
int T,N,d[maxn];
bool vis[maxn];

struct Edge{
	int u,v,w;
	Edge(int u=0,int v=0,int w=0):u(u),v(v),w(w) {}
};
vector<int> G[maxn];
vector<Edge> edges; 

void init(){
	for(int i=0;i<=N;++i) G[i].clear();
	memset(vis,0,sizeof vis);
	edges.clear();
}

void addE(int u,int v,int w){
	G[u].push_back(edges.size());
	edges.push_back(Edge(u,v,w));
}


int solve(){
	priority_queue<PII,vector<PII>,greater<PII> > Q;
	memset(d,INF,sizeof d);
	d[1]=0;
	Q.push(mp(0,1));
	while(!Q.empty()){
		PII x=Q.top(); Q.pop();
		int u=x.se;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<G[u].size();++i){
			Edge e=edges[G[u][i]];
			if(d[e.v]>d[u]+e.w){
				d[e.v]=d[u]+e.w;
				Q.push(mp(d[e.v],e.v));
			}
		}
	}
	return d[N];
}

int main()
{
//	freopen("test.txt","r",stdin);
	while(scanf("%d %d",&T,&N)==2){
		int u,v,w;
		init();
		for(int i=0;i<T;++i){
			scanf("%d %d %d",&u,&v,&w);
			addE(u,v,w);
			addE(v,u,w);
		}
		printf("%d\n",solve());
	}
	return 0;
}


