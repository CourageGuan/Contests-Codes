#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[30];
int n;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	sort(a,a+n,greater<int>());
	LL ans = a[0],cur = a[0];
	for(int i=1;i<n;++i)
	{
		if(!cur) break;
		if(a[i] >= cur)
			--cur;
		else
			cur = a[i];
		ans += cur;
	}
	printf("%lld\n",ans);
	return 0;
}
