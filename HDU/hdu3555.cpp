#include<cstdio>
#include<cstring>

typedef long long LL;
const int N = 20;

LL d[N][10][2];
int dig[N];

LL dfs(int x,int pre,int ye,int limit)
{
	if(x<0) return ye;
	LL &ans = d[x][pre][ye];
	if(!limit && ans!=-1) return ans;
	LL res = 0;
	int last = limit?dig[x]:9;
	for(int i=0;i<=last;++i)
		res += dfs(x-1,i,ye || (pre == 4 && i == 9),limit && (i==last));
	if(!limit) ans = res;
	return res;
}

LL solve(LL n)
{
	memset(d,-1,sizeof d);
	int len = 0;
	while(n)
	{
		dig[len++] = n%10;
		n/=10;
	}
	return dfs(len-1,0,0,1);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL n;
		scanf("%lld",&n);
		printf("%I64d\n",solve(n));
	}
	return 0;
}

