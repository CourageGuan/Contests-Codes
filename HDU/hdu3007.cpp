#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 510;
const double eps = 1e-9;
struct Point{
	double x,y;
} p[maxn];
int n;

double dis(Point& a,Point& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

Point cal(Point& a,Point& b,Point& c)
{
	Point res;
	double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;  
	double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;  
	double d=a1*b2-a2*b1;  
	res.x=a.x+(c1*b2-c2*b1)/d;  
	res.y=a.y+(a1*c2-a2*c1)/d;  
	return res;
}

void solve(Point& res,double& r)
{
	random_shuffle(p,p+n);
	res = p[0]; r = 0;
	for(int i=1;i<n;++i)
	{
		if(dis(res,p[i]) > r+eps)
		{
			res = p[i],r = 0;
			for(int j=0;j<i;++j)
				if(dis(res,p[j]) > r+eps)
				{
					res.x = (p[i].x+p[j].x)/2;
					res.y = (p[i].y+p[j].y)/2;
					r = dis(p[j],res);
					for(int k=0;k<j;++k)
						if(dis(res,p[k]) > r+eps)
						{
							res = cal(p[i],p[j],p[k]);
							r = dis(p[i],res);
						}
				}
		}
	}
}


int main()
{
//	freopen("test.txt","r",stdin);
	while(~scanf("%d",&n) && n)
	{
		for(int i=0;i<n;++i) scanf("%lf %lf",&p[i].x,&p[i].y);
		double r;
		Point ans;
		solve(ans,r);
		printf("%.2lf %.2lf %.2lf\n",ans.x,ans.y,r);
	}
	return 0;
}
