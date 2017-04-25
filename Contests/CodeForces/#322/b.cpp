#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;
int h[maxn],mx[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",h+i);
	int cur = 0;
	for(int i=n-1;i>=0;--i)
	{
		mx[i] = cur;
		cur = max(cur,h[i]);
	}
	for(int i=0;i<n-1;++i)
	{
		printf("%d ",max(0,mx[i] - h[i]+1));
	}
	printf("%d\n",0);
	return 0;
}
