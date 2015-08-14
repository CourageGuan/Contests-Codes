//数位dp
//用位表示最长上升子序列
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;
const int maxn = 22;
LL d[maxn][1<<10][12];
int dig[maxn],K;

inline int get(int x)
{
	int cnt = 0;
	for(int i=0;i<10;++i) if((1<<i)&x) ++cnt;
	return cnt;
}

inline int judge(int st,int i)
{
	if((1<<i) & st) return st;
	if((1<<i) > st) return st|(1<<i);
	st |= 1<<i;
	for(int j=i+1;j<10;++j) if((1<<j) & st) return st^(1<<j);
}

LL dfs(int x,int st,int limit)
{
	if(x<0)  return get(st)==K; 
	LL &ans = d[x][st][K];
	if(!limit && ans != -1) return ans;
	int last = limit?dig[x]:9;
	LL res = 0;
	for(int i=0;i<=last;++i) res+=dfs(x-1,st || i ?judge(st,i):0,limit && (i==last));
	if(!limit) ans = res;
	return res;
}

inline LL solve(LL n)
{
	int len = 0;
	while(n)
	{
		dig[len++] = n%10;
		n /= 10;
	}
	return dfs(len-1,0,1);
}

int main()
{
//	freopen("test.txt","r",stdin);
	memset(d,-1,sizeof d);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		LL L,R;
		scanf("%lld %lld %d",&L,&R,&K);
		printf("Case #%d: %I64d\n",z,solve(R)-solve(L-1));
	}
	return 0;
}

