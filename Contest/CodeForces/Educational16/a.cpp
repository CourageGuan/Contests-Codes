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
	char s[2];
	cin >> s;
	if(s[1] == '1' || s[1] == '8' || s[0] == 'a' || s[0] == 'h')
	{
		if((s[1] == '1' || s[1] == '8') && (s[0] == 'a' || s[0] == 'h'))
		{
			puts("3");
			return 0;
		}
		puts("5");
		return 0;
	}
	puts("8");
	return 0;
}
