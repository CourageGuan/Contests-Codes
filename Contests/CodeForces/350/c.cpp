#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
map<int,int> cnt;
int b[maxn],c[maxn];

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;++i) 
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	scanf("%d",&m);
	int res = 1,r = 0,t = 0;
	for(int i=0;i<m;++i) scanf("%d",b+i);
	for(int i=0;i<m;++i) scanf("%d",c+i);
	for(int i=0;i<m;++i)
	{
		int cb = cnt[b[i]],cc = cnt[c[i]];
		if( cb > r || (cb == r && cc >= t))
		{
			res = i+1;
			r = cb;
			t = cc;
		}
	}
	printf("%d\n",res);
	return 0;
}
