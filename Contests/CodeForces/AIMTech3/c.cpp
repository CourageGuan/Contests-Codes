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
	int i = 0,mv = 0;
	while(i < n && s[i] == 'a') ++i;
	for(;i<n;++i)
	{
		if(s[i] != 'a')
		{
			++mv;
			s[i] = s[i] - 1;
		}
		else break;
	}
	if(mv == 0) s[n-1] = 'z';
	puts(s);
	return 0;
}
