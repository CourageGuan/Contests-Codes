#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 55;
char G[maxn][maxn];
int vis[maxn][maxn],col[maxn*maxn],n,m,k,sum,flag;
vector<pair<int,int> > P;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool check(int x,int y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x,int y,int cnt)
{
	if(x == 0 || y == 0 || x == n-1 || y == m-1) flag = 0;
	vis[x][y] = cnt;
	++sum;
	F(i,0,3)
	{
		int tx = x + dx[i],ty = y + dy[i];
		if(check(tx,ty) && !vis[tx][ty] && G[tx][ty] == '.')
			dfs(tx,ty,cnt);
	}
}

void colo(int x,int y)
{
	vis[x][y] = -1;
	F(i,0,3)
	{
		int tx = x + dx[i],ty = y + dy[i];
		if(check(tx,ty) && vis[tx][ty]!=-1 && G[tx][ty] == '.') colo(tx,ty);
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&k);	
	F(i,0,n-1)
	{
	   	scanf("%s",G[i]);
	}
	memset(vis,0,sizeof vis);
	int cnt = 1;
	F(i,0,n-1)
		F(j,0,m-1)
		if(G[i][j]=='.' && !vis[i][j])
		{
			sum = 0;
			flag = 1;
			dfs(i,j,cnt);
			if(flag)
			{
				P.push_back(make_pair(sum,cnt));
				++cnt;
			}
			else colo(i,j);
		}

	sort(P.begin(),P.end(),greater<pair<int,int> >());
	int ans = 0;
	memset(col,0,sizeof col);
	while(P.size() > k)
	{
		col[P[P.size()-1].second] = 1;
		ans += P[P.size()-1].first;
		P.pop_back();
	}
	F(i,0,n-1)
		F(j,0,m-1) if(vis[i][j] > 0 && col[vis[i][j]]) G[i][j] = '*';
	printf("%d\n",ans);
	F(i,0,n-1)
	{
	   	puts(G[i]);
	}
	return 0;
}
