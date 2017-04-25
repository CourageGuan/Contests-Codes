#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;
#define R(i,n) for(int i=0;i<(n);++i)
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fill(a,b) memset(a,b,sizeof (a));

const int maxn = 3e5 + 10;
struct P{
	int p,d;
	int id;
	P()  {}
	P(int p,int d,int id):p(p),d(d),id(id) {}
	bool operator<(const P& rhs) const
	{
		return p < rhs.p;
	}
} p[maxn];
int ans[maxn],pos[maxn];
int n,m;
LL t;

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> m >> t;
	t %= 1LL*n*m;
	R(i,n)
	{
		int pos;
		char s[2];
		scanf("%d %s",&pos,s);
		--pos;
		p[i] = P(pos,s[0] == 'L'?-1:1,i);
	}
	sort(p,p+n);
	int bg = 0;
	R(i,n)
	{
		if(p[i].d == 1) bg = (bg - (p[i].p+t)/m)%n;
		else bg = (bg + (m-1 - p[i].p + t)/m)%n;
		pos[i] = ((p[i].p+p[i].d*t)%m + m)%m;
	}
	bg = (bg+n)%n;
	//printf("%d\n",bg);
	sort(pos,pos+n);
	rotate(p,p+bg,p+n);
	R(i,n) ans[p[i].id] = pos[i] + 1;
	R(i,n) printf("%d ",ans[i]);
	return 0;
}

