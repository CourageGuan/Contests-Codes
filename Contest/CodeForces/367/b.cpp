#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
int a[maxn];
int n,q;

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n;
	R(i,n) scanf("%d",a+i);
	sort(a,a+n);
	cin >> q;
	while(q--)
	{
		int m;
		scanf("%d",&m);
		int ans = upper_bound(a,a+n,m) - a;
		printf("%d\n",ans);
	}
	return 0;
}
