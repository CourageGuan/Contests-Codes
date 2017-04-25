#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 55;
int pic[maxn][maxn];

int main()
{
//	freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		memset(pic,0,sizeof pic);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j) scanf("%d",&pic[i][j]);
		}
		int ans = 0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j) 
			{
				if(pic[i][j]) ++ans;
				ans += max(0,pic[i][j] - pic[i+1][j]); 
				ans += max(0,pic[i][j] - pic[i-1][j]); 
				ans += max(0,pic[i][j] - pic[i][j+1]); 
				ans += max(0,pic[i][j] - pic[i][j-1]); 
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
