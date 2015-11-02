#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const double eps = 1e-8;

LL gcd(LL a,LL b)
{
	return !b?a:gcd(b,a%b);
}

int main()
{
	//freopen("test.txt","r",stdin);
	LL t,w,b,ans = 0;
	scanf("%lld %lld %lld",&t,&w,&b);

	if(w > b) swap(w,b);
	LL g = gcd(w,b);

	if((double)w/g <= (double)t/b)
	{
		LL lcm = w/g*b;
		ans = (t/lcm)*w - 1 + min(w,t%lcm + 1);
	}
	else
	{
		ans = min(w-1,t);
	}

	if(ans == 0) printf("%d/%d",0,1);
	else 
	{
		LL d = gcd(ans,t);
		printf("%I64d/%I64d",ans/d,t/d);
	}
	return 0;
}
