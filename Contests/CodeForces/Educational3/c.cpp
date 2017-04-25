#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int m[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int sum = 0;
	for(int i=0;i<n;++i) scanf("%d",m+i),sum += m[i];
	sort(m,m+n,greater<int>());
	int ans = 0;
	int cur = sum/n,rem = sum%n;
	for(int i=0;i<n;++i)
	{
		if(i+1 <= rem)
			ans += abs(m[i]-cur-1);
		else 
			ans += abs(m[i]-cur);
	}
//	printf("%d\n",ans);
	printf("%d\n",ans/2);
	return 0;
}
