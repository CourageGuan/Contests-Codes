#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1010;
int a[maxn];

int main()
{
	int T;
	int n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d",a+i);
		int ans = 0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(j == i) continue;
				for(int k=j+1;k<n;++k)
				{
					if(k == i)  continue;
					ans = max(ans,(a[j]+a[k])^a[i]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
