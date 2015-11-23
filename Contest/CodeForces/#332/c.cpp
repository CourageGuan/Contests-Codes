#include<bits/stdc++.h>
using namespace std;
typedef long long  LL;

const int maxn = 1e5 + 10;
int n,h[maxn],t[maxn];
map<int,int> mp;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",h+i),t[i] = h[i];
	sort(t,t+n);
	mp.clear();
	int cur = 0,ans = 0;
	for(int i=0;i<n;++i)
	{
		int p = int(lower_bound(t,t+n,h[i])-t) + mp[h[i]];
		++mp[h[i]];
		if(p > cur)
		{
			cur = p;
		}
		if(cur == i) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}
