//骨牌覆盖终极版
//根据状态建图 -> 答案为 G^n[2^m-1][2^m-1]
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = (1<<11);
typedef long long LL;
typedef LL Matrix[maxn][maxn];

const LL mod = 12357;
Matrix g;
int sz;
LL n,m;
Matrix C;

void mul(Matrix A,Matrix B,Matrix res)
{

	memset(C,0,sizeof C);
	for(int i=0;i<sz;++i)
		for(int j=0;j<sz;++j)
		{
			if(A[i][j]==0) continue;
			for(int k=0;k<sz;++k)
				C[i][k] = (C[i][k] + A[i][j]*B[j][k]) % mod;
		}
	memcpy(res,C,sizeof(C));
}
Matrix a,r;
void qpow(Matrix A,LL n,Matrix res)
{

	memset(r,0,sizeof (r));
	memcpy(a,A,sizeof (a));
	for(int i=0;i<sz;++i) r[i][i] = 1;
	/*
	for(int i=0;i<sz;++i)
	{
		for(int j=0;j<sz;++j)
			printf("%d ",r[i][j]);
		puts("");
	}
	*/
	while(n)
	{
		if(n&1) mul(r,a,r);
		n>>=1;
		mul(a,a,a);
	}
	memcpy(res,r,sizeof (r));
}

void dfs(int k,int s1,int s2)
{
	if(k>m)
	{
		g[s1][s2]=g[s2][s1] = 1;
		return ;
	}
	dfs(k+1,s1<<1|1,s2<<1);
	dfs(k+1,s1<<1,s2<<1|1);
	if(k<=m-1) dfs(k+2,s1<<2|3,s2<<2|3);
}

int main()
{
    freopen("test.txt","r",stdin);
	while(scanf("%lld %lld",&m,&n)==2)
	{
		if((n&1) && (m&1))
		{
			puts("0");
			continue;
		}
		if(n<m) swap(n,m);
		sz = (1<<m);
		memset(g,0,sizeof g);

		dfs(1,0,0);

		qpow(g,n,g);

		printf("%lld\n",g[sz-1][sz-1]);
	}
	return 0;
}


