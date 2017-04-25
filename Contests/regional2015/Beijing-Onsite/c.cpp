#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

queue<int> Q;
const int INF = 0x3f3f3f3f;
const int maxd = 777777, maxn = 120;
int dp[maxd],cnt[7],G[7][7],to[7];
char s[maxn],t[maxn];

void bfs()
{
	fill(dp,INF);
	Q.push(123456);
	dp[123456] = 0;
	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();
		int t = u,v,d[6],p[6];
		for(int i=0;i<6;++i) d[i] = t%10,t/=10;
		for(int i=0;i<6;++i)
			for(int j=0;j<6;++j)
			{
				if(i == j) continue;
				memcpy(p,d,sizeof(p));
				v = 0;
				for(int k=0;k<6;++k) if(p[k] == i+1) p[k] = j+1;
				for(int k=5;k>=0;--k) v = v*10 + p[k];
				if(dp[v] > dp[u] + 1)
				{
					dp[v] = dp[u] + 1;
					Q.push(v);
				}
			}
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	bfs();
	while(scanf("%s %s",t,s) == 2)
	{
		int len = strlen(s),ans = INF;
		fill(cnt,0);
		fill(G,0);
		R(i,len)
		{
			int d1 = s[i] - '0',d2 = t[i] - '0';
			cnt[d1]++; G[d1][d2]++;
		}
		R(a,6) R(b,6) R(c,6) R(d,6) R(e,6) R(f,6)
		{
			int u = (a+1) + (b+1)*10 + (c+1)*100 + (d+1)*1000
				+ (e+1)*10000 + (f+1)*100000;
			to[1] = f + 1;
			to[2] = e + 1;
			to[3] = d + 1;
			to[4] = c + 1;
			to[5] = b + 1;
			to[6] = a + 1;
			int res = dp[u];
			R(i,6)
			{
				res += cnt[i+1] - G[i+1][to[i+1]];
			}
			ans = min(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}
