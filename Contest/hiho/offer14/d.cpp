#include<bits/stdc++.h> 
using namespace std;

const int maxn = 2010;
const double pi = acos(-1.0);
 
struct P
{
	double x, y;
	P(double x, double y) : x(x), y(y){}
	P() {}
} p[maxn];
 
struct A
{
	double angle;
	bool flag;
 
	bool operator<(const A &rhs) const
	{
		return angle < rhs.angle;
	}
} a[maxn*2];
 
inline double dis(const P &p, const P &q)
{
	return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}
 
inline int solve(const int& n, const double& r)
{
	int res = 1;
	for (int i = 0; i < n; ++i)
	{
		int m = 0;
		double d;
		for (int j = 0; j < n; ++j)
		{
			if (i != j && (d = dis(p[i], p[j])) <= 2*r)
			{
				double phi = acos(d/2/r);
				double theta = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
				if(theta < 0) theta += 2*pi;
				a[m].angle = theta - phi + 2*pi, a[m++].flag = 1;
				a[m].angle = theta + phi + 2*pi, a[m++].flag = 0;
			}
		}
		sort(a, a + m);
		for (int sum = 1, j = 0; j < m; ++j)
		{
			if (a[j].flag)
				++sum;
			else
				--sum;
			res = max(res, sum);
		}
	}
	return res;
}
 
int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	double r;
	scanf("%d %lf",&n,&r);
	for (int i = 0; i < n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
	if(n == 1) 
		puts("1");
	else
		printf("%d\n", solve(n, r));
	return 0;
}
