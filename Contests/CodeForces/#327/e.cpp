#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1010;
char s[maxn][maxn];
int dp[3][maxn][maxn];

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0}; 

int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i) scanf("%s",s[i]);
	memset(dp,INF,sizeof dp);
	for(int k=0;k<3;++k)
	{
		queue<pair<int,int> > Q;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				if(s[i][j] == '1'+k)
				{
					Q.push(make_pair(i,j));
					dp[k][i][j] = 0;
				}
			}

		while(!Q.empty())
		{
			pair<int,int> u = Q.front(); Q.pop();
			for(int i=0;i<4;++i)
			{
				int tx = u.first + dx[i],ty = u.second + dy[i];
				if(tx>=0 && ty>=0 && tx<n && ty<m && s[tx][ty]!='#' && dp[k][u.first][u.second] + (s[u.first][u.second]=='.') < dp[k][tx][ty])
				{
					dp[k][tx][ty] = dp[k][u.first][u.second]+ (s[u.first][u.second]=='.');
					Q.push(make_pair(tx,ty));
				}
			}
		}
	}
	int ans = INF;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			if(dp[0][i][j] < INF && dp[1][i][j] < INF && dp[2][i][j] < INF)
			{
				ans = min(ans,dp[0][i][j] + dp[1][i][j] + dp[2][i][j] + (s[i][j]=='.'));
			}
		}
	printf("%d\n",ans>=INF?-1:ans);
	return 0;
}
