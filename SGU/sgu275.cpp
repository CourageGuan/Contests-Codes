#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;

const int maxn = 110;
LL a[maxn];

int xorGauss(int n,int m)
{
	int r = 0,c = 60;
	for(;r < n && c >= 0; ++r,--c)
	{
		int p = r;
		for(;p < n;++p) if((a[p] >> c) & 1) break;
		if(p == n) { --r; continue; }
		swap(a[p],a[r]);

		for(int i=0;i<n;++i) 
			if(i != r && (a[i] >> c) & 1)
				a[i] ^= a[r];
	}
	return r;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%lld",a+i);
	int r = xorGauss(n,61);
	LL ans = 0;
	for(int i=0;i<r;++i) ans ^= a[i];
	printf("%lld\n",ans);
	return 0;
}
