#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

const double dis=10000;

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)==2){
		int all=n+m;
		double ans=0;
		for(int i=1;i<n;++i){
			double pos=(double)i/n * all;
			ans+=fabs(pos-(int)(pos+0.5)) / all;
		}
		printf("%.4lf\n",ans*dis);
	}
	return 0;
}
