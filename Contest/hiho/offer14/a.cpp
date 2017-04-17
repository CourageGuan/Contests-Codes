#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1010;
const int maxs = 2e6 + 10;
int n,a[maxn];	
LL mp[maxs];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	if(n < 4)
	{
		puts("0");
		return 0;
	}
	LL ans = 0;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			mp[a[i] + a[j]]++;
	for(int i=0;i<maxs;++i)
		if(mp[i])
			ans += mp[i]*(mp[i]-1);
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(a[i] == a[j])
			{
				ans -= 2*(n-2);
			}
	printf("%lld\n",ans);
	return 0;
}
