//1*r 骨牌 铺满 m*n方格的方案数
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

inline const int qpow(int a,int n)
{
	int res=1;
	while(n)
	{
		if(n&1) res*=a;
		n>>=1;
		a*=a;
	}
	return res;
}

int r;	//进制
int d[2][10000000];
int t,n,m;

void dfs(int p,int s1,int s2)
{
	if(p>m)
	{
		d[t][s1] += d[t^1][s2];	
		return ;
	}
	for(int i=0;i<r;++i)
	{
		dfs(p+1,s1*r+i,s2*r+(i+1)%r);	
	}
	if(p<=m-r+1) dfs(p+r,s1*qpow(r,r)+qpow(r,r)-1,s2*qpow(r,r)+qpow(r,r)-1);
}

int main()
{
	while(scanf("%d %d %d",&n,&m,&r)==3)
	{
		if((n*m)%r) puts("0");
		else
		{
			if(m>n) swap(n,m);
			memset(d,0,sizeof d);
			d[0][qpow(r,m)-1] = 1;
			for(int i=1;i<=n;++i)
			{
				t=i&1;
				dfs(1,0,0);	
				memset(d[t^1],0,sizeof d[t^1]);
			}
			printf("%d\n",d[n&1][qpow(r,m)-1]);
		}
	}
	return 0;
}

