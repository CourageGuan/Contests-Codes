#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define R(i,n) for(int i=0;i<(n);++i)
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 3010;
int n;
int a[maxn],b[maxn];
LL d[2][maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	R(i,n) scanf("%d",a+i),b[i] = (a[i] -= i+1);
	sort(b,b+n);
	R(i,n)
	{
		LL cur = INF;
		R(j,n) 
		{
			cur = min(cur,d[0][j]);
			d[1][j] = cur + abs(a[i] - b[j]);
		}
		memcpy(d[0],d[1],sizeof(d[1]));
	}
	LL ans = INF;
	R(i,n) ans = min(ans,d[0][i]);
	printf("%lld\n",ans);
	return 0;
}
