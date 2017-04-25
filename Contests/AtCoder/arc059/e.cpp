#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 410;
const int mod = 1e9 + 7;

int n,c;
int a[maxn],b[maxn];
LL P[maxn][maxn],A[maxn][maxn];
LL d[2][maxn];

void init()
{
	F(i,1,400)
	{
		P[i][0] = 1;
		F(j,1,400)
			P[i][j] = P[i][j-1]*i %mod; 
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	init();

	scanf("%d %d",&n,&c);	
	F(i,1,n) scanf("%d",a+i);
	F(i,1,n) scanf("%d",b+i);

	F(i,1,n)
	{
		F(k,0,c)
		{
			A[i][k] = 0;
			F(j,a[i],b[i])
			{
				A[i][k] = (A[i][k] + P[j][k])%mod;
			}
		}
//		printf("%d\n",A[i][1]);
	}


	int p = 1;
	d[p][0] = 1;
	F(i,1,n)
	{
		p ^= 1;
		fill(d[p],0);
		F(j,0,c)
		{
			F(k,0,c)
			{
				if(k+j > c) break;
				d[p][k+j] = (d[p][k+j] + d[p^1][j]*A[i][k] %mod) %mod;
			}
		}
	}
	printf("%lld\n",d[p][c]);
//	printf("%d\n",pow_m(a[1],c)*C[n+c-1][c]%mod);
	return 0;
}
