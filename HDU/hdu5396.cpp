#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)

const int mod = 1e9 + 7;
const int maxn = 110;
int n;
int a[maxn],fac[maxn];
LL d[maxn][maxn];
char s[maxn];

LL pow_mod(LL a,int n)
{
	LL res = 1;
	while(n)
	{
		if(n&1) res = res*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	//freopen("test.txt","r",stdin);
	fac[0] = 1;
	F(i,1,100) fac[i] = 1LL*i*fac[i-1]%mod;
	while(~scanf("%d",&n))
	{
		memset(d,0,sizeof d);
		R(i,n) scanf("%d",a+i),d[i][i] = a[i];
		scanf("%s",s);
		F(l,1,n-1) R(i,n)
		{
			int j = i+l;
			if(j >= n) break;
			F(k,i,j-1)
			{
				if(s[k] == '+')
					d[i][j] += d[i][k]+d[k+1][j]%mod;
				else if(s[k] == '-')
					d[i][j] += d[i][k]-d[k+1][j]%mod;
				else
					d[i][j] += d[i][k]*d[k+1][j]%mod;
				d[i][j] = (d[i][j]%mod + mod)%mod;
			}
			d[i][j] = d[i][j]*pow_mod(l,mod-2)%mod;
		}
		printf("%d\n",d[0][n-1]*fac[n-1]%mod);
	}
	return 0;
}


