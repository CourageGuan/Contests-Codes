#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef int LL;

const int sz = 2;
const int maxn = 46337;

LL res[maxn+1010];
LL len[5010];


LL qpow(LL a,LL n,LL mod)
{
	if(n==0) return 1;
	LL x = qpow(a,n/2,mod) % mod;
	LL res = (long long)x*x %mod;
	if(n&1) res = (long long)res*a %mod;
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		LL x,m;
		scanf("%lld %lld\n",&x,&m);
		
		LL t1 = 1%m, t2 = 9%m;
		res[0] = t1;
		res[1] = t2;
		LL j = 2;
		for(;;++j)
		{
			res[j] = ((10*res[j-1] - res[j-2] + 8)%m + m) %m;
			if(res[j-1] == t1 && res[j]==t2) break;
		}
		j-=1;
	//	printf("%lld\n",(1+qpow(2,x,j)) % j);
		LL ans = res[(1+qpow(2,x,j)) % j];
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}


