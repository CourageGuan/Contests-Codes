#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 5e5;
const int base = maxn/2;
const int mod = 1e9 + 7;

LL d[2][maxn];
LL sum[maxn];
int inc[maxn];
int a,b,k,t,down,up;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d %d",&a,&b,&k,&t);
	d[0][a-b+base] = 1;
	F(i,-k,k)
		F(j,-k,k)
			inc[i-j+base]++;
	down = up = a - b;
	F(i,1,t)
	{
		memset(d[1],0,sizeof d[1]);
		down -= 2*k, up += 2*k;
		int L = down ,R = up;
		memset(sum,0,sizeof sum);
		F(j,L-2*k,R+2*k) sum[j+base] = (sum[j-1+base] + d[0][j+base]) %mod;
		F(j,-2*k,2*k)
			d[1][L+base] = (d[1][L+base] + inc[j+base]*d[0][L+j+base]%mod) %mod;
		F(l,L+1,R)
		{
			d[1][l+base] = ((d[1][l-1+base] - (sum[l-1+base] - sum[l-1-2*k-1+base]) + (sum[l+2*k+base] - sum[l-1+base]))%mod + mod)%mod;
		}
		memcpy(d[0],d[1],sizeof d[1]);
	}
	LL ans = 0;
	F(i,1,up)
	{
	   	ans = (ans + d[0][i+base])%mod;
//		if(d[0][i+base]) printf("%d %lld\n",i,d[0][i+base]);
	}
	printf("%lld\n",ans);
	return 0;
}
