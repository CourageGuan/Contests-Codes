#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define P(x) ((x)*(x))
typedef long double LDB;
const LDB pi = acosl(-1.0);
double x[2],y[2],r[2];

LDB solve()
{
	LDB d = sqrtl(P(x[0]-x[1])+P(y[0]-y[1]));

	// out
	if(d >= r[0] + r[1]) return 0;

	// in
	if(d <= r[1] - r[0]) return pi*P(r[0]);


	// cross 
	
	// 余弦定理
	LDB a0 = acosl((P(r[0])+P(d)-P(r[1]))/(2*r[0]*d));
	LDB a1 = acosl((P(r[1])+P(d)-P(r[0]))/(2*r[1]*d));
	
	return a0*P(r[0]) + a1*P(r[1]) - P(r[0])*sinl(2*a0)/2 - P(r[1])*sinl(2*a1)/2;
}

int main()
{
	//freopen("test.txt","r",stdin);

	for(int z=0;z<2;++z) scanf("%lf%lf%lf",x+z,y+z,r+z);
	if(r[0] > r[1]) swap(x[0],x[1]),swap(y[0],y[1]),swap(r[0],r[1]);

	//cout<<fixed<<setprecision(10)<<solve()<<'\n';
	printf("%.14lf\n",(double)solve());

	return 0;
}
