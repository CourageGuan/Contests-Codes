#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;

LL qpow(LL a,LL n,LL mod)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a %mod;
		a = a*a%mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	int T;
	LL x,m,k,c;
	cin >> T;
	for(int z=1;z<=T;++z)
	{
		cin >>x>>m>>k>>c;
		printf("Case #%d:\n%s\n",z,(qpow(10,m,9*k)-1)/9*x%k == c?"Yes":"No");
	}
	return 0;
}
