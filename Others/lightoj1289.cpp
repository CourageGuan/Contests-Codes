//lcm(1..n) n <= 10^8
//线性筛，位图标记　预处理出素数的前缀积
//枚举幂次，二分求次此幂次可以到达的最大素数(满足<=n)
//答案乘上这个前缀。
//由于要求模2^32，用unsigned int 自然溢出会快一些。
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

typedef unsigned int UI;
typedef long long LL;

const int maxn = 1e8 + 2;

UI vis[(maxn+31)/32 + 5];
UI sum[5770000];
int pri[5770000];
int n,tot;

void init()
{
	tot = 0;
	memset(vis,0,sizeof vis);
	for(int i=2;i<maxn;++i)
	{
		if(!(vis[i/32]&(1<<(i%32)))) pri[tot++] = i;
		for(int j=0;j<tot;++j)
		{
			 LL t = (LL)i*pri[j];
			 if(t > maxn) break;
			 vis[t/32] |= (1<<(t%32));
			 if(i % pri[j] == 0) break;
		}
	}
	sum[0] = pri[0];
	for(int i=1;i<tot;++i)
	{
		sum[i] = sum[i-1]*pri[i];
	}
}

inline bool ok(int m,int t)
{
	LL cur = 1;
	for(int i=1;i<=t;++i)
	{
		cur *= pri[m];
		if(cur > n) return false;
	}
	return true;
}

inline int judge(int t)
{
	int l = 0, r = tot-1,m,res = -1 ;
	while(l <= r)
	{
		m = (l+r)>>1;
		if(ok(m,t))
		{
			res = m;
		   	l = m+1;
		}
		else
		{
		   	r = m-1;
		}
	}
	return res;
}


UI solve()
{
	UI ans=1;
	for(int i=1;;++i)
	{
		int now = judge(i);
		if(now == -1) break;
		ans *= sum[now];	
	}
	return ans;
}

int main()
{
	int T;
	init();
	//freopen("test.txt","r",stdin);
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		printf("Case %d: %u\n",z,solve());
	}
	return 0;
}

