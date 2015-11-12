#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 1e5 + 10;
LL a[maxn],b[maxn],p[20];


int main()
{
	//freopen("test.txt","r",stdin);
	int n,k;
	scanf("%d %d",&n,&k);
	int t = n/k;
	for(int i=0;i<t;++i) scanf("%lld",a+i);
	for(int i=0;i<t;++i) scanf("%lld",b+i);
	p[0] = 1;
	for(int i=1;i<10;++i) p[i] = p[i-1]*10;
	LL res = 1;
	for(int i=0;i<t;++i) 
	{
		LL cur = (p[k]-1)/a[i]+1;
		LL L = (b[i]*p[k-1]/a[i]) * a[i],R = ((b[i]+1)*p[k-1]/a[i]) * a[i];
		if(L < b[i]*p[k-1]) L += a[i];
		if(R >= (b[i]+1)*p[k-1]) R -= a[i];
		if(R-L>=0) cur -= (R-L)/a[i] + 1;
		res = res*cur%mod;
		if(res == 0) break;
	}
	printf("%I64d\n",res);
	return 0;
}
