#include<stdio.h>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
int d[1<<16][17];
int a[20],p[20],n;

void update(int &x,int y)
{
	x = max(x,y);
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d %d",a+i,p+i);
		memset(d,-INF,sizeof d);
		a[n] = 0;
		d[0][n] = 0;
		for(int i=0;i<(1<<n);++i)
		{
			int cnt = __builtin_popcount(i); 
			for(int j=0;j<=n;++j)
			{
				if(d[i][j] != -INF)
				{
					for(int k=0;k<n;++k)
						if(!((i>>k)&1) && (p[k] == -1 || p[k] == cnt))
							update(d[i|(1<<k)][k],d[i][j]+a[j]*a[k]);
				}
			}
		}
		int ans = -INF;
		for(int i=0;i<=n;++i) update(ans,d[(1<<n)-1][i]);
		printf("Case #%d:\n%d\n",z,ans);
	}
	return 0;
}
