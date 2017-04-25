#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))


int main()
{
//	freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	R(z,T)
	{
		int n;
		scanf("%d",&n);
		puts(n&1?"Balanced":"Bad");
	}
	return 0;
}
