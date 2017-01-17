#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))
LL sum;
LL n,m;

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	while(scanf("%d",&T) == 1)
	{
		R(z,T)
		{
			scanf("%lld",&n);
			bool flag = 1;
			int cnt = 0;
			sum = 0;
			R(i,n)
			{
				scanf("%d",&m);
				sum += m;
				if(m > 2*(n-1)) flag = 0;
				if(m == 2*(n-1)) ++cnt;
			}
			if(cnt > 1 || n*(n-1) != sum) flag = 0;
			puts(flag?"T":"F");
		}
	}
	return 0;
}
