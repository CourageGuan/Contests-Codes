#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

typedef long double LDB;
const int maxn = 1e5 + 10;
const LDB pi = acos(LDB(-1));

struct Vector
{
	int id;
	LDB ang;
	bool operator<(const Vector& rhs) const
	{
		return ang < rhs.ang;
	}
} v[maxn];


int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		v[i].ang = atan2(y,x);
		v[i].id = i+1;
	}
	sort(v,v+n);
	v[n] = v[0];
	v[n].ang = v[0].ang + 2*pi;
	LDB mn = 1e3;
	int ra,rb;
	ra = rb = -1;
	for(int i=0;i<n;++i)
	{
		LDB tt = v[i+1].ang - v[i].ang;
		if(tt < mn)
		{
			mn = tt;
			ra = v[i].id;
			rb = v[i+1].id;
		}
	}
	printf("%d %d\n",ra,rb);
	return 0;
}
