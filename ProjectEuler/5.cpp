#include<bits/stdc++.h>
using namespace std;


int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

int solve()
{
	int res=2;
	for(int i=3;i<=20;++i)
		res = res/gcd(res,i)*i;
	return res;
}

int main()
{
	printf("%d\n",solve());
	return 0;
}
