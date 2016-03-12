#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 11;
int r,c,n,k;
int vis[maxn][maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d %d",&r,&c,&n,&k);
	memset(vis,0,sizeof vis);
	for(int i=0;i<n;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		vis[x][y] = 1;
	}
	int res = 0;
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
		{
			for(int t=0;t<=r-i;++t)
				for(int l=0;l<=c-j;++l)
				{
					int cnt = 0;
					for(int a=i;a<=i+t;++a)
						for(int b=j;b<=j+l;++b)
						if(vis[a][b]) ++cnt;
					if(cnt >= k) ++res;
				}
		}
	}
	printf("%d\n",res);
	return 0;
}
