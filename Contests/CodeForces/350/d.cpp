#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;
const int INF = 0x7fffffff;

LL a[maxn],b[maxn];
int n;
LL k;

bool yes(LL m)
{
	LL cur = k;
	for(int i=0;i<n;++i)
	{
		if(a[i]*m - b[i] > 0) cur -= a[i]*m - b[i];
		if(cur < 0) return false;
	}
	return true;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;++i) scanf("%lld",a+i);
	for(int i=0;i<n;++i) scanf("%lld",b+i);
	LL l=0,r=INF,res = 0;
	while(l <= r)
	{
		LL m = (l+r) >> 1;
		if(yes(m)) 
		{
			res = m;
			l = m+1;
		}
		else r = m-1;
	}
	printf("%lld\n",res);
	return 0;
}
