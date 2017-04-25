#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int f[maxn]; 

int main()
{
	//freopen("test.txt"."r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		f[x] = i+1;
	}
	long long ans = 0;
	for(int i=1;i<n;++i)
	{
		ans += abs(f[i+1] - f[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
