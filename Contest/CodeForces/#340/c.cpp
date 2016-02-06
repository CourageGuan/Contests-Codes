#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define P(x) ((x)*(x))
const int maxn = 2010;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int n;

struct Point{
	int id;
	LL x,y;
} p1[maxn],p2[maxn],p,q;

map<int,LL> val;

LL dis(Point a,Point b)
{
	return P(a.x - b.x)+P(a.y - b.y);
}

bool cmp1(const Point a,const Point b)
{
	return dis(a,p) < dis(b,p);
}

bool cmp2(const Point a,const Point b)
{
	return dis(a,q) < dis(b,q);
}



int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %lld %lld %lld %lld",&n,&p.x,&p.y,&q.x,&q.y);
	for(int i=0;i<n;++i)
	{
		scanf("%lld %lld",&p1[i].x,&p1[i].y);
		p2[i].x = p1[i].x; p2[i].y = p1[i].y;
		p1[i].id = p2[i].id = i;
	}
	sort(p1,p1+n,cmp1);
	sort(p2,p2+n,cmp2);

	LL ans = INF;

	for(int i=0;i<n;++i)
	{
		val[p2[i].id] = dis(p2[i],q);
	}
	for(int i=-1;i<n;++i)
	{
		LL r1 = 0,r2 = 0;
		if(i!=-1) r1 = dis(p1[i],p);
		for(int j=i+1;j<n;++j)
		{
			r2 = max(r2,val[p1[j].id]);
		}
		ans = min(ans,r1+r2);
//		printf("%lld %lld\n",r1,r2);
	}

	val.clear();
	for(int i=0;i<n;++i)
	{
		val[p1[i].id] = dis(p1[i],p);
	}
	for(int i=-1;i<n;++i)
	{
		LL r1 = 0,r2 = 0;
		if(i!=-1) r2 = dis(p2[i],q);
		for(int j=i+1;j<n;++j)
		{
			r1 = max(r1,val[p2[j].id]);
		}
		ans = min(ans,r1+r2);
//		printf("%lld %lld\n",r1,r2);
	}

	printf("%lld\n",ans);
	return 0;
}
