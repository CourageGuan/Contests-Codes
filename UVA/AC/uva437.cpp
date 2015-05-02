//DAG矩阵嵌套模型，每个立方体对应三个矩阵
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int maxn=100;
int n;

struct Edge{
	int a,b,c;
	Edge(int a,int b,int c):a(a),b(b),c(c){}
};

int d[maxn];

vector<Edge> G;

int dp(int i)
{
	int &ans=d[i];
	if(d[i]>0) return ans;
	Edge u=G[i];
	ans=u.c;
	for(int j=0;j<G.size();++j){
		Edge v=G[j];
		if(u.a>v.a && u.b>v.b) ans=max(ans,dp(j)+u.c);
	}
	return ans;
}

int main()
{
	//freopen("test","r",stdin);
	int kase=0;
	while(scanf("%d",&n) && n){
		G.clear();
		int a,b,c;
		for(int i=0;i<n;++i){
			scanf("%d %d %d",&a,&b,&c);
			G.push_back(Edge(min(a,b),max(a,b),c));
			G.push_back(Edge(min(a,c),max(a,c),b));
			G.push_back(Edge(min(b,c),max(b,c),a));
		}
		memset(d,0,sizeof(d));
		int ans=0;
		for(int i=0;i<G.size();++i){
			ans=max(ans,dp(i));
		}
		printf("Case %d: maximum height = %d\n",++kase,ans);
	}
	return 0;
}


