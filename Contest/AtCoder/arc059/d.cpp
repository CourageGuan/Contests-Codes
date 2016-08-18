#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
char s[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s",s);
	int n = strlen(s);
	R(i,n-1) 
	{
		if(s[i] == s[i+1])
		{
			printf("%d %d\n",i+1,i+2);
			return 0;
		}
		if(i+2 < n && s[i] == s[i+2])
		{
			printf("%d %d\n",i+1,i+3);
			return 0;
		}
	}
	puts("-1 -1");
	return 0;
}
