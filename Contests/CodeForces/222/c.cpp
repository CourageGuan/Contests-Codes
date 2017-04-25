#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

int dx[] =  {0,0,1,-1};
int dy[] =  {1,-1,0,0};

const int maxn = 510;
int n,m,k,vis[maxn][maxn],cnt,sum;
char s[maxn][maxn];

bool check(int x,int y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x,int y)
{
	if(cnt == sum-k) return;
	vis[x][y] = ++cnt;
	R(i,4)
	{
		int tx = x + dx[i],ty = y + dy[i];
		if(vis[tx][ty]) continue;
		if(check(tx,ty) && s[tx][ty] == '.') dfs(tx,ty);
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&k);
	sum = 0;
	R(i,n)
	{
		scanf("%s",s[i]);
		R(j,m) sum += s[i][j] == '.';
	}
	memset(vis,0,sizeof vis);
	cnt = 0;
	R(i,n)
		R(j,m) if(s[i][j] == '.')
		{
			dfs(i,j);
			break;
		}
	R(i,n)
		R(j,m) if(s[i][j] == '.' && !vis[i][j]) s[i][j] = 'X';

	R(i,n) puts(s[i]);
	return 0;
}
