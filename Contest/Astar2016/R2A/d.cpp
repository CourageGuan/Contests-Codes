#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxn = 310;
int n,m;
int d[maxn],a[maxn],yes[maxn][maxn],dp[maxn][maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;++i) scanf("%d",a+i);
		for(int i=0;i<m;++i) scanf("%d",d+i);
		memset(yes,0,sizeof yes);
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				for(int k=j+1;k<n;++k)
					if(a[j] + d[i] == a[k]) yes[j][k] = 1; 

		memset(dp,0,sizeof dp);
		for(int L=1;L<n;++L)
		{
			for(int i=0;i+L<n;++i)
			{
				int j = i+L;
				if(yes[i][j] && dp[i+1][j-1] == (j-1==i?0:(j-i-1)))
					dp[i][j] = max(dp[i][j],dp[i+1][j-1]+2);
				if(yes[i][i+1] && dp[i+1][j] == j-i && a[i+1] - a[i] == a[j] - a[j-1])
					dp[i][j] = max(dp[i][j],dp[i+1][j]+1);
				if(yes[j-1][j] && dp[i][j-1] == j-i && a[i+1] - a[i] == a[j] - a[j-1])
					dp[i][j] = max(dp[i][j],dp[i][j-1]+1);
				for(int k=i;k<j;++k)
					dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
		printf("%d\n",dp[0][n-1]);
	}
	return 0;
}
