#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod = 1e9 + 7;
const int maxn = 2010;
int n,m;
LL d[maxn][maxn];
char s[int(1e5) + 10];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&m);
	memset(d,0,sizeof d);
	d[0][0] = 1;
	int t = n-m;

	for(int i=1;i<=t;++i)
		for(int j=0;j<=i;++j)
			if(!j)
				d[i][j] = (d[i][j] + d[i-1][j+1]) %mod;
			else
				d[i][j] = (d[i][j] + d[i-1][j+1] + d[i-1][j-1]) %mod;

	scanf("%s",s);
	int mn = 0,cur = 0;
	for(int i=0;i<m;++i)
	{
		cur += (s[i] == '('?1:-1);
		mn = min(mn,cur);
	}

	LL ans = 0;
	for(int i=0;i<=t;++i)
		for(int j=0;j<=i;++j)
		{
			if(j + mn < 0 || abs(j+cur) > t-i) continue;
			ans = (ans+d[i][j]*d[t-i][abs(j+cur)]) %mod;
		}
	printf("%lld\n",ans);
	return 0;
}
