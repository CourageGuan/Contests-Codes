#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn],p[maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d %d",a+i,p+i);
	int cur = p[0],ans = cur*a[0];
	for(int i=1;i<n;++i)
	{
		if(cur > p[i]) cur = p[i];
		ans += cur*a[i];
	}
	printf("%d\n",ans);
	return 0;
}

