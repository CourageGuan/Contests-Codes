#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 55;
int g[maxn][maxn],cnt[maxn],n;

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j) scanf("%d",&g[i][j]);
	int re = n;
	for(int i=0;i<n;++i)
	{
		memset(cnt,0,sizeof cnt);
		for(int j=0;j<n;++j)
		{
			if(i == j) continue;
			++cnt[g[i][j]];
		}
		bool flag = false;
		for(int j=1;j<=n;++j)
		{
			if(cnt[j]>1)
			{
				flag = true;
				printf("%d ",j);
				break;
			}
		}
		if(!flag) printf("%d ",re),--re; 
	}
	return 0;
}
