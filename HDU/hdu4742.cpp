#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define R(i,n) for(int i=0;i<(n);++i)
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define mp make_pair

const LL mod = (1<<30) - 1;
const int maxn = 1e5 + 10;
int n,all[maxn],tot;
struct Res{
	LL a,b;
	Res(LL a=0,LL b=0):a(a),b(b) {}
	Res operator+(const Res& rhs) const
	{
		Res res = *this;
		if(a < rhs.a) res = rhs;
		else if(a == rhs.a) res.b = (res.b+rhs.b)&mod;
		return res;
	}
} bit[maxn],ans[maxn];
struct P{
	int x,y,z,id;
	bool operator<(const P& rhs) const
	{
		if(x != rhs.x) return x < rhs.x;
		else if(y != rhs.y) return y < rhs.y;
		else return z < rhs.z;
	}
} p[maxn];
vector<P> op;

bool cmp(const P& a,const P& b)
{
	return a.y < b.y || (a.y == b.y && a.z < b.z) || (a.z == b.z && a.id < b.id);
}

void add(int x,Res p)
{
	for(;x<=n;x += x&-x) bit[x] = bit[x] + p;
}

Res query(int x)
{
	Res res;
	for(;x;x -= x&-x) res = res + bit[x];
	return res;
}

void clr(int x)
{
	for(;x <= n;x += x&-x) bit[x] = Res();
}

void init(int n)
{
	tot = 0;
	for(int i=0;i<n;++i) ans[i] = Res(1,1),bit[i+1] = Res(0,0);
}

void cdq(int L,int R)
{
	if(L == R) return;
	int m = (L+R) >> 1;
	cdq(L,m);
	op.clear();
	F(i,L,R) op.push_back(p[i]);
	sort(op.begin(),op.end(),cmp);
	R(i,op.size())
	{
		if(op[i].id > m) 
		{
			Res cur = query(op[i].z);
			cur.a ++;
			ans[op[i].id] = ans[op[i].id] + cur;
		//	printf("%d %d %d %d\n",cur.a,op[i].id,ans[op[i].id].a,ans[op[i].id].b);
		}
		else add(op[i].z,ans[op[i].id]);
	}
	R(i,op.size()) if(op[i].id <= m) clr(op[i].z);
	cdq(m+1,R);
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	R(z,T)
	{
		scanf("%d",&n);
		init(n);
		R(i,n)
		{
			scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
			all[tot++] = p[i].z;
		}
		sort(p,p+n);
		sort(all,all+tot);
		int pn = unique(all,all+tot) - all;
		R(i,n) p[i].z = lower_bound(all,all+pn,p[i].z) - all + 1,p[i].id = i;
		cdq(0,n-1);
		Res res = Res(1,1);
		R(i,n)
		{
		   	res = res + ans[i];
//			printf("%d %d %d %d\n",i,ans[i].a,ans[i].b,p[i].z);
		}
		printf("%lld %lld\n",res.a,res.b);
	}
	return 0;
}
