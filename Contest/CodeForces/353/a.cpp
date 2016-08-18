#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

int main()
{
	//freopen("test.txt","r",stdin);
	LL a,b,c;
	cin >> a >> b >> c;
	if(c == 0)
		puts(a==b?"YES":"NO");
	else 
	{
		LL t = b - a;
		if(t*c < 0) puts("NO");
		else puts(t%c == 0?"YES":"NO");
	}
	return 0;
}
