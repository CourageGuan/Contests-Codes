#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define fi first
#define se second
#define mp make_pair

LL r,c,n,sum;
LL ans[10];
vector<pair<int,int> >  p;
set<pair<int,int> > vis,has;

inline bool yes(int x,int y)
{
	return x>0 && y>0 && x <= r && y <= c;
}

inline void cal(int x,int y)
{
//	printf("%d %d\n",x,y);
	F(i,0,2)
		F(j,0,2)
		{
			int tx = x - i,ty = y - j;
			if(yes(tx,ty) && yes(tx+2,ty+2) && vis.find(mp(tx,ty)) == vis.end())
			{
				int cur = 0;
				F(k,tx,tx+2) F(l,ty,ty+2)
				{
				   	if(has.find(mp(k,l)) != has.end())
					{
					   	++cur;
					}
				}
				vis.insert(mp(tx,ty));
				ans[cur]++;
			}
		}
}

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%lld %lld %lld",&r,&c,&n);
	sum = (r-2) * (c-2);
	F(i,1,n)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		p.push_back(mp(x,y));
		has.insert(mp(x,y));
	}
	F(i,0,int(p.size())-1)
		cal(p[i].fi,p[i].se);
	F(i,1,9) sum -= ans[i];
	ans[0] = sum;
	F(i,0,9) printf("%lld\n",ans[i]);
	return 0;
}
