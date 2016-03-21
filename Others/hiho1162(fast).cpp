#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = (1<<10);
typedef long long LL;
typedef LL Matrix[maxn][maxn];

struct mat
{
	int i,j;
	LL v;
	mat(int i,int j,LL v):i(i),j(j),v(v) {}
};
vector<mat> a,b;
int hq[maxn];

const LL mod = 12357;
Matrix g;
int sz;
LL n,m;

Matrix C;
void mul(Matrix A,Matrix B,Matrix res)
{
	a.clear();
	b.clear();



	memset(C,0,sizeof C);
	memset(hq,-1,sizeof hq);

	for(int i=0;i<sz;++i)
		for(int j=0;j<sz;++j)
		{
			if(A[i][j]) a.push_back(mat(i,j,A[i][j]));
			if(B[i][j])
			{
				if(hq[i]==-1) hq[i] = b.size();
			   	b.push_back(mat(i,j,B[i][j]));
			}
		}
//	for(int i=0;i<b.size();++i) printf("%d %d %d\n",b[i].i,b[i].j,b[i].v);
//	for(int i=0;i<sz;++i) printf("%d\n",hq[i]);

	for(int i=0;i<a.size();++i)
	{
		if(hq[a[i].j]==-1) continue;
		for(int j=hq[a[i].j]; j<b.size();++j)
		{
			if(b[j].i!=a[i].j) break;
			C[a[i].i][b[j].j] = (C[a[i].i][b[j].j] + a[i].v*b[j].v) % mod;
		}
	}

	memcpy(res,C,sizeof(C));
}
Matrix t,r;

void qpow(Matrix A,LL n,Matrix res)
{

	memset(r,0,sizeof (r));
	memcpy(t,A,sizeof (t));
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
		if(n&1) mul(r,t,r);
		n>>=1;
		mul(t,t,t);
	}
	memcpy(res,r,sizeof (r));
}

void dfs(int k,int s1,int s2)
{
	if(k>m)
	{
		g[s1][s2] = 1;
		return ;
	}
	dfs(k+1,s1<<1|1,s2<<1);
	dfs(k+1,s1<<1,s2<<1|1);
	if(k<=m-1) dfs(k+2,s1<<2|3,s2<<2|3);
}

int main()
{
	//freopen("test.txt","r",stdin);
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
/*		for(int i=0;i<sz;++i)
		{
			for(int j=0;j<sz;++j)
				printf("%d ",g[i][j]);
			puts("");
		}
*/

		printf("%lld\n",g[sz-1][sz-1]);
	}
	return 0;
}

