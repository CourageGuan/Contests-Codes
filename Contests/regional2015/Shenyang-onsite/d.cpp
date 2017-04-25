#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

int main()
{
//	freopen("input.txt","r",stdin);
	int n,a,b,T;
	scanf("%d",&T);
	F(z,1,T)
	{
		scanf("%d%d%d",&n,&a,&b);
		printf("Case #%d: ",z),puts((n/__gcd(a,b))&1?"Yuwgna":"Iaka");
	}
	return 0;
}
