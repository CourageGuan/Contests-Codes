#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	int mx = 0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)
	{
		int mn = INF;
		for(int j=0;j<m;++j)
		{
			int c; scanf("%d",&c);
			mn = min(mn,c);
		}
		mx = max(mx,mn);
	}
	printf("%d\n",mx);
	return 0;
}
