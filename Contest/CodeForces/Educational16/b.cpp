#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define se second

const int maxn = 3e5 + 10;
int n;
int a[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	R(i,n) scanf("%d",a+i);
	sort(a,a+n);
	printf("%d\n",a[(n-1)/2]);
	return 0;
}
