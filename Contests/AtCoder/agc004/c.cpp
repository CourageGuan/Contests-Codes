#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof a);

const int maxn = 510;
char s[maxn][maxn],a[maxn][maxn],b[maxn][maxn];
int n,m;

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	R(i,n)
	{
	   	scanf("%s",s[i]);
		R(j,m) a[i][j] = b[i][j] = '.';
		if(i&1)
		{
		   	R(j,m-1) a[i][j] = '#';
			R(j,m-1) if(s[i][j] == '#') b[i][j] = '#';
			b[i][m-1] = '#';
		}
		else
		{
		   	F(j,1,m-1) b[i][j] = '#';
			R(j,m-1) if(s[i][j] == '#') a[i][j] = '#';
			a[i][0] = '#';
		}
	}
	R(i,n) puts(a[i]);
	puts("");
	R(i,n) puts(b[i]);
	return 0;
}
