#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof (a))

LL n,l,v1,v2,k;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%lld%lld%lld%lld%lld",&n,&l,&v1,&v2,&k);		
	LL g = (n/k + (n%k!=0)) - 1;
	DB a = 1.0*l*(v1+v2)/(2*g*v1+v1+v2);
	printf("%.8lf\n",a/v2+(l-a)/v1);
	return 0;
}
