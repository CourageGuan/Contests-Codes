#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)

const LL INF = 0x3f3f3f3f3f3f3f3fLL;
LL d,k,a,b,t;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%lld %lld %lld %lld %lld",&d,&k,&a,&b,&t);
	LL l = 0,r = d/k,res = INF;
	res = min(d*b,a*k*r + t*(max(0LL,(r-1)+(d%k != 0))) + (d-k*r)*a);
//	printf("%d\n",res);
	if(k < d)
		res = min(res,(d-k)*b + a*k);
	if(r*k < d)
		res = min(res,(d-r*k)*b + a*k*r + t*(max(0LL,r-1)));
	printf("%lld\n",res);
	return 0;
}
