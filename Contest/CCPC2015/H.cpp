#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

char s[5][5];
bool vis[5][5][5];
int ans[5][5];

vector<pair<int,int> > v;

bool yes()
{
	bool vis[5];
	for(int i=0;i<4;++i)
	{
		memset(vis,0,sizeof vis);
		for(int j=0;j<4;++j)
		{
			if(vis[ans[i][j]]) return false;
			vis[ans[i][j]] = 1;
		}
	}
	for(int i=0;i<4;++i)
	{
		memset(vis,0,sizeof vis);
		for(int j=0;j<4;++j)
		{
			if(vis[ans[j][i]]) return false;
			vis[ans[j][i]] = 1;
		}
	}
	for(int i=0;i<=2;i+=2)
		for(int j=0;j<=2;j+=2)
		{
			memset(vis,0,sizeof vis);
			for(int r=i;r<i+2;++r)
				for(int c=j;c<j+2;++c)
				{
					if(vis[ans[r][c]]) return false;
					vis[ans[r][c]] = 1;
				}
		}
	return true;
}

bool dfs(int n) 
{
	if(n >= v.size())
	{
		return yes();
	}
	for(int j=1;j<=4;++j)
	{
		if(!vis[v[n].first][v[n].second][j])
		{
			ans[v[n].first][v[n].second] = j;
			if(dfs(n+1)) return true;
		}
	}
	return false;
}

void solve()
{
	v.clear();
	int n = 4;
	
	memset(vis,0,sizeof vis);

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(s[i][j] == '*')
			{
				for(int r=0;r<n;++r)
				{
					if(s[r][j] != '*') vis[i][j][s[r][j] - '0'] = 1;
					if(s[i][r] != '*') vis[i][j][s[i][r] - '0'] = 1;
				}

				for(int r=i/2+i/2;r<=i/2+i/2+1;++r)
					for(int c=j/2+j/2;c<=j/2+j/2+1;++c)
					{
						if(s[r][c] != '*') vis[i][j][s[r][c] - '0'] = 1;
					}

				v.push_back(make_pair(i,j));
			}
			else ans[i][j] = s[i][j] - '0';
		}
	}

	dfs(0);
	//puts("yes");	
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		for(int i=0;i<4;++i) scanf("%s",s[i]);
		printf("Case #%d:\n",z);
		solve();
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<4;++j)
			{
				printf("%d",ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}


