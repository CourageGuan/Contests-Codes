/*map太慢了，换刘汝佳的写法*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define min(a,b) (a<b)?(a):(b)
#define SET(a,t) memset(a,t,sizeof(a))
#define fi first
#define se second
#define pb push_back

typedef pair<int,int> PII;
const int maxn=100000+10;
const int inf=0x7ffffff;
int n;

/*struct ed{
	int u,v,c;
	ed(int u=0,int v=0,int c=0):u(u),v(v),c(c) {}
};*/

vector<int> pic[maxn];
map<PII,int> pii; 

void init()
{
	F(i,1,n) pic[i].clear();
	pii.clear();
}

void bfs()
{
	bool vis[maxn];
	int dis[maxn];
	SET(dis,0);
	SET(vis,0);
	queue<int> nodes;
	nodes.push(n);
	vis[n]=1;
	while(!nodes.empty()){
		int u=nodes.front();
		nodes.pop();
		if(u==1) break;
		F(i,0,pic[u].size()-1){
			int v=pic[u][i];
			if(!vis[v]){
				dis[v]=dis[u]+1;
				vis[v]=1;
				nodes.push(v);
			}
		}
	}
	printf("%d\n",dis[1]);
	while(!nodes.empty()) nodes.pop();
	nodes.push(1);
	SET(vis,0);
	vis[1]=1;
	int cnt=0,ans[maxn];
	while(!nodes.empty()){
		int u=nodes.front();
		nodes.pop();
		if (u==n) break;
		int d=dis[u]-1;
		int as=inf;
		F(i,0,pic[u].size()-1){
			int v=pic[u][i];
			if(dis[v]==d){
				vis[v]=1;
				PII p(u,v);
				if (pii[p]<=as){
					as=pii[p];		
					//printf("(%d,%d) ",p.fi,p.se);
					/*if(!nodes.empty()){
						PII pp(u,nodes.front());
						if(pii[pp]>pii[p]) nodes.pop();
					}*/
					nodes.push(v);
				}
			}
		}
		ans[d]=(ans[d]==0)?as:min(ans[d],as);
		//printf("%d %d,",d,as);
	}
	int j=dis[1];
	while(j--){
		printf("%d",ans[j]);
		if(j) printf(" ");
		else printf("\n");
	}
}

int main()
{
	//freopen("test","r",stdin);
	int m;
	while(scanf("%d %d",&n,&m)==2){
		init();
		F(i,1,m){
			int u,v,c;
			scanf("%d %d %d",&u,&v,&c);
			PII p1(u,v),p2(v,u);
			pii[p1]=(pii[p1])?min(pii[p1],c):c;
			pii[p2]=pii[p1];
			pic[u].pb(v);
			pic[v].pb(u);
		}
		bfs();
	}
	return 0;
}

