#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
const int maxl = 20;

int n;
int a[maxn],b[maxn];

int dmin[maxn][maxl],dmax[maxn][maxl],LOG[maxn];

void init()
{
	LOG[0] = -1;
	for(int i=1;i<=n+1;++i)
	{
		LOG[i] = LOG[i/2] + 1;
		dmax[i-1][0] = a[i-1];
		dmin[i-1][0] = b[i-1];
	}

	for(int j=1;(1<<j)<=n+1;++j)
		for(int i=0;i+(1<<(j-1))-1 < n+1;++i)
		{
			dmax[i][j] = max(dmax[i][j-1],dmax[i+(1<<(j-1))][j-1]);
			dmin[i][j] = min(dmin[i][j-1],dmin[i+(1<<(j-1))][j-1]);
		}
}

int query(int L,int R,int op)
{
	int t = LOG[R-L+1];
	return op?min(dmin[L][t],dmin[R-(1<<t)+1][t]):max(dmax[L][t],dmax[R-(1<<t)+1][t]);
}

int main()
{
	//freopen("test.txt","r",stdin);

	cin >> n;
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=0;i<n;++i) scanf("%d",b+i);

	a[n] = 2e9;
	b[n] = -2e9;

	init();

	LL ans = 0;

	for(int i=0;i<n;++i)
	{
		if(a[i] > b[i]) continue;
		int L = i,R = i;

		int l = i,r = n;
		while(l <= r)
		{
			int m = (l+r)/2;
			if(query(i,m,0) >= query(i,m,1)) r = m-1,L = m;
			else l = m+1;
		}
		if(query(i,L,0) > query(i,L,1)) continue;
		l = i,r = n;
		while(l <= r)
		{
			int m = (l+r)/2;
			if(query(i,m,0) > query(i,m,1)) r = m-1,R = m;
			else l = m+1;
		}
		ans += R-L;
	}

	printf("%lld\n",ans);
	return 0;
}
