//注释部分为判断任意两点间是否联通
#include<cstdio>
#define min(a,b) ((a)<(b))?(a):(b)

const int INF=0x3f3f3f3f;
const int maxn=1000;
int d[maxn][maxn];
int n,m;

void init()
{
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			d[i][j]=(i==j)?0:INF;	//memset(d,0,sizeof(d))
}

void floyd()
{
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if(d[i][k]<INF && d[k][j]<INF)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]); //d[i][j]=d[i][j] || (d[i][k] && d[k][j]) 
}

int main()
{
	init();
	scanf("%d %d",&n,&m);
	int u,v,w;
	for(int i=0;i<m;++i){
		scanf("%d %d %d",&u,&v,&w);
		d[u][v]=d[v][u]=w;	 //d[u][v]=d[v][u]=1;
	}
	floyd();
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(d[i][j]<INF && i!=j) printf("%d %d: %d\n",i,j,d[i][j]);
	return 0;
}

