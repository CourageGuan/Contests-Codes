#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,a,b,c;

LL cal()	
{
	if(a <= b-c) return n/a;
	LL res = 0,t = n;
	if(t <= b) return max(t/b,t/a);
	res += (t-b)/(b-c);
	t = (t-b)%(b-c) + b;
	while(t/b > 0)
	{
		LL rem = t%b;
		rem += (t/b)*c;
		res += t/b;
		t = rem;
	}
	return res + t/a;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
	printf("%lld\n",cal());
	return 0;
}
