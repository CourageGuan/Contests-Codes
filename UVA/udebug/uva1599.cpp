/*和汝佳写的几乎一模一样，还是TLE，待解决。。。*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define min(a,b) (a<b)?(a):(b)
#define SET(a,t) memset(a,t,sizeof(a))
#define pb push_back

const int maxn=100000+10;
const int inf=0x7ffffff;
int n;

struct ed{
	int u,v,c;
	ed(int u=0,int v=0,int c=0):u(u),v(v),c(c) {}
};

vector<int> pic[maxn];
vector<ed> e;
bool vis[maxn];
int dis[maxn];

void bfs1()
{
	SET(vis,0);
	queue<int> nodes;
	nodes.push(n);
	vis[n]=1;
	dis[n]=0;
	while(!nodes.empty()){
		int u=nodes.front();
		nodes.pop();
		F(i,0,pic[u].size()-1){
			int v=e[pic[u][i]].v;
			if(!vis[v]){
				dis[v]=dis[u]+1;
				vis[v]=1;
				nodes.push(v);
			}
		}
	}
}

vector<int> ans;

void bfs2()
{
	ans.clear();
	vector<int> next;
	next.pb(1);
	SET(vis,0);
	vis[1]=1;
	F(i,1,dis[1]){
		int as=inf;
		F(k,0,next.size()-1){
			int u=next[k];
			int d=dis[u]-1;
			F(i,0,pic[u].size()-1){
				int v=e[pic[u][i]].v,c=e[pic[u][i]].c;
				if(dis[v]==d)
					as=min(c,as);
			}
		}
		ans.pb(as);
		vector<int> next2;
		F(k,0,next.size()-1){
			int u=next[k];
			int d=dis[u]-1;
			F(i,0,pic[u].size()-1){
				int v=e[pic[u][i]].v,c=e[pic[u][i]].c;
				if(dis[v]==d && c==as && !vis[v])
					vis[v]=1;
					next2.pb(v);
			}
		}
		next=next2;
	}
	printf("%d\n",ans.size());
	F(j,0,ans.size()-1){
		if(j) printf(" ");
		printf("%d",ans[j]);
	}
	puts("");
}

int main()
{
	//freopen("test","r",stdin);
	int m;
	while(scanf("%d%d",&n,&m)==2){
		F(i,0,n) pic[i].clear();
		e.size();
		while(m--){
			int u,v,c;
			scanf("%d %d %d",&u,&v,&c);
			e.pb(ed(u,v,c));	
			pic[u].pb(e.size()-1);
			e.pb(ed(v,u,c));
			pic[v].pb(e.size()-1);
		}
		bfs1();
		bfs2();
	}
	return 0;
}

