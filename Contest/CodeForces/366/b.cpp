#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
const int INF = 0x3f3f3f3f;

const int maxn = 1e5 + 10;
int a[maxn],ans[maxn];

int main()
{
//	freopen("test.txt","r",stdin);
	int n;
	LL cur = 0; 
	cin >> n;
	R(i,n) scanf("%d",a+i);
	ans[0] = 1 + (a[0]&1);
	F(i,1,n-1)
		if(a[i] == 1) ans[i] = ans[i-1];
		else
		{
			if(ans[i-1] == 1)
			{
				if(a[i]&1) ans[i] = 1;
				else ans[i] = 2;
			}
			else
			{
				if(a[i]&1) ans[i] = 2;
				else ans[i] = 1;
			}
		}
	R(i,n) printf("%d\n",ans[i]);
	return 0;
}
