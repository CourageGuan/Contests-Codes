#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int mod = 1e9 + 7;
const int p2 = 500000004;
const int maxn = 5010;
int d[2][maxn];
char s[maxn];
int n;

void add(int& a,int b)
{
	a += b;
	if(a > mod) a -= mod;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %s",&n,s);
	int m = strlen(s);
	int p = 1;
	d[p][0] = 1;
	R(i,n)
	{
		p ^= 1;
		fill(d[p],0);
		F(j,0,i)
		{
			add(d[p][max(j-1,0)],d[p^1][j]);
			add(d[p][j+1],2*d[p^1][j] %mod);
		}
	}
	LL ans = d[p][m];
	R(i,m) ans = ans*p2%mod;
	printf("%lld\n",ans);
	return 0;
}


