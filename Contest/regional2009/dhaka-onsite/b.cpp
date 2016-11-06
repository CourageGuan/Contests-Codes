#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL C[66][66],res[66];
int bit[66],tot,cnt;


LL cal(LL n)
{
	if(n == -1) return 0;
	memset(res,0,sizeof res);
	cnt = tot = 0;
	LL t = n;
	while(t)
	{
		bit[++tot] = t&1;
		t >>= 1;
	}
	for(int i=tot;i;--i)
	{
		if(bit[i] == 1)
		{
			for(int j=(cnt==0);j<i;++j)
				res[cnt+j] = res[cnt+j] + C[i-1][j];
		}
		cnt += bit[i];
	}
	LL ans = cnt;
	for(int i=1;i<=tot;++i)
		ans = ans + i*res[i];
	return ans;
}

void init()
{
	for(int i=0;i<66;++i)
	{
		C[i][0] = 1;
		for(int j=1;j<=i;++j)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
}

LL a,b;

int main()
{
//	freopen("input.txt","r",stdin);
	init();
	int z = 0;
//	printf("%lld\n",cal(1));
	while(scanf("%lld %lld",&a,&b) == 2 && a+b)
	{
		printf("Case %d: %lld\n",++z,cal(b)-cal(a-1));
	}
	return 0;
}
