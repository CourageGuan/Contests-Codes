#include<bits/stdc++.h>
using namespace std;

const double INF = 1e20;
const double eps = 1e-12;
const double pi = acos(-1.0);
double mx,mn;


const int maxn = 1e5 + 10;
int n;

struct Point{
	double x,y;
	Point() {}
	Point(double x,double y):x(x),y(y) {}
	Point operator-(const Point& rhs) const{
		return Point(x-rhs.x,y-rhs.y);
	}
} p[maxn],p0;
typedef Point Vector;

double dis2(Point a,Point b)
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

double Dot(Vector a,Vector b)
{
	return a.x*b.x + a.y*b.y;
}

double Cross(Vector a,Vector b)
{
	return a.x*b.y - a.y*b.x;
}


int main()
{
	//freopen("test.txt","r",stdin);
	mx = 0;
	mn = INF;
	scanf("%d %lf %lf",&n,&p0.x,&p0.y);
	for(int i=0;i<n;++i)
	{
		scanf("%lf %lf",&p[i].x,&p[i].y);
		mx = max(mx,dis2(p[i],p0));
	}
	p[n] = p[0];
	for(int i=1;i<=n;++i)
	{
		Vector v = p[i] - p[i-1],v1 = p[i] - p0,v2 = p[i-1] - p0;
		double res ;
		if(Dot(v,v1) < 0 ) res = dis2(p0,p[i]);
		else if(Dot(v,v2) > 0) res = dis2(p0,p[i-1]);
		else res = Cross(v1,v2)*Cross(v1,v2)/dis2(p[i],p[i-1]);
		mn = min(mn,res);
	}
//	printf("%lf %lf\n",mx,mn);
	printf("%.12lf\n",pi*(mx - mn));
	return 0;
}

