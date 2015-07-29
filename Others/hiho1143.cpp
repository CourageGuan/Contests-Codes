//骨牌覆盖->fib->矩阵快速幂
#include<cstdio>
#include<cstring>

typedef long long LL;
const LL mod = 19999997;
const int maxn = 3;
const int sz = 2;
typedef LL Matrix[maxn][maxn];

void mul(Matrix A,Matrix B,Matrix res) 
{
	Matrix C;
	memset(C,0,sizeof C);
	for(int i=0;i<sz;++i)
		for(int j=0;j<sz;++j)
			for(int k=0;k<sz;++k)
				C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % mod;

	/*
	for(int i=0;i<sz;++i){
		for(int j=0;j<sz;++j)
			printf("%d ",C[i][j]);
		puts("");
	}
	*/
	memcpy(res,C,sizeof C);
}

void qpow(Matrix A,LL n,Matrix res)
{
	Matrix a,r;
	memcpy(a,A,sizeof a);
	memset(r,0,sizeof r);	
	for(int i=0;i<sz;++i) r[i][i] = 1;
	while(n)
	{
		if(n&1) mul(r,a,r);
		n>>=1;
		mul(a,a,a);	
	}
	memcpy(res,r,sizeof r);
}

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		Matrix f = {{0,1},{0,0}},g = {{0,1},{1,1}};
		//qpow(g,n,g);
		qpow(g,n,g);	
		mul(f,g,f);
		printf("%lld\n",f[0][1]);
	}
	return 0;
}


