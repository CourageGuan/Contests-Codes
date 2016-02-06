#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;

const int maxn = 5e4 + 10;

struct Res{
	int l,r,id;
	LL up,down;
} res[maxn];

int c[maxn],pos[maxn],cur[maxn];
int m,n,B,val;

LL gcd(LL a,LL b)
{
	return !b?a:gcd(b,a%b);
}

bool cmp(const Res& a,const Res& b)
{
	if(pos[a.l] == pos[b.l]) return a.r < b.r;
	else return a.l < b.l;
}

bool cmp_id(const Res& a,const Res& b)
{
	return a.id < b.id;
}

void update(int p,int ad)
{
	val -= (LL)cur[p]*(cur[p]-1)/2;
	cur[p] += ad;
	val += (LL)cur[p]*(cur[p]-1)/2;
}

void solve()
{
	LL l,r;
	val = 0;
	l = r = 1;
	memset(cur,0,sizeof cur);
	update(c[1],1);
	for(int i=0;i<m;++i)
	{
		res[i].down = (LL)(res[i].r - res[i].l + 1)*(res[i].r - res[i].l)/2;
		for(;l<res[i].l;++l) update(c[l],-1);
		for(;l>res[i].l;--l) update(c[l-1],1);
		for(;r<res[i].r;++r) update(c[r+1],1);
		for(;r>res[i].r;--r) update(c[r],-1);
		res[i].up = val;
		//printf("%d %lld\n",res[i].id,val);
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	int mx = 0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",c+i);
	for(int i=0;i<m;++i) scanf("%d %d",&res[i].l,&res[i].r),res[i].id = i,mx = max(mx,res[i].l);
	B = sqrt(n);
	for(int i=1;i<=mx;++i) pos[i] = i/B;
	sort(res,res+m,cmp);
	solve();
	sort(res,res+m,cmp_id);
	for(int i=0;i<m;++i)
	{
		LL t = gcd(res[i].up,res[i].down);
		if(!res[i].up) puts("0/1");
		else printf("%lld/%lld\n",res[i].up/t,res[i].down/t);
	}
	return 0;
}
