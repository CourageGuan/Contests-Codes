#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const double eps = 1e-8;
const double delta = 0.99;
const double INF = 1e20;
const int T = 100;
const int maxn = 110;

struct Point {
	double x,y,z;
};

int n;
Point p[maxn];

double dist(Point A,Point B)
{
	return sqrt( (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) + (A.z-B.z)*(A.z-B.z) );
}

void solve()
{
	Point s;
	for(int i=0; i<n; ++i)
		s.x += p[i].x,s.y += p[i].y,s.z += p[i].z;
	s.x /= n,s.y /= n,s.z /= n;
	double t = T,ans = INF;
	while(t > eps)
	{
		int k = 0;
		for(int i=0; i<n; ++i)
			if(dist(s,p[i]) > dist(s,p[k])) k = i;
		double d = dist(s,p[k]);
		ans = min(ans,d);
		s.x += (p[k].x - s.x)/d * t;
		s.y += (p[k].y - s.y)/d * t;
		s.z += (p[k].z - s.z)/d * t;
		t *= delta;
	}
	printf("%.5f\n",ans);
}

int main()
{
//	freopen("test.txt","r",stdin);
	while(~scanf("%d",&n) && n)
	{
		for(int i=0;i<n;++i)
			scanf("%lf %lf %lf",&p[i].x,&p[i].y,&p[i].z);
		solve();
	}
	return 0;
}
