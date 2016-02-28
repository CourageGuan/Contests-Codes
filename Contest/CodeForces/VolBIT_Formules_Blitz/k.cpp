#include<cstdio>

typedef long long LL;

int main()
{
	LL res = 0,n;
	scanf("%lld",&n);
	for(int i=0;i<2;++i)
	for(int j=0;j<2;++j)
	for(int k=0;k<2;++k)
	for(int l=0;l<2;++l)
	{
		int cnt = i+j+k+l;
		int cur = 1;
		if(i) cur*=2;
		if(j) cur*=3;
		if(k) cur*=5;
		if(l) cur*=7;
		if(cnt&1) res -= n/cur;
		else res += n/cur;
	}
	printf("%lld\n",res);
	return 0;
}
