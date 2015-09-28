#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 1010;

int main()
{
	//freopen("test.txt","r",stdin);
	int x;
	while(scanf("%d",&x)==1)	
	{
		if(x==1) puts("1");
		else
		{
			int ans = 0;
			while(x)
			{
				if(x&1) ++ans;
				x/=2;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
