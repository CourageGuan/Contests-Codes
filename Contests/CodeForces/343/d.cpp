#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
const double pi = acos(-1.0);
int n,r[maxn],h[maxn];
LL v[maxn],d[maxn];

inline int lowbit(int x)
{
	return x&-x;
}

void modify(int x,LL mx)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		d[i] = max(d[i],mx);
	}
}

LL query(int x)
{
	LL res = 0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		res = max(res,d[i]);
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d %d",r+i,h+i),v[i] = (LL)r[i]*r[i]*h[i];
	sort(v,v+n);
	int pn = unique(v,v+n) - v;
	memset(d,0,sizeof d);
	LL ans = 0;
	for(int i=0;i<n;++i)
	{
		LL vol = (LL)r[i]*r[i]*h[i],cur;
		int p = lower_bound(v,v+pn,vol) - v +1;
		cur = vol + query(p-1);
		ans = max(ans,cur);
		modify(p,cur);
	}
	//printf("%lld\n",ans);
	printf("%.12lf\n",pi*ans);
	return 0;
}




