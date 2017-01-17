#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e7 + 10;
char s[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,kase = 1;
	while(scanf("%s",s) == 1)
	{
		int  a = 0,b = 0;
		R(i,strlen(s))
		{
			a = (a*10 + s[i]-'0')%73;
			b = (b*10 + s[i]-'0')%137;
		}
		printf("Case #%d: %s\n",kase++,a==0&&b==0?"YES":"NO");
	}
	return 0;
}
