#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 6; 
char s[maxn][maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int n,m;
	while(scanf("%d",&n,&m) == 2)
	{
		R(i,n) scanf("%s",s);
		m = strlen(s);
	}
	return 0;
}
