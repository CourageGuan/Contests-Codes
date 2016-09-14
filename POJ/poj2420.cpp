#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

typedef pair<double,double> Point;
#define x first 
#define y second

const double eps = 1e-8;
const double delta = 0.98;
const double INF = 1e20;
const int T = 100;
const int maxn = 110;

int n;
Point p[maxn];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

double dist(Point A,Point B)
{
	return sqrt( (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) );
}

double cal(Point t)
{
	double ans = 0;
	for(int i=0;i<n;++i) ans += dist(p[i],t);
	return ans;
}

void solve()
{
	Point s = p[0];
	double t = T,ans = INF;
	while(t > eps)
	{
		bool flag = 1;
		while(flag)
		{
			flag = 0;
			for(int i=0;i<4;++i)
			{
				Point c = make_pair(s.x+dx[i]*t,s.y+dy[i]*t);
				double cur = cal(c);
				if(ans > cur)
				{
					ans = cur;
					s = c;
					flag = 1;
				}
			}
		}
		t *= delta;
	}
	printf("%d\n",(int)(ans+0.5));
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		solve();
	}
	return 0;
}
