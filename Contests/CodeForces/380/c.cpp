#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fi first
#define se second

const int maxn = 2e5 + 10;
int n,k,s,t;
int g[maxn];
vector<pair<int,int> > V,C;

LL cal(LL l,LL v)
{
	if(v >= 2*l) return l;
	if(v < l) return -1;
	return 3*l - v;
}

int judge(int id)
{
	int v = C[id].se;
	LL res = 0;
	F(i,0,k)
	{
		LL cur = cal(g[i],v);
		if(cur == -1) return 0;
		res += cur;
	}
	return res <= t;
}

int getans()
{
	int l = 0,r = C.size()-1,res = -1;
	while(l <= r)
	{
		int m = l+r >> 1;
		if(judge(m))
		{
			res = C[m].fi;
			r = m - 1;
		}
		else l  = m + 1;
	}
	return res;
}

void solve()
{
	scanf("%d %d %d %d",&n,&k,&s,&t);
	F(i,1,n)
	{
		int c,v;
		scanf("%d %d",&c,&v);
		V.push_back(make_pair(c,v));
	}
	F(i,1,k) scanf("%d",g+i-1);
	sort(g,g+k);
	g[k] = s;
	for(int i=k;i>=1;--i) g[i] = g[i] - g[i-1];
	sort(V.begin(),V.end());
	int cur = 0;
	for(int i=0;i<V.size();++i)
	{
		if(i != V.size()-1 && V[i].fi == V[i+1].fi) continue;
		if(V[i].se <= cur) continue;
		cur = V[i].se;
		C.push_back(V[i]);
	}
	printf("%d\n",getans());
}

int main()
{
//	freopen("input.txt","r",stdin);
	solve();
	return 0;
}
