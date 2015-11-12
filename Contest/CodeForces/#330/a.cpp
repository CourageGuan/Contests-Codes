#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	int cnt = 0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			if(x!=0 || y!=0) ++cnt;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
