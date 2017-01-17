#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

LL n,m;

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%lld %lld",&m,&n) == 2)
	{
		puts(n >= (m - (m/2))*(m/2)?"T":"F");
	}
	return 0;
}
