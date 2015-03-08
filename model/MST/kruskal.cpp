#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=1000 + 5;
int p[maxn],w[maxn],r[maxn],u[maxn],v[maxn];	//并查集 边权值 边 边左节点 边右节点
int n,m; // n个点  m条边

bool cmp(const int i,const int j) {return w[i]<w[j];}
int find(int x) {return (p[x]==x)?x:p[x]=find(p[x]);}	//并查集find

int kruskal()
{
	int ans=0;
	vector<int> anse;
	for(int i=0;i<n;++i) p[i]=i;
	for(int i=0;i<m;++i) r[i]=i;
	sort(r,r+m,cmp);
	for(int i=0;i<m;++i){
		int e=r[i];
		int x=find(u[e]),y=find(v[e]);
		if(x!=y) {ans+=w[e]; p[x]=y; anse.push_back(e); }
	}
	for(int i=0;i<anse.size();++i) printf("%d %d\n",u[anse[i]],v[anse[i]]);
	return ans;
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i) scanf("%d %d %d",&u[i],&v[i],&w[i]);
	printf("%d\n",kruskal());
	return 0;
}


