//数位dp
#include<cstdio>
#include<cstring>

#define abs(a) ((a)<0?(-(a)):(a))
typedef long long LL;
const int maxn = 20;
int dig[maxn];
LL d[maxn][10][2];

LL dfs(int x,int pre,int ye,int limit)
{
	if(x<0) return ye;
	LL &ans = d[x][pre][ye];
	if(!limit && ans!=-1) return ans;
	LL res = 0;
	int last = limit?dig[x]:9;
	for(int i=0;i<=last;++i)
	{
		if(abs(pre-i)<2 && ye) continue;
		res += dfs(x-1,i,ye || i!=0,limit && i==last);
	}
	if(!limit) ans = res;
	return res;
}


LL solve(LL a, LL b)
{
	int len = 0;
	--a;
	do
	{
		dig[len++]=a%10;
		a/=10;
	} while(a);
	memset(d,-1,sizeof d);
	LL l = dfs(len-1,0,0,1);
	len =  0;
	do
	{
		dig[len++]=b%10;
		b/=10;
	}while(b);
	memset(d,-1,sizeof d);
	LL r = dfs(len-1,0,0,1);
	return r-l;
}

int main()
{
	//freopen("test.txt","r",stdin);
	LL a,b;
	while(scanf("%lld %lld",&a,&b)==2) printf("%lld\n",solve(a,b));
	return 0;
}

