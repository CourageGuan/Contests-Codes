#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e7 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int n,x,y;
LL d[maxn*2];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&x,&y);
	fill(d,INF);
	d[1] = x;
	F(i,1,n)
	{
		d[i] = min(d[i],d[i+1]+x);
		d[i+1] = min(d[i+1],d[i] + x);
		if(i*2 <= 2*n) d[i*2] = min(d[i*2],d[i]+y);
	}
	printf("%lld\n",d[n]);
	return 0;
}
