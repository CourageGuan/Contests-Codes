#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=a;i<=b;++i)
#define R(i,n) for(int i=0;i<n;++i)

int k;
int a[13];

int main()
{
//	freopen("test.txt","r",stdin);
	cin >> k;
	R(i,12) cin >> a[i];
	sort(a,a+12,greater<int>());
	int cur = 0;
	R(i,13)
	{
		if(cur >= k)
		{
			printf("%d\n",i);
			return 0;
		}
		cur += a[i];
	}
	puts("-1");
	return 0;
}
