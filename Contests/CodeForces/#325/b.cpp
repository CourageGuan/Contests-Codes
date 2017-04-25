#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 110;
const int INF = 0x3f3f3f3f;

int a[maxn],b[maxn],c[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	a[0] = b[0] = 0;
	for(int i=1;i<n;++i) scanf("%d",a+i),a[i] += a[i-1];
	for(int i=1;i<n;++i) scanf("%d",b+i),b[i] += b[i-1];
	for(int i=0;i<n;++i) scanf("%d",c+i);
	int mn1,mn2;
	mn1 = mn2 = INF;
	for(int i=0;i<n;++i)
	{
		int cur = b[n-1] - b[i] + c[i] + a[i] - a[0];
		//printf("%d\n",cur);
		if(mn1 >= cur)
		{
			mn2 = mn1;
			mn1 = cur;
		}
		else if(mn2 > cur) mn2 = cur;
	}
	printf("%d\n",mn1+mn2);
	return 0;
}
