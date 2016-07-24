#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;
#define R(i,n) for(int i=0;i<(n);++i)
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fill(a,b) memset(a,b,sizeof (a));

const int maxn = 2e5 + 10;
struct P{
	int x,in;
	int id;
	P() {}
	P(int x,int in,int id):x(x),in(in),id(id) {}
	bool operator<(const P& rhs) const
	{
		return x < rhs.x;
	}
} p[2*maxn];
int n,ans[maxn],B[maxn],pos[maxn];

void add(int x,int d)
{
	for(;x>0;x -= x&-x) B[x] += d;
}

int query(int x)
{
	int res = 0;
	for(;x<=n;x += x&-x) res += B[x];
	return res;
}


int main()
{
	//freopen("test.txt","r",stdin);
	int m = 0;
	cin >> n;
	R(i,n)
	{ 
		int l,r;
		scanf("%d %d",&l,&r);
		p[m++] = P(l,1,i);
		p[m++] = P(r,-1,i);
	}
	sort(p,p+m);
	int tot = 1;
	R(i,m) if(p[i].in == 1) pos[p[i].id] = tot++;
	R(i,m)
	{
		if(p[i].in == -1)
		{
//			printf("%d..\n",pos[p[i].id]);
			ans[p[i].id] = query(pos[p[i].id]);
			add(pos[p[i].id],1);
		}
	}
	R(i,n) cout << ans[i] << '\n';
	return 0;
}
