#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define P(x) ((x)*(x))

const int maxn = 5e5 + 10;

LL d[maxn],sum[maxn];
int c[maxn],q[maxn],l,r;
int n,m;

LL up(int k,int j)
{
	return d[j] + P(sum[j]) - d[k] - P(sum[k]);
}

LL down(int k,int j)
{
	return 2*(sum[j] - sum[k]);
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(~scanf("%d %d",&n,&m))
	{
		sum[0] = 0;
		F(i,1,n) scanf("%d",c+i),sum[i] = sum[i-1] + c[i];
		l = r = 0;
		q[r++] = d[0] = 0;
		F(i,1,n)
		{
			while(l+1 < r && up(q[l],q[l+1]) < sum[i]*down(q[l],q[l+1])) ++l;
			d[i] = d[q[l]] + P(sum[i] - sum[q[l]]) + m;
			while(l+1 < r && up(q[r-2],q[r-1])*down(q[r-1],i) >= up(q[r-1],i)*down(q[r-2],q[r-1])) --r;
			q[r++] = i;
		}
		printf("%I64d\n",d[n]);
	}
	return 0;
}
