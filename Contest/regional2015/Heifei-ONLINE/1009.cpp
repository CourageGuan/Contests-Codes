#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

typedef int LL;

const int dr[] = {-1,0};
const int dc[] = {0,-1};

const int maxn = 31;
const LL INF = 0x3f3f3f3f;

int R,C;
int num[maxn][maxn];

int dp[maxn][maxn][(maxn+maxn)*maxn];

int main()
{
  	//freopen("./test.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    for(int z = 1;z <= kase;++z)
    {
        scanf("%d %d",&R,&C);
        for(int i = 1;i <= R;++i)
            for(int j = 1;j <= C;++j)
                scanf("%d",&num[i][j]);


		memset(dp,INF,sizeof dp);
        dp[1][1][num[1][1]] = num[1][1]*num[1][1];
		int mx = num[1][1]; 

        int n = R+C-1;

        for(int S = 3;S <= R+C;++S)
        {
            for(int r = 1;r <= R;++r)
            {
                int c = S-r;
                if(!( c >= 1 && c <= C)) continue;

                for(int k = 0;k < 2;++k)
                {
                    int tr = r + dr[k];
                    int tc = c + dc[k];
                    if(tr >= 1 && tr <= R && tc >= 1 && tc <= C)
                    {
						for(int t=0;t<=mx;++t)
						{
							if(dp[tr][tc][t] != INF)
							{
								dp[r][c][t+num[r][c]] = min(dp[r][c][t+num[r][c]],dp[tr][tc][t] + num[r][c]*num[r][c]);
								mx = max(mx,t+num[r][c]);
							}
						}
					}
                }
            }
        }
		LL res = INF;
		for(int i=0;i<=mx;++i)
		{
			if(dp[R][C][i]!=INF)
			{
				res = min(res,n*dp[R][C][i] - i*i);
			}
		}

        printf("Case #%d: %d\n",z,res);
    }
    return 0;
}



