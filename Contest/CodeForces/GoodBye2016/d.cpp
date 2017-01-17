#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

const int maxn = 310;
int n;
int vis[maxn][maxn][33][8],ok[maxn][maxn];
int t[33];

void dfs(int x,int y,int k,int d)
{
	if(k > n || vis[x][y][k][d]) return;
	vis[x][y][k][d] = 1;
	F(i,1,t[k])
	{
		x += dx[d];
		y += dy[d];
		ok[x][y] = 1;
	}
	dfs(x,y,k+1,(d+1)%8);
	dfs(x,y,k+1,(d+7)%8);
}

void solve()
{
	scanf("%d",&n);
	F(i,1,n) scanf("%d",t+i);
	dfs(155,155,1,0);
	int ans = 0;
	F(i,1,maxn-1) F(j,1,maxn-1) ans += ok[i][j];
	printf("%d\n",ans);
}

int main()
{
//	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
