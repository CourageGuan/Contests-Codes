#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

int n;

bool yes(int i)
{
	return 0 < i && i <= n;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	LL cnt = 0;
	F(i,1,n)
	{
		if(!yes(i+b-c)) continue;
		if(!yes(i+a-d)) continue;
		if(!yes(i+a+b-c-d)) continue;
		cnt += n;
	}
	printf("%lld\n",cnt);
	return 0;
}
