#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[6];

int main()
{
	//freopen("test.txt","r",stdin);
	int n = 5,ans = 0,cnt = 0,cur = 0,res = 0;
	for(int i=0;i<n;++i) scanf("%d",a+i),ans += a[i];
	a[n] = 0;
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=1;i<=n;++i)
	{
		if(a[i] == a[i-1] && cnt < 2)
		{
			cur += a[i-1];
			++cnt;
		}
		else
		{
			cur += a[i-1];
			if(cnt)
			{
				res = max(res,cur);
			}
			cnt = 0,cur = 0;
		}
	}
	printf("%d\n",ans - res);
	return 0;
}
