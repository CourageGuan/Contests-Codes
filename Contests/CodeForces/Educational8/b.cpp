#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 3e5 + 10;
char s[maxn];
LL d[maxn][4];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%s",s);
	int n = strlen(s);
	for(int i=0;i<n;++i)
	{
		int t = s[i] - '0';
		d[i][t%4]++;
		if(!i) continue;
		for(int j=0;j<4;++j)
			d[i][(t+j*10)%4] += d[i-1][j];
	}
	LL ans = 0;
	for(int i=0;i<n;++i) ans += d[i][0];
	printf("%lld\n",ans);
	return 0;
}
