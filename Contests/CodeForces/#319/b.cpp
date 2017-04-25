#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const int maxm = 2020;

int save[maxn];
bool vis[2][maxm];

int n,m;

bool yes()
{
	//memset(vis,0,sizeof vis);
	vis[0][0] = 1;
	int cur = 0;
	for(int i=1;i<=n;++i)
	{
        if(save[i] == 0) return true;
        cur^=1;
        memset(vis[cur],0,sizeof vis[cur]);
		for(int j=0;j<=m;++j)
		{
			if(vis[cur^1][j])
			{
				vis[cur][j] = 1;
				if(j+save[i] == m) return true;
			   	vis[cur][(j+save[i]) % m] = 1;
			}
		}
	}
	return vis[cur][m];
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{
	   	scanf("%d",save+i);
		save[i]%=m;
	}
	puts(yes()?"YES":"NO");
	return 0;
}
