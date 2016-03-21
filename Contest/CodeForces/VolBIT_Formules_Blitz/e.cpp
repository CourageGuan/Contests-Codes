#include<cstdio>

typedef long long LL;

int main()
{
	LL x1,y1,x2,y2,res;
	scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
	LL t1 = x2 - x1 + 1,t2 =(y2 - y1 + 2)/2;
	if(t1&1) printf("%lld\n",(t1+1)/2 * t2 + t1/2 * (t2-1));
	else printf("%lld\n",t1*t2);
	return 0;
}
