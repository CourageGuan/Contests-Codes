#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

using namespace std;
#define lowbit(x) ((x) & -(x))

const int maxn = 505;
int b[maxn][maxn],a[maxn][maxn];
int n,m,q;

inline void update(int x,int y,int v)
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=m;j+=lowbit(j))
			b[i][j] ^= v;
}

inline int query(int x,int y)
{
	int res = 0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			res ^= b[i][j];
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);

		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				scanf("%d",&a[i][j]);
				b[i][j] = 0;
			}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				update(i,j,a[i][j]);
			}
		while(q--)
		{
			int op;
			int x1,y1,x2,y2,v;
			scanf("%d",&op);
			if(op == 1)
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				int t = 0;

				t ^= query(x2,y2);
				t ^= query(x2,y1-1);
				t ^= query(x1-1,y2);
				t ^= query(x1-1,y1-1);

				puts(t?"Yes":"No");
			}
			else
			{
				scanf("%d %d %d",&x1,&y1,&v);
				update(x1,y1,a[x1][y1]^v);
				a[x1][y1] = v;
			}
		}
	}
	return 0;
}


