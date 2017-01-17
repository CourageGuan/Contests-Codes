#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 5e5 + 10;
int n;
LL a[maxn],b[maxn],s;

void xorGauss(int n)
{
	int r = 0,c = 60,m = 60;
	for(;r < n && c >= 0; ++r,--c)
	{
		int p = r;
		for(;p < n;++p) if((a[p]>>c) & 1) break;
		if(p == n) { --r; continue; }
		if(p != r) swap(a[p],a[r]);

		for(int i=0;i <= n;++i)
			if(i != r && ((a[i]>>c) &1))
				a[i] ^= a[r];
	}

	if(a[n])
		puts("1/1");
	else
		printf("%lld/%lld\n",(1LL << r)-1,1LL << r);
}


int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	F(i,0,n-1) scanf("%lld %lld",a+i,b+i),s ^= a[i],a[i] ^= b[i];
	a[n] = s;
	xorGauss(n);
	return 0;
}
