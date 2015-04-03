//集合dp，最优配对问题
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

const int maxn=16;
const double INF=1e9;
double d[(1<<maxn)];

struct Point{
	double x,y;
} p[maxn+2];

double dist(const Point& a,const Point& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	int n,kase=0;
	while(scanf("%d",&n)==1 && n){
		n*=2;
		char name[100];
		for(int i=0;i<n;++i){
		   	scanf("%s %lf %lf",name,&p[i].x,&p[i].y);
		}
		d[0]=0;
		for(int S=1;S<(1<<n);++S){
			int i,j;
			d[S]=INF;
			for(i=0;i<n;++i)
				if(S&(1<<i)) break;
			for(j=i+1;j<n;++j)
				if(S&(1<<j)) d[S]=min(d[S],dist(p[i],p[j])+d[S^(1<<i)^(1<<j)]);
		}
		printf("Case %d: %.2lf\n",++kase,d[(1<<n)-1]);
	}
	return 0;
}
