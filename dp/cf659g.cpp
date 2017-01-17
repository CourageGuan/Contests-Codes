#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
int h[maxn],n,hi;
LL d[maxn];

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	F(i,1,n) scanf("%d",h+i),--h[i];
	if(n == 1)
	{
	   	printf("%d\n",h[1]);
		return 0;
	}
	LL ans = h[1];
	hi = d[1] = min(h[1],h[2]);

//	printf("%d %d\n",1,d[1]);

	F(i,2,n)
	{
		hi = min(h[i+1],min(h[i],h[i-1]));
		d[i] = (d[i-1]*hi%mod + min(h[i],h[i+1])) %mod;
		ans = (ans + d[i-1]*min(h[i],h[i-1])%mod + h[i])%mod;
//		printf("%d %d %lld\n",i,d[i],ans);
	}

	printf("%lld\n",ans);
	return 0;
}
