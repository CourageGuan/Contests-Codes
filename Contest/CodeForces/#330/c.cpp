#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int a[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	sort(a,a+n);
	int ans = INF;
	for(int i=0;i<n;++i)
	{
		if(i+(n/2) < n) ans = min(ans,a[i+(n/2)]-a[i]);
		else break;
	}
	printf("%d\n",ans);
	return 0;
}
