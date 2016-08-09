#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e6 + 10;
int bit[maxn],sum[maxn],ans[maxn],a[maxn];
int n,m;

map<int,int> pos;

void add(int x,int val)
{
	for(;x <= n;x += x&-x) bit[x] ^= val;
}

int query(int x)
{
	int res = 0;
	for(;x;x -= x&-x) res ^= bit[x];
	return res;
}

struct Q{
	int l,r,id;
	bool operator<(const Q& rhs) const
	{
		return r < rhs.r;
	}
} q[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i),sum[i] = sum[i-1]^a[i];
	scanf("%d",&m);
	F(i,1,m) scanf("%d %d",&q[i].l,&q[i].r),q[i].id = i;
	sort(q+1,q+1+m);
	int j = 0;
	F(i,1,m)
	{
		while(j < q[i].r)
		{
			++j;
			if(pos[a[j]]) add(pos[a[j]],a[j]);
			add(j,a[j]);
			pos[a[j]] = j;
		}
		ans[q[i].id] = sum[q[i].r] ^ sum[q[i].l-1] ^ query(q[i].r) ^ query(q[i].l-1);
	}
	F(i,1,m) printf("%d\n",ans[i]);
	return 0;
}

