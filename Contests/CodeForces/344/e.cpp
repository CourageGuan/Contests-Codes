#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
#define fi first
#define se second

const int maxn = 2e5 + 10; 
LL sum[maxn],a[maxn],ans;
int n;

vector<pll> V;

bool check(pll a,pll b,pll c)
{
	return (a.fi - b.fi)*(b.se - c.se) >= (b.se - a.se)*(c.fi - b.fi);
}

void add(LL k,LL b)
{
	pll p(k,b);
	while(V.size() >= 2 && check(V[V.size()-2],V[V.size()-1],p)) V.pop_back();
	V.push_back(p);
}

LL cal(LL x,int i)
{
	return x*V[i].fi + V[i].se;
}

LL query(LL x)
{
	int l = -1,r = V.size()- 1;
	while(r - l > 1)
	{
		int m = (l+r)/2;
		if(cal(x,m+1) >= cal(x,m)) l = m;
		else r = m;
	}
	return cal(x,r);
}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);	
	ans = 0;
	for(int i=1;i<=n;++i) scanf("%lld",a+i),ans += i*a[i],sum[i] = sum[i-1] + a[i];
	LL res = 0;
	for(int r=2;r<=n;++r)
	{
		add(r-1,-sum[r-2]);
		res = max(res,query(a[r])+sum[r-1]-r*a[r]);
		//printf("%d %d\n",res,r);
	}
	V.clear();
	for(int l=n-1;l>=1;--l)
	{
		add(-(l+1),-sum[l+1]);
		res = max(res,query(-a[l])+sum[l]-l*a[l]);
		//printf("%d %d\n",res,l);
	}
	printf("%lld\n",ans+res);
	return 0;
}



