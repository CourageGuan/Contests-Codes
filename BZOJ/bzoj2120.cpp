#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;

int n,m,cur,B;
int cntq,cntr;
int a[maxn],t[maxn],vis[int(1e6) + 10],ans[maxn];

struct Que{
	int l,r,id,re;
	Que() {}
	Que(int l,int r,int id,int re):l(l),r(r),id(id),re(re) {}
	bool operator<(const Que& rhs) const 
	{
		if(l/B == rhs.l/B) return r < rhs.r;
		else return l < rhs.l;
	}
} q[maxn];

struct Rep{
	int p,col;
	Rep() {}
	Rep(int p,int col):p(p),col(col) {}
} r[maxn];


void update(int pre,int now)
{
	if(pre != now && --vis[pre] == 0) --cur;
	if(vis[now]++ == 0) ++cur;
}

void solve()
{
	memset(vis,0,sizeof vis);
	int L = 0,R = -1,pre = 0;
	vis[0] = 1;
	cur = 0;
	for(int i=0;i<cntq;++i)
	{
		for(int j=q[i].re;j<pre;++j)
		{
			if(r[j].p >= L && r[j].p <= R)
			{
				if(t[r[j].p] != a[r[j].p]) update(a[r[j].p],t[r[j].p]);
			}
			a[r[j].p] = t[r[j].p];
		}
		for(int j=0;j<q[i].re;++j)
		{
			if(r[j].p >= L && r[j].p <= R)
			{
				if(r[j].col != a[r[j].p]) update(a[r[j].p],r[j].col);
			}
			a[r[j].p] = r[j].col;
		}
		pre = q[i].re;
		while(L < q[i].l) update(a[L++],0);
		while(L > q[i].l) update(a[--L],a[L]);
		while(R < q[i].r) update(a[++R],a[R]);
		while(R > q[i].r) update(a[R--],0);
		ans[q[i].id] = cur;
		//printf("%d %d %d %d\n",q[i].l,q[i].r,q[i].re,cur);
	}
	for(int i=0;i<cntq;++i) printf("%d\n",ans[i]);
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	memcpy(t,a,sizeof t);
	cntq = 0,cntr = 0;
	for(int i=0;i<m;++i)
	{
		char s[2];
		int L,R;
		scanf("%s %d %d",s,&L,&R);
		if(s[0] == 'Q')
			q[cntq] = Que(L-1,R-1,cntq++,cntr);
		else
			r[cntr++] = Rep(L-1,R);
	}
	B = sqrt(cntq) + 1;
	sort(q,q+cntq);
	solve();
	return 0;
}

