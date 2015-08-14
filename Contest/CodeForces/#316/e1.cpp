#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 510;
int d[2][maxn][maxn];
char pic[maxn][maxn];

inline void add(int &a,int b)
{
	a += b;
	if(a>=mod) a-=mod;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	while(scanf("%d %d",&n,&m)==2)
	{
		for(int i=0;i<n;++i) scanf("%s",pic[i]);
		if(pic[0][0]!=pic[n-1][m-1])
		{
			puts("0");
			continue;
		}
		memset(d,0,sizeof d);
		int cur = 0;
		d[cur][0][n-1] = 1;
		int N = (m+n-2);
		for(int t=1;t<=N/2;++t)
		{
			cur^=1;	
			memset(d[cur],0,sizeof d[cur]);
			for(int i=0;i<=t;++i)
			{
				for(int k=n-t-1;k<n;++k)
				{
				//	printf("(%d,%d) (%d,%d)\n",i,t-i,k,N-t-k);
					if(i>k || t-i > N-t-k) continue;
					if(pic[i][t-i]==pic[k][N-t-k])
					{
						add(d[cur][i][k],d[1-cur][i][k]);
						if(i-1>=0) add(d[cur][i][k],d[1-cur][i-1][k]);
						if(k+1<n) add(d[cur][i][k],d[1-cur][i][k+1]);
						if(i-1>=0 && k+1<n) add(d[cur][i][k],d[1-cur][i-1][k+1]);
					}
				}
			}
		}
		int ans = 0 , t=N/2;
		if(N&1)
		{
			for(int i=0;i<=t;++i)
			{
				add(ans,d[cur][i][i+1]);
				add(ans,d[cur][i][i]);
			}
		}
		else
		{
			for(int i=0;i<=t;++i)
			{
			   	if(i-1>=0) add(ans,d[cur][i-1][i]);
			   	add(ans,d[cur][i][i]);
			   	if(i+1<n) add(ans,d[cur][i][i+1]);
			   	if(i-1>=0 && i+1<n) add(ans,d[cur][i+1][i-1]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


