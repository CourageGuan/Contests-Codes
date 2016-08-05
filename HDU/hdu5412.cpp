#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;

int n,m,tot;
int bit[maxn],a[maxn],ans[maxn];

struct Q{
	int x,y,k,op,id;
} q[maxn*3],q1[maxn*3],q2[maxn*3];


void add(int x,int t)
{
	for(;x <= n;x += x&-x) bit[x] += t;
}

int query(int x)
{
	int res = 0;
	for(;x>0;x -= x&-x) res += bit[x];
	return res;
}

void deal(int L,int R,int l,int r)
{
	if(L > R) return;
	if(l == r)
	{
		F(i,L,R) if(!q[i].op) ans[q[i].id] = l;
		return;
	}
	int m = l+r >> 1,cnt1,cnt2;
	cnt1 = cnt2 = 0;
	F(i,L,R)
	{
		if(q[i].op)
		{
			if(q[i].y <= m)
			{
				add(q[i].x,q[i].op);
				q1[++cnt1] = q[i];
			}
			else q2[++cnt2] = q[i];
		}
		else
		{
			int t = query(q[i].y) - query(q[i].x-1);
			if(q[i].k <= t)
			{
				q1[++cnt1] = q[i];
			}
			else
			{
				q[i].k -= t;
				q2[++cnt2] = q[i];
			}
		}
	}

	F(i,1,cnt1) if(q1[i].op) add(q1[i].x,-q1[i].op);

	F(i,1,cnt1) q[L+i-1] = q1[i];
	F(i,1,cnt2) q[L+i+cnt1-1] = q2[i];

	deal(L,L+cnt1-1,l,m);
	deal(L+cnt1,R,m+1,r);
}


int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	while(~scanf("%d",&n))
	{
		int cnt = 0;
		tot = 0;
		F(i,1,n) scanf("%d",a+i),q[tot++] = (Q){i,a[i],0,1};
		scanf("%d",&m);
		F(i,1,m)
		{
			int op,x,y,k;
			scanf("%d %d %d",&op,&x,&y);
			if(op == 1)
			{
				q[tot++] = (Q){x,a[x],0,-1,0};
				q[tot++] = (Q){x,y,0,1,0};
				a[x] = y;
			}
			else
			{
				scanf("%d",&k);
				q[tot++] = (Q){x,y,k,0,++cnt};
			}
		}
		fill(bit,0);
		deal(0,tot-1,1,0x3f3f3f3f);
		F(i,1,cnt) printf("%d\n",ans[i]);
	}
	return 0; 
}
