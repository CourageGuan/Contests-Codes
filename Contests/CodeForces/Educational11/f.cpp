#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const double eps = 1e-8;
const int maxn = 2e5 + 10;
int n,a[maxn],q[maxn],t;
LL sum[maxn],mul[maxn];

inline LL up(int k,int j)
{
	return j*sum[j]-mul[j] - (k*sum[k] - mul[k]);
}

inline LL down(int k,int j)
{
	return j - k;
}


int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i),sum[i] = sum[i-1] + a[i],mul[i] = mul[i-1] + 1LL*i*a[i];
	t = 0;
	LL ans = 0;
	F(i,1,n)
	{
		int l = 0,r = t-1,j = q[t];
		while(l <= r)
		{
			int m = l+r>>1;
			if(up(q[m],q[m+1]) <= sum[i]*down(q[m],q[m+1])) j = q[m],r = m - 1;
			else l = m + 1;
		}
		ans = max(ans,mul[i] - mul[j] - j*(sum[i] - sum[j]));
		//printf("%d %d %d\n",i,j,t);
		while(t>=1 && up(q[t-1],q[t])*down(q[t],i) <= up(q[t],i)*down(q[t-1],q[t])) --t;
		q[++t] = i;
	}
	printf("%lld\n",ans);
	return 0;
}
