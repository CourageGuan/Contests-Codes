#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1010;
int n,a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	sort(a,a+n);
	int i = 0,cur = 0,ans = 0;
	bool fi = 0;
	while(i < n)
	{
		int cnt = 1;
		while(i < n-1 && a[i+1] == a[i]) ++i,++cnt;
		if(fi) ans += min(cur,cnt);
		else fi = 1;
		++i;
		cur = max(cur,cnt);
	}
	printf("%d\n",ans);
	return 0;
}
