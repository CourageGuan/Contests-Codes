#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a));

const int maxn = 110;
int t[maxn],c[maxn][maxn],r[maxn],d[maxn][maxn*maxn];
int n,m;


int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> m;
	F(i,1,n) 
	{
		scanf("%d",r+i);
		F(j,1,r[i]) scanf("%d",t+j),t[j] += t[j-1];
		F(L,0,r[i])
			F(R,L,r[i])
			{
				int p = L + r[i] - R;
				c[i][p] = max(c[i][p],t[L] + t[r[i]] - t[R]);
			}
		//F(j,1,r[i]) printf("%d ",c[i][j]);
		//puts("");
	}
	F(i,1,n)
	{
		F(j,0,r[i])
		{
			F(k,0,m-j)
			{
				d[i][k+j] = max(d[i][k+j],d[i-1][k]+c[i][j]);
			}
		}
	}
	printf("%d\n",d[n][m]);
	return 0;
}
