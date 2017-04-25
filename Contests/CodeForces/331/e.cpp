#include<bits/stdc++.h>
using namespace std;

const int maxn = 210;
int n,m,q;
int d[maxn*maxn][10],a[maxn],b[maxn];
char s[maxn][maxn],qs[(int)1e6 + 10];
bool vis[maxn][maxn];

vector<int> t;

inline int id(int x,int y)
{
	return x*m + y;
}

void dfs(int x,int y)
{
	vis[x][y] = 1;
	int c = s[x][y] - '0';
	int tx = x + a[c],ty = y + b[c];
	int p = id(x,y);
	if(tx < 0 || ty < 0 || tx >= n || ty >= m)
		d[p][c] = p;
	else
	{
		c = s[tx][ty] - '0'; 
		d[p][c] = id(tx,ty); 
		if(!vis[tx][ty]) dfs(tx,ty);
		for(int i=0;i<10;++i)
			if(i != c)
				d[p][i] = d[id(tx,ty)][i];
	}
}

bool check(char qs[])
{
	int len = strlen(qs);
	for(int i: t)
	{
		int j = 0,c = i;
//		printf("%d %d\n",i/m,i%m);
		if(s[i/m][i%m] == qs[j]) ++j;
		while(j < len && d[c][qs[j]-'0'] != -1) c = d[c][qs[j++]-'0'];
		if(j >= len) return true;
	}
	return false;
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;++i)
		scanf("%s",s[i]);
	for(int i=0;i<10;++i) scanf("%d %d",a+i,b+i);
	memset(vis,0,sizeof vis);
	memset(d,-1,sizeof d);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(!vis[i][j])
			{
				dfs(i,j);
				t.push_back(id(i,j));
			}
	for(int i=0;i<q;++i)
	{
		scanf("%s",qs);
		puts(check(qs)?"YES":"NO");
	}
	return 0;
}
