#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2010;
double d[maxn][maxn];
bool vis[maxn][maxn];
int vx[maxn],vy[maxn],cx,cy;
int n,m;

double dp(int x,int y)
{
	double &ans = d[x][y];
	if(vis[x][y]) return ans;
	vis[x][y] = 1;
	//printf("%d %d\n",x,y);
	ans = n*n;
	if(x+1 <= n) ans += (n-x)*y*dp(x+1,y);
	if(y+1 <= n) ans += x*(n-y)*dp(x,y+1);
	if(x+1 <= n && y+1 <= n) ans += (n-x)*(n-y)*dp(x+1,y+1);
	ans /= (n*n - x*y);
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);	
	F(i,1,m)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(!vx[x]) ++cx,vx[x] = 1;
		if(!vy[y]) ++cy,vy[y] = 1;
	}
	memset(vis,0,sizeof vis);
	vis[n][n] = 1;
	d[n][n] = 0;
	double res = dp(cx,cy);
	printf("%.10lf\n",res);
	return 0;
}
