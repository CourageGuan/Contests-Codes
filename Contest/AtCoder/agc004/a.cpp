#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof a);

const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
	//freopen("test.txt","r",stdin);
	LL a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	LL ans = INF;
	ans = min(ans,b*c*((a+1)/2 - a/2));
	ans = min(ans,a*c*((b+1)/2 - b/2));
	ans = min(ans,a*b*((c+1)/2 - c/2));
	printf("%lld",ans);
	return 0;
}
