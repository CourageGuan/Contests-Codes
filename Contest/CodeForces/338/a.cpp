#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int cnt[110];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<n;++i)
	{
		int x,y;
		scanf("%d",&x);
		for(int i=0;i<x;++i)
		{
			scanf("%d",&y);
			cnt[y] = 1;
		}
	}
	for(int i=1;i<=m;++i) if(!cnt[i]){ puts("NO"); return 0; }
	puts("YES");
	return 0;
}
