#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const int maxn = 1010;
int vis[maxn][maxn];
char s[maxn][maxn];
int n,m,k,cnt;

int dfs1(int l,int r)
{
	vis[l][r] = 0;
	for(int i=0;i<4;++i)
	{
		int tl = l+dx[i],tr = r + dy[i];
		if(tl>=0 && tr >=0 && tl<n && tr<m && s[tl][tr]=='*') ++cnt;
		if(tl>=0 && tr >=0 && tl<n && tr<m && s[tl][tr]=='.' && vis[tl][tr]==-1) dfs1(tl,tr);
	}
}

void dfs2(int l,int r)
{
	vis[l][r] = cnt;
	for(int i=0;i<4;++i)
	{
		int tl = l+dx[i],tr = r+ dy[i];
		if(tl>=0 && tr >=0 && tl<n && tr<m && s[tl][tr]=='.' && vis[tl][tr] == 0) dfs2(tl,tr);
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;++i) scanf("%s",s[i]);
	memset(vis,-1,sizeof vis);
	while(k--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		--l; --r;
		if(vis[l][r] != -1)
			printf("%d\n",vis[l][r]);
		else
		{
			cnt = 0;
			dfs1(l,r);
			dfs2(l,r);
			printf("%d\n",cnt);
		}
	}
	return 0;
}
