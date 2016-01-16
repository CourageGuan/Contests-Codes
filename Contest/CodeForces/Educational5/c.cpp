#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int dx[] = {0,0,1,-1}; 
int dy[] = {1,-1,0,0}; 

char pic[maxn][maxn];
int val[maxn][maxn];
int vis[maxn][maxn];
int n,m,cnt,mark;

inline bool inside(int x,int y)
{
	return x>=0 && y>=0 && x<n && y<m;
}

void cal(int x,int y)
{
	vis[x][y] = mark;
	++cnt;
	for(int i=0;i<4;++i)
	{
		int tx = x + dx[i],ty = y + dy[i];
		if(inside(tx,ty) && pic[tx][ty] == '.' && !vis[tx][ty])
		{
			cal(tx,ty);
		}
	}
}

void dfs(int x,int y)
{
	val[x][y] = cnt;
	for(int i=0;i<4;++i)
	{
		int tx = x + dx[i],ty = y + dy[i];
		if(inside(tx,ty) && pic[tx][ty] == '.' && !val[tx][ty])
		{
			dfs(tx,ty);
		}
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i) scanf("%s",pic[i]);
	memset(vis,0,sizeof vis);
	memset(val,0,sizeof val);
	mark = 0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(pic[i][j] == '.' && !vis[i][j])
			{
				++mark;
				cnt = 0;
				cal(i,j);
				dfs(i,j);
			}
	/*
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			printf("%d",vis[i][j]);
		puts("");
	}
	puts("");
	*/
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(pic[i][j] == '*')
			{
				int ans = 0;
				vector<int> st;
				for(int t=0;t<4;++t)
				{
					int ti = i + dx[t],tj = j + dy[t]; 
					if(inside(ti,tj) && val[ti][tj])
					{
						bool flag = true;
						for(int k=0;k<st.size();++k)
							if(st[k] == vis[ti][tj]) { flag = false;}
						if(flag)
						{
							st.push_back(vis[ti][tj]);
							ans += val[ti][tj];
						}
					}
				}
				printf("%d",(ans+1)%10);
			}
			else putchar(pic[i][j]);
		}
		putchar('\n');
	}
	return 0;
}

