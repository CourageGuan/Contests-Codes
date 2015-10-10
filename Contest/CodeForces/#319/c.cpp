#include<bits/stdc++.h>

using namespace std;
const int maxn = 1010;
bool vis[maxn];
vector<int> prim;
int e[maxn];

void init()
{
	memset(vis,0,sizeof vis);
	for(int i=2;i<maxn;++i)
	{
		if(!vis[i])
		{
			prim.push_back(i);
			for(int j=i+i;j<maxn;j+=i) vis[j] = 1;
		}
	}
}


void solve(int n)
{
	memset(e,0,sizeof e);
	for(int i=1;i<=n;++i)
	{
		int t = i;
		for(int j=0;j<prim.size();++j)
		{
			if(t%prim[j] == 0)
			{
				int cnt = 0;
				while(t%prim[j]==0)
				{
				   	t/=prim[j];
					++cnt;
				}
				e[j] = max(e[j],cnt);
			}
		}
	}
	int cnt = 0;
	for(int i=0;i<prim.size();++i)
	{
		cnt+=e[i];
	}
	printf("%d\n",cnt);
	for(int i=0;i<prim.size();++i)
	{
		int res = 1;
		for(int j=1;j<=e[i];++j)
		{
			res *= prim[i];
			printf("%d%c",res,--cnt?' ':'\n');
		}
	}
}

int main()
{
	int n;
	init();
	while(scanf("%d",&n)==1)
	{
		solve(n);
	}
	return 0;
}




