#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int n,m,k,B,a[maxn];
int cnt[1 << 20];
LL pre[maxn],ans[maxn],cur;

struct Res{
	int l,r;
	int id;
	bool operator<(const Res& rhs) const
	{
		if(l/B == rhs.l/B) return r < rhs.r;
		else return l < rhs.l;
	}
} q[maxn];

void add(int x)
{
	cur += cnt[pre[x]^k];
	++cnt[pre[x]];
}

void del(int x)
{
	--cnt[pre[x]];
	cur -= cnt[pre[x]^k];
}

void solve()
{
	memset(cnt,0,sizeof cnt);
	int L = 1,R = 0;
	++cnt[0];
	cur = 0;
	for(int i=0;i<m;++i)
	{
		while(L < q[i].l) del((L++)-1);
		while(L > q[i].l) add((--L)-1);
		while(R < q[i].r) add(++R);
		while(R > q[i].r) del(R--);
		ans[q[i].id] = cur;
	}
	for(int i=0;i<m;++i) printf("%lld\n",ans[i]);
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;++i) scanf("%d",a+i+1);
	pre[0] = 0;
	for(int i=1;i<=n;++i) pre[i] = pre[i-1]^a[i];
	for(int i=0;i<m;++i) scanf("%d %d",&q[i].l,&q[i].r),q[i].id = i;
	B = sqrt(m) + 1;
	sort(q,q+m);
	solve();
	return 0;
}

