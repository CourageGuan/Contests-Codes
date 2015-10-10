#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;
const double eps = 1e-10;

double x[4],y[4];

int cmp(double a,double b)
{
	if(fabs(a-b)<eps) return 0;
	return a>b?1:-1;
}

double dis(double x1,double y1,double x2,double y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}


int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		int p[4];
		memset(p,0,sizeof p);
		for(int i=0;i<4;++i)
		{
			scanf("%lf %lf",x+i,y+i);
		}
		printf("Case #%d: ",z);
		if(!cmp(dis(x[0],y[0],x[1],y[1]),dis(x[2],y[2],x[3],y[3])) && !cmp(dis(x[0],y[0],x[3],y[3]),dis(x[1],y[1],x[2],y[2]))) p[0] = 1;
		else
		{
		   	puts("Others");
			continue;
		}
		if(!cmp(dis(x[0],y[0],x[2],y[2]),dis(x[1],y[1],x[3],y[3]))) p[1] = 1;
		if(!cmp(dis(x[0],y[0],x[1],y[1]),dis(x[1],y[1],x[2],y[2]))) p[2] = 1;
		if(p[1] && p[2]) puts("Square");
		else if(p[1]) puts("Rectangle");
		else if(p[2]) puts("Diamond");
		else puts("Parallelogram");
	}
	return 0;
}
