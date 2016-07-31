#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a));

const int maxn = 1e5 + 10;
bool vis[maxn];


int main()
{
//	freopen("test.txt","r",stdin);
	int a[4],d;
	R(i,4) scanf("%d",a+i);
	scanf("%d",&d);
	R(i,4)
	{
		for(int j = a[i];j<=d;j += a[i])
		{
			vis[j] = 1;
		}
	}
	int ans = 0;
	F(i,1,d) if(vis[i]) ++ans;
	printf("%d\n",ans);
	return 0;
}
