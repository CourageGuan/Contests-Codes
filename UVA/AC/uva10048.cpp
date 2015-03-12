//求两点间的一条路径使其边的最大值最小
//用了floyd的特性，经过两点间的每一条路径，既可以在联通的路径中找到边的最大值
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=100+10;
const int INF=0x3f3f3f3f;
int C,S,Q;
int pic[maxn][maxn];

void init()
{
	for(int i=1;i<=C;++i)
		for(int j=1;j<=C;++j)
			pic[i][j]=INF;
}

void floyd()
{
	for(int k=1;k<=C;++k)
		for(int i=1;i<=C;++i)
			for(int j=1;j<=C;++j)
				if(pic[i][k]<INF && pic[k][j]<INF)
					pic[i][j]=min(pic[i][j],max(pic[i][k],pic[k][j]));
}

int main()
{
	//freopen("test","r",stdin);
	int kase=0;
	while(scanf("%d %d %d",&C,&S,&Q) && C){
		int u,v,w;
		init();
		if (kase) puts("");
		for(int i=0;i<S;++i){
			scanf("%d %d %d",&u,&v,&w);
			pic[u][v]=pic[v][u]=w;
		}
		floyd();
		printf("Case #%d\n",++kase);
		while(Q--){
			scanf("%d %d",&u,&v);
			if(pic[u][v]>=INF) puts("no path");
			else printf("%d\n",pic[u][v]);
		}
	}
	return 0;
}

