#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;

const int LEN = 33;
LL cnt[3][LEN];
int n;

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		LL s = (LL)n*(n+1)/2,ans[3];

		for(int i=0;i<3;++i) ans[i] = 0;
		memset(cnt,0,sizeof cnt);

		for(int i=0;i<n;++i)
		{	
			int x;
			scanf("%d",&x);
			for(int j=0;j<LEN;++j)
			{
				if(x&1)
				{
					++cnt[0][j];
					cnt[1][j] = i+1;
					cnt[2][j] = i - cnt[2][j] + 1;
				}
				else
				{
					cnt[0][j] = 0;
				}
				x >>= 1;
			}
			LL sum[3];
			memset(sum,0,sizeof sum);
			for(int j=LEN-1;j>=0;--j)
			{
				for(int t=0;t<3;++t)
				{
					sum[t] = (sum[t]<<1) + cnt[t][j];
				}
			}
			for(int t=0;t<3;++t) ans[t] += sum[t];
		}
		//printf("Case #%d: %.6f %.6f %.6f\n",z,ans[0],ans[1],ans[2]);
		printf("Case #%d: %.6lf %.6lf %.6lf\n",z,(double)ans[0]/s,(double)ans[1]/s,(double)ans[2]/s);
	}
	return 0;
}


