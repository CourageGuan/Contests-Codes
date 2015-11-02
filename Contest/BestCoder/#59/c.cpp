//贪心+dp
//我们发现对于相邻的两项两种顺序的得分为
// a[i] - b[i]*c[i] + a[i+1] - b[i+1]*(c[i]+c[i+1]) 和 a[i] - b[i]*(c[i]+c[i+1]) + a[i+1] - b[i+1]*c[i+1]
// 因此每次总要选择一个更优的顺序, 我们移项之后即得到 b[i]*c[i+1] > b[i+1]*c[i]
// 然后按照排序后的顺序再 dp 即可
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int maxn = 1010;
int d[maxn*3];
int n,t;

struct Po
{
	int a,b,c;
	bool operator<(const Po& rhs) const
	{
		 return (LL)b*rhs.c > (LL)rhs.b*c;
	}
} P[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&t);
		for(int i=0;i<n;++i)
		{
			scanf("%d %d %d",&P[i].a,&P[i].b,&P[i].c);
		}
		sort(P,P+n);
		memset(d,0,sizeof d);
		for(int i=0;i<n;++i)
		{
			//printf("%d\n",P[i].a);
			for(int j=t-P[i].c;j>=0;--j)
			{
				d[j+P[i].c] = max(d[j+P[i].c] , d[j]+P[i].a - P[i].b*(j+P[i].c));
			}
		}
		int ans = 0;
		for(int i=0;i<=t;++i) ans = max(ans,d[i]);
		printf("%d\n",ans);
	}
	return 0;
}
