//集合dp
//求二分图完备匹配数,即一侧完全匹配
//牛对应二分图的一侧，牛圈对应另一侧
//这里每个牛圈只能放一头牛
#include<cstdio>
#include<cstring>

const int maxn = 30;
int G[maxn][maxn];
int d[1<<20];
int N,M;

inline int cal(int x)
{
	int cnt = 0;
	while(x)
	{
		cnt += (x&1);
		x>>=1;
	}
	return cnt;
}

inline int next(int n)    // n!=0
{
	int x=n&(-n); 
	return n+x+(n^(n+x))/x/4;
}

int dp()
{
	d[0] = 1;
	for(int j=1;j<(1<<M);++j)
	{
		for(int i=1;i<=M;++i)
			if(j & (1<<(i-1)) ) d[j] += d[j-(1<<(i-1))]*G[cal(j)][i];
	}
	int ans = 0;
	for(int j = (1<<N)-1 ; j<(1<<M) ; j=next(j) )
	{
//		printf("%d\n",d[j]);
	   	ans += d[j];
	}
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d",&N,&M)==2)
	{
		memset(G,0,sizeof G);
		for(int i=1;i<=N;++i)
		{
			int P;
			scanf("%d",&P);
			for(int j=0;j<P;++j)
			{
				int x;
				scanf("%d",&x);
				G[i][x] = 1; 
			}
		}
		if(N>M) puts("0");
		else printf("%d\n",dp());
	}
	return 0 ;
}
