#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))


struct P{
	int b,c,id,cnt;
	bool operator<(const P& rhs) const
	{
		return c > rhs.c;
	}
};

bool cmp(const P& a,const P& b) 
{
	return a.b > b.b;
}

const int maxn = 1e5 + 10;
P p[maxn];
pair<int,int> a[maxn];
int ans[maxn],res[maxn];
int n,m,s;

bool yes(int t)
{
	priority_queue<P> q;
	int j = 0;
	LL cost = 0;
	R(i,m)
	{
		while(j < n && p[j].b >= a[i].first) q.push(p[j]),++j;
		if(q.empty()) return 0;
		P u = q.top(); q.pop();
		u.cnt++;
		res[a[i].second] = u.id+1;
		cost += u.c;
		u.c = 0;
		if(u.cnt < t) q.push(u);
		if(cost > s) return 0;
	}
	return 1;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&s);
	R(i,m)
	{
		int x;
	   	scanf("%d",&x);
		a[i].first = x;
		a[i].second = i;
	}
	sort(a,a+m,greater<pair<int,int> >());
	R(i,n) scanf("%d",&p[i].b),p[i].id = i;
	R(i,n) scanf("%d",&p[i].c),p[i].cnt = 0;
	sort(p,p+n,cmp);
	int l = 1,r = m,ret = -1;
	while(l <= r)
	{
		int m = l+r>>1;
		if(yes(m))
		{
			memcpy(ans,res,sizeof(ans));
			ret = m;
			r = m - 1;
		}
		else l = m+1;
	}
	if(ret == -1) puts("NO");
	else
	{
		puts("YES");
		R(i,m) printf("%d ",ans[i]);
	}
	return 0;
}
