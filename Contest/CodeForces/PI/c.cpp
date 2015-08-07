#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long LL;

const int maxn = 200010;
map<LL,LL> d[2];

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	LL k1;
	scanf("%d %lld",&n,&k1);
	LL k2 = k1*k1;
	LL ans = 0;
	d[0].clear();
	d[1].clear();
	for(int i=0;i<n;++i)
	{
		LL x;
		scanf("%lld",&x);
		if(x%k2==0) ans += d[1][x/k2];
		if(x%k1==0) d[1][x/k1] += d[0][x/k1];
		++d[0][x];
	}
	printf("%lld\n",ans);
	return 0;
}
