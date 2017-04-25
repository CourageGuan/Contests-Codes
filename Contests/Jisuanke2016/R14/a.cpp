#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e4 + 10;
int a[maxn];
int n;

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&n) == 1)
	{
		for(int i=0;i<n;++i) scanf("%d",a+i);
		if(n  <= 2)
		{
			if(n == 1) printf("%d\n",a[0]);
			else printf("%d\n",max(a[0],a[1]));
			continue;
		}
		int ans = 0,sum = 0;
		for(int i=0;i<n;i+=2) sum += a[i]; 
		ans = max(ans,sum);
		if(!(n&1)) ans = max(ans,sum-a[n-2]+a[n-1]);
		sum = 0;
		for(int i=1;i<n;i+=2) sum += a[i]; 
		ans = max(ans,sum);
		if(n&1) ans = max(ans,sum-a[n-2]+a[n-1]);
		printf("%d\n",ans);
	}
	return 0;
}
