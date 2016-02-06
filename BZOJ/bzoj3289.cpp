#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxn = 5e5 + 10;
int n,m,B;
int pos[maxn],b[maxn],a[maxn],p[maxn];
LL ans[maxn],cur; 


struct Res{
	int l,r,id;
} q[maxn];

bool cmp(const Res& a,const Res& b)
{
	if(a.l/B == b.l/B) return a.r < b.r;
	else return a.l < b.l;
}

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int val)
{
	for(;x<=n;x+=lowbit(x))
	{
		b[x] += val;
	}
}

LL query(int x)
{
	LL res = 0;
	for(;x>0;x-=lowbit(x))
	{
		res += b[x];
	}
	return res;
}

void solve()
{
	int l,r;
	l = r = 1;
	cur = 0;
	add(a[1],1);
	for(int i=0;i<m;++i)
	{
		for(;l<q[i].l;++l) cur -= query(a[l]-1),add(a[l],-1);
		for(;l>q[i].l;--l) cur += query(a[l-1]-1),add(a[l-1],1);
		for(;r<q[i].r;++r) cur += r-l+1 - query(a[r+1]),add(a[r+1],1);
		for(;r>q[i].r;--r) cur -= r-l+1 - query(a[r]),add(a[r],-1);
		ans[q[i].id] = cur;
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",p+i),a[i+1] = p[i];
	sort(p,p+n);
	for(int i=1;i<=n;++i) a[i] = lower_bound(p,p+n,a[i]) - p + 1;
	scanf("%d",&m);
	for(int i=0;i<m;++i) scanf("%d %d",&q[i].l,&q[i].r),q[i].id = i;
	B = sqrt(n+1);
	sort(q,q+m,cmp);
	solve();
	for(int i=0;i<m;++i) printf("%lld\n",ans[i]);
	return 0;
}
