/*dfs实现拓扑排序，题目保证了DAG(有向无环图),未保证则需判断*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=123;

int G[maxn][maxn],n,m,cnt;
int has_ar[maxn],bs[maxn];


void init()
{
	memset(G,0,sizeof(G));
	memset(has_ar,0,sizeof(has_ar));
	memset(bs,0,sizeof(bs));
}

void dfs(int u)
{
	has_ar[u]=1;
	for(int i=1;i<=n;++i){
		if(G[u][i] && !has_ar[i] && u!=i)
			dfs(i);
	}
	bs[cnt--]=u;
}

int main()
{
	//freopen("test","r",stdin);
	while(cin>>n>>m && n){
		init();
		for(int i=1;i<=m;++i){
			int x,y;
			cin>>x>>y;
			G[x][y]=1;
		}
		cnt=n;
		for(int i=1;i<=n;++i)
			if(!has_ar[i])
				dfs(i);
		for(int i=1;i<=n;++i){
			cout<<bs[i];
			if(i!=n) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}



