#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1e5 + 10;
char s[22][maxn];
int n,m;
LL d[22][1<<20];

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);	
	F(i,0,n-1) scanf("%s",s[i]);
	F(j,0,m-1)
	{
		int num = 0;
		F(i,0,n-1) num = (num<<1) + s[i][j] - '0';
		d[0][num]++;
	}
	F(k,1,n)
	{
		F(s,0,(1<<n)-1)
		{
			if(k >= 2) d[k][s] = (k-2-n)*d[k-2][s];
			F(j,0,n-1) d[k][s] += d[k-1][s^(1<<j)];
			d[k][s] /= k;
		}
	}
	LL ans = n*m;
	F(s,0,(1<<n)-1)
	{
		LL res = 0;
		F(k,0,n) res += min(k,n-k)*d[k][s];
//		printf("%d %d\n",s,res);
		ans = min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
