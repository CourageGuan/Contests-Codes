#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const double eps = 1e-8;
typedef long double LDB;

int main()
{
	//freopen("test.txt","r",stdin);
	LL l,r,k;
	scanf("%lld %lld %lld",&l,&r,&k);
	LDB L=l,R=r,K=k;
	bool flag = false;
	LDB res = 1;
	while(res < L) res *= K;
	while(res <= R) 
	{
		flag = 1;
		printf("%lld ",(LL)res);
		res *= K;
	}
	if(!flag) puts("-1");
	return 0;
}
