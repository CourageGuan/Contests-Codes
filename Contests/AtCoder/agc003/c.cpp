#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
int a[maxn],b[maxn];
int n;

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);	
	R(i,n)
	{
		scanf("%d",a+i);
		b[i] = a[i];
	}
	sort(b,b+n);
	int cnt = 0;
	R(i,n)
	{
		int p = lower_bound(b,b+n,a[i]) - b;
		if((p - i)%2 != 0) ++cnt;
	}
	assert(!(cnt&1));
	printf("%d\n",cnt/2);
	return 0;
}
