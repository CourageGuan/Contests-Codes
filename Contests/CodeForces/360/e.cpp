#include<bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n,k;

int d[2][maxn][maxn],c[maxn];
int res[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> k;
	int p = 0;
	d[0][0][0] = 1;
	for(int i=0;i<n;++i)
	{
		cin >> c[i];
		p ^= 1;
		memset(d[p],0,sizeof d[0]);
		for(int j=k;j>=0;--j)
		{
			for(int t=k;t>=0;--t)
			{
				d[p][j][t] = d[p^1][j][t];
				if(j - c[i] >= 0)
				{
					d[p][j][t] = d[p][j][t] || d[p^1][j-c[i]][t];
					if(t-c[i]>=0)
						d[p][j][t] = d[p][j][t] || d[p^1][j-c[i]][t-c[i]];
				}
			}
		}
	}
	int cnt = 0;
	for(int i=0;i<=k;++i) if(d[p][k][i]) ++cnt;
	printf("%d\n",cnt);
	for(int i=0;i<=k;++i) if(d[p][k][i]) printf("%d ",i);
	return 0;
}
