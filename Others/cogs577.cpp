#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 2e5 + 10;
const int maxw = 2e6 + 10;

struct Q {
	int op,x,y,z,id,t;
	bool operator<(const Q& rhs) const {
		return x < rhs.x;
	}
} q[maxn*4],s[maxn*4];

int ans[maxn];
int bit[maxw],w,n;
inline void add(int x,int d)
{
	for(;x <= w;x += x&-x) bit[x] +=  d;
}
inline int query(int x)
{
	int res = 0;
	for(;x;x -= x&-x) res += bit[x];
	return res;
}

void solve(int l,int r)
{
	if(l == r) return; 
	int m = (l+r)>>1,t1 = l-1,t2 = m,t = l;
	F(i,l,r) if(q[i].t <= m) s[++t1] = q[i];
	else s[++t2] = q[i];
	memcpy(q+l,s+l,sizeof(Q)*(r-l+1));
	F(i,m+1,r) if(q[i].op == 2)
	{
		for(;t <= m && q[t].x <= q[i].x;++t) 
			if(q[t].op == 1) add(q[t].y,q[t].z);
		ans[q[i].id] += query(q[i].y)*q[i].z;
	}
	F(i,l,t-1) if(q[i].op == 1) add(q[i].y,-q[i].z);
	solve(l,m); solve(m+1,r);
}

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("mokia.in","r",stdin);
	freopen("mokia.out","w",stdout);
	scanf("%d %d",&n,&w);
	int tot = 0,id = 0,op;
	while(~scanf("%d",&op) && op != 3)
	{
		int x,y,z,zz;
		scanf("%d %d %d",&x,&y,&z);
		if(op == 1)
		{
			q[++tot] = (Q){op,x,y,z,0,tot};
		}
		else
		{
			scanf("%d",&zz);
			q[++tot] = (Q){op,z,zz,1,id,tot};
			q[++tot] = (Q){op,x-1,y-1,1,id,tot};
			q[++tot] = (Q){op,x-1,zz,-1,id,tot};
			q[++tot] = (Q){op,z,y-1,-1,id++,tot};
		}
	}
	sort(q+1,q+tot+1);
	solve(1,tot);
	R(i,id) printf("%d\n",ans[i]);
	return 0;
}
