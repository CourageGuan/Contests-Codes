#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 110;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int n,m,k;

LL d[2][maxn][maxn];
int c[maxn],w[maxn];

void update(LL &a,LL b)
{
	if(a > b) a = b;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&k);
	F(i,1,n) scanf("%d",c+i);
	int p = 0;
	fill(d[p],INF);
	F(i,0,m) d[p][i][0] = 0;
	F(i,1,n)
	{
		p ^= 1;
		fill(d[p],INF);
		F(j,1,m) scanf("%d",w+j);
		if(c[i] == 0)
		{
			F(j,1,m)
			{
				F(z,0,m)
				{
					F(l,1,min(n,k))
					{
						if(j == z)
							update(d[p][j][l],d[p^1][z][l] + w[j]);
						else
							update(d[p][j][l],d[p^1][z][l-1] + w[j]);
					}
				}
			}
		}
		else
		{
			F(z,0,m)
			{
				F(l,1,min(n,k))
				{
					if(c[i] == z)
						update(d[p][c[i]][l],d[p^1][z][l]);
					else
						update(d[p][c[i]][l],d[p^1][z][l-1]);
				}
			}
		}
	}
	LL ans = INF;
	F(i,1,m) update(ans,d[p][i][k]);
	if(ans >= INF) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}
