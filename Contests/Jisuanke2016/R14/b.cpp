#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned uint;

uint ans;
int n,m,t;
int a[20];

void dfs(int k)
{
	if(k >= t)
	{
		++ans;
		return ;
	}
	for(int i=0;i<m;++i)
	{
		a[k] = i;
		if(k&1)
		{
			bool flag = 0;
			for(int j=0;j<=k/2;++j)
				if(a[j] != a[k/2+j+1])
				{
					flag = true;
					break;
				}
			if(flag) dfs(k+1);
		}
		else
			dfs(k+1);
	}
}

int main()
{
	freopen("test.txt","r",stdin);
	while(scanf("%d %d",&n,&m) == 2)
	{
		ans = 0;
		int pre = 0;
		for(t=1;t<=n;++t)
		{
			dfs(0);
			printf("%d %d\n",t,ans-pre);
			pre = ans;
		}
		printf("%u\n",ans);
	}
	return 0;
}
