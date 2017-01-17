#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 5e5 + 10,maxd = 60;
DB d[maxn][maxd];
int fa[maxn];
int q,sz;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&q);
	F(i,0,maxd-1) d[1][i] = 1;
	fa[1] = -1;
	sz = 1;
	while(q--)
	{
		int op,u;
		scanf("%d %d",&op,&u);
		if(op == 1)
		{
			++sz;
			fa[sz] = u;
			F(i,0,maxd-1) d[sz][i] = 1;
			int k = 0;
			DB cur = d[u][0];
			d[u][0] *= 0.5;
			while(fa[u] != -1 && ++k < maxd)
			{
				DB tmp = d[fa[u]][k];
				d[fa[u]][k] /= (1+cur)/2;
				d[fa[u]][k] *= (1+d[u][k-1])/2;
				cur = tmp;
				u = fa[u];
			}
		}
		else
		{
			DB ans = 0;
			F(i,1,maxd-1) ans += i*(d[u][i] - d[u][i-1]);
			printf("%.8lf\n",ans);
		}
	}
	return 0;
}
