#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	//freopen("test.txt","r",stdin);
	int n,k;
	LL p[2];
	for(int t=0;t<2;++t)
	{
		p[t] = 0;
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;++i)
		{
			int x;
			scanf("%d",&x);
			p[t] = p[t]*k + x;
		}
	}
	if(p[0] != p[1]) puts(p[0]<p[1]?"<":">");
	else puts("=");
	return 0;
}
