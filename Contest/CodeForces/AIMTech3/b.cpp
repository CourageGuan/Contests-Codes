#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;  
const int INF = 0x3f3f3f3f;
int x[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,a;
	cin >> n >> a;
	R(i,n) scanf("%d",x+i);
	sort(x,x+n);
	if(n == 1)
	{
		puts("0");
		return 0;
	}
	if(n == 2)
	{
		printf("%d\n",min(abs(a-x[0]),abs(a-x[1])));
		return 0;
	}
	int ans = min(x[n-1] - x[1] + min(abs(a - x[1]),abs(x[n-1] - a)),x[n-2] - x[0] + min(abs(a - x[0]),abs(x[n-2] - a)));
	printf("%d\n",ans);
	return 0;
}
