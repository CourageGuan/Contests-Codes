#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int mod = 924844033;
const int maxn = 2010;
int N,K;
LL d[2][maxn][4],fac[maxn];

inline void add(LL& a,LL b)
{
	a += b;
	if(a >= mod) a -= mod;
}

int main()
{
	scanf("%d %d",&N,&K);
	int p = 0;
	d[p][0][0] = 1;
	F(i,1,K)
   	{
		for(int j=i;j<=N;j+=K)
		{
			p ^= 1;
			memset(d[p],0,sizeof d[0]);
			F(k,0,N) F(l,0,3)
			{
				LL& w = d[p^1][k][l]; 
				if(!w) continue;
				add(d[p][k][(l<<1)&3],w);
				if(!(l&2) && j - K > 0) 
					add(d[p][k+1][(l<<1)&3],w);
				if(j + K <= N) 
					add(d[p][k+1][((l<<1)|1)&3],w);
			}
		}
		p ^= 1;
		memset(d[p],0,sizeof d[0]);
		F(k,0,N) F(l,0,3)
		{
			if(!d[p^1][k][l]) continue;
			add(d[p][k][0],d[p^1][k][l]);
		}
	}
	fac[0] = 1;
	F(i,1,N) fac[i] = fac[i-1]*i%mod;
	LL ans = 0;
	F(i,0,N)
	{
//		printf("%lld ",d[p][i][0]);
		LL m = fac[N-i]*d[p][i][0]%mod;
	   	add(ans,(i&1)?mod - m:m);
	}
	//puts("");
	printf("%lld\n",ans);
	return 0;
}
