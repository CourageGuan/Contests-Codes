//noip2010 T2
#include<cstdio>
#include<cstring>

const int maxn = 352;
const int maxm = 41;
int d[maxn][maxm][maxm][maxm];
int a[maxn];
int card[5];

inline void update(int &x,int y)
{
	if(x<y) x = y;
}


int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	while(scanf("%d %d",&n,&m) == 2)
	{
		memset(card,0,sizeof card);
		for(int i=0;i<n;++i) scanf("%d",a+i);
		for(int i=0;i<m;++i)
		{
			int x; scanf("%d",&x);
			++card[x];
		}
		memset(d,0,sizeof card);
		d[0][0][0][0] = a[0];
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<=card[1];++j)
			{
				for(int k=0;k<=card[2];++k)
				{
					for(int t=0;t<=card[3];++t)
					{
						int &ans = d[i][j][k][t];
						if(i-1>=0 && j) update(ans,d[i-1][j-1][k][t]+a[i]);
						if(i-2>=0 && k) update(ans,d[i-2][j][k-1][t]+a[i]);
						if(i-3>=0 && t) update(ans,d[i-3][j][k][t-1]+a[i]);
						if(i-4>=0 ) update(ans,d[i-4][j][k][t]+a[i]);
					}
				}
			}
		}
		printf("%d\n",d[n-1][card[1]][card[2]][card[3]]);
	}
	return 0;
}


