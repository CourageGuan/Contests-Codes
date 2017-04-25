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
	int n,m;
	cin >> n >> m;
	int yes = 0;
	R(i,n)
	{
		char s[2];
		R(j,m)
		{
			cin >> s;
			if(s[0] == 'C' || s[0] == 'M' || s[0] == 'Y') yes = 1;
		}
	}
	puts(yes?"#Color":"#Black&White");
	return 0;
}
