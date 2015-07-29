//双塔dp d[i][j]　表示前i个任务 a-b = j时的最少时间
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;
const int BASE = 100;
int n;
int d[maxn][2*maxn],ta[maxn],tb[maxn];

	

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);

		for(int i=1;i<=n;++i) scanf("%d %d",ta+i,tb+i);

		memset(d,INF,sizeof d);

		d[0][BASE] = 0;

		for(int i=1;i<=n;++i)
		{
			for(int j=-BASE;j<=BASE;++j)
			{
				if(d[i-1][j+BASE]==INF) continue;
				if(j>=0)	//a较高
				{	
					d[i][ta[i]+BASE] = min(d[i][ta[i]+BASE],d[i-1][j+BASE]+ta[i]);	//继续放a,注意此时b比a低，b到a的这段空闲时间不能跳过,所以从a,b等高开始加
					d[i][j-tb[i]+BASE] = min(d[i][j-tb[i]+BASE],d[i-1][j+BASE]+max(0,tb[i]-j));//放b，b的高度超过a则加超过部分，否则不加
				}
				else
				{
					d[i][-tb[i]+BASE] = min(d[i][-tb[i]+BASE],d[i-1][j+BASE]+tb[i]); //继续放b,道理同上
					d[i][j+ta[i]+BASE] = min(d[i][j+ta[i]+BASE],d[i-1][j+BASE]+max(0,ta[i]+j));//放a道理同上
				}
			}
		}

		int ans = INF;
		for(int i=-BASE;i<=BASE;++i) ans=min(ans,d[n][BASE+i]);
		printf("%d\n",ans);
	}
	return 0;
}


