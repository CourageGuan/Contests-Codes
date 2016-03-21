//双塔dp 
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 5000010;
const int INF = 0x3f3f3f3f;
int d[2][maxn],b[100],sum[100];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%d",b+i);
		}

		sort(b+1,b+n+1);

		sum[1] = b[1];
		for(int i=2;i<=n;++i)
		{
			sum[i] = sum[i-1] + b[i];
		}

		for(int j=0;j<=sum[n];++j) d[0][j] = -INF;
		d[0][0] = 0;

		for(int i=1;i<=n;++i)
		{
			int t=i&1;
			memset(d[t],-INF,sum[n]*sizeof(d[0][0]));
			for(int j=0;j<=sum[i];++j)
			{
				d[t][j+b[i]] = max(d[t][j+b[i]],d[t^1][j]+b[i]);
				d[t][abs(j-b[i])] = max(d[t][abs(j-b[i])],d[t^1][j]+b[i]);
				d[t][j] = max(d[t][j],d[t^1][j]);
			}
		}
		
		if(d[n&1][0]/2 <= 0) puts("-1"); 
		else printf("%d\n",d[n&1][0]/2);	
	}
	return 0;
}
