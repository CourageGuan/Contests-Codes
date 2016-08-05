#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 210;

int d[maxn][maxn];

int dfs(int w,int h)
{
	if(~d[w][h]) return d[w][h];
	int vis[maxn];
	fill(vis,0);
	F(i,2,w/2) vis[dfs(i,h)^dfs(w-i,h)] = 1;
	F(i,2,h/2) vis[dfs(w,i)^dfs(w,h-i)] = 1;
	for(int i=0;;++i) if(!vis[i]) return d[w][h] = i;
}

int w,h;

int main()
{
//	freopen("test.txt","r",stdin);
	fill(d,-1);
	while(scanf("%d %d",&w,&h) == 2)
	{
		puts(dfs(w,h)?"WIN":"LOSE");
	}
	return 0;
}
