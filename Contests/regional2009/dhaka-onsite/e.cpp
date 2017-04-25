#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

map<int,int> sg;
int g[6][6];

void clr(int x,int y,int col)
{
	g[x][y] = 0;
	if(x+1 < 4 && g[x+1][y] == col) clr(x+1,y,col);
	if(x-1 >= 0 && g[x-1][y] == col) clr(x-1,y,col);
	if(y+1 < 4 && g[x][y+1] == col) clr(x,y+1,col);
	if(y-1 >= 0 && g[x][y-1] == col) clr(x,y-1,col);
}

inline int get(int s,int x,int y)
{
	memset(g,0,sizeof g);
	for(int i=3;i>=0;--i)
		for(int j=3;j>=0;--j)
			g[i][j] = s%3,s/=3;
	if(g[x][y] == 0) return -1;
	clr(x,y,g[x][y]);
	F(j,0,3)
	{
		int t = 0,tm[4];
		F(i,0,3) if(g[i][j] != 0) tm[++t] = g[i][j],g[i][j] = 0;
		for(int i=3;i>=0 && t>=1 ;--i) g[i][j] = tm[t--];
	}
	int st = 0;
	F(i,0,3) F(j,0,3)
	{
		st = st*3 + g[i][j];
	}
	return st;
}

int dfs(int st)
{
	if(st == 0) return 0;
	if(sg.count(st)) return sg[st];

	int res = 1000;

	F(i,0,3) F(j,0,3)
	{
		int t = get(st,i,j);
		if(t == -1) continue;
		int nxt = dfs(t);
		if(res == 1000) res = nxt;
		else if(res > 0)
		{
			if(nxt < 0) res = nxt;
			else if(nxt > 0) res = max(res,nxt);
		}
		else 
		{
			if(nxt < 0) res = max(res,nxt);
		}
	}

	if(res > 0) res = -res - 1;
	else res = -res + 1;
	sg[st] = res;

	return res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	sg[0] = 0;
	F(z,1,T)
	{
		for(int i=0;i<4;++i)
		{
			char s[6];
			scanf("%s",s);
			for(int j=0;j<4;++j)
			   	g[i][j] = s[j]=='B'?1:2;
		}
		int st = 0;
		F(i,0,3) F(j,0,3)
		{
			st = st*3 + g[i][j];
		}

		int t = dfs(st);
		if(t > 0)
			printf("Case %d: win %d\n",z,t);
		else
			printf("Case %d: loss %d\n",z,-t);
	}
	return 0;
}
