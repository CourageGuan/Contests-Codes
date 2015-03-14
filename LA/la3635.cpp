//二分答案，浮点数的跳出条件精度不能太高，否则易造成死循环，比答案高1-2个精度
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;


const double PI=acos(-1.0);
const double EPS=1e-5;
#define P(x) (PI*(x)*(x))
const int maxn=10000 + 5;
int f,n;
double pie[maxn];

bool ok(double s)
{
	int cnt=0;
	for(int i=0;i<n;++i)
		cnt+=floor(P(pie[i])/s);
	return cnt>=f;
}

int main()
{
	//freopen("test","r",stdin);
	int T; 
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&f);
		++f;
		double mx=-1;
		for(int i=0;i<n;++i){
			scanf("%lf",&pie[i]);
			mx=max(mx,pie[i]);
		}
		double l=0,r=P(mx);
		while(r-l>EPS){
			double m=l+(r-l)/2;
			if(ok(m)) l=m;
			else r=m;
		}
		printf("%.4lf\n",l);
	}
	return 0;
}

