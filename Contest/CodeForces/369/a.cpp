#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1010;
char s[maxn][10];
int n;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	bool yes = 0 ;
	R(i,n)
	{
		scanf("%s",s[i]);
		if(yes) continue;
		if(s[i][0] == 'O' && s[i][1] == 'O')
		{
			yes = 1;
			s[i][0] = s[i][1] = '+';
			continue;
		}
		if(s[i][3] == 'O' && s[i][4] == 'O')
		{
			yes = 1;
			s[i][3] = s[i][4] = '+';
			continue;
		}
	}
	if(!yes) puts("NO");
	else
	{
		puts("YES");
		R(i,n) puts(s[i]);
	}
	return 0;
}
