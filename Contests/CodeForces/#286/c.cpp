#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 30010;
const int mid = 250;
int P[maxn],n,d;
int dp[maxn][500];

int main()
{
	//freopen("test.txt","r",stdin);

	scanf("%d %d",&n,&d);
	memset(P,0,sizeof P);

	int mx = 0;
	for(int i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		mx = max(x,mx);
		++P[x];
	}

	int ans;

	memset(dp,0,sizeof dp);
	ans = dp[d][mid] = P[d]+1;

	for(int i=d;i<=mx;++i)
	{
		for(int j=-mid;j<mid;++j)
		{
			int s = d+j;
			if(s<=0) continue;
			if(i+s-1 > mx) break;

			if(dp[i][j+mid])
			{
				if(i+s-1 <= mx)
				{
					if(s-1>=1)
					{
						dp[i+s-1][j-1+mid] = max(dp[i][j+mid]+P[i+s-1] , dp[i+s-1][j-1+mid]);
						ans = max(ans,dp[i+s-1][j-1+mid]);
					}
				}
				else continue;

				if(i+s <= mx)
				{
					dp[i+s][j+mid] = max(dp[i][j+mid]+P[i+s],dp[i+s][j+mid]);
					ans = max(ans,dp[i+s][j+mid]);
				}
				else continue;

				if(i+s+1 <= mx)
				{
					dp[i+s+1][j+1+mid] = max(dp[i][j+mid]+P[i+s+1],dp[i+s+1][j+1+mid]);
					ans = max(ans,dp[i+s+1][j+1+mid]);
				}
			}
		}
	}

	printf("%d\n",ans-1);
	return 0;
}
