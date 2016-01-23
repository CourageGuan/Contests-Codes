#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
int a[maxn],id[maxn],res[maxn],n;
LL A,m,cf,cm,sum[maxn];

LL cal(int n)
{
	LL res = 0,rem = m;
	int  p = 0,L = 0 ,R = n-1;
	while(L <= R)
	{
		int M = (L+R)/2;
		if((LL)a[M]*M-sum[M] <= rem)
		{
			p = M;
			L = M+1;
		}
		else R = M-1;
	}
	res = (rem - (LL)a[p]*p + sum[p])/(p+1) + a[p];
//	printf("%d %d %d\n",p,n,res);
	return min(A,res);
}

int cmp(const int i,const int j) 
{
	return a[i] < a[j];
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %lld %lld %lld %lld",&n,&A,&cf,&cm,&m);
	for(int i=0;i<n;++i) scanf("%d",a+i),id[i] = i;
	sort(id,id+n,cmp);
	sort(a,a+n);
	a[n] = A;
	sum[0] = 0;
	for(int i=0;i<n;++i) sum[i+1] = sum[i] + a[i];
	LL ans = 0,up = a[0];
	int rem = n;
	for(int i=n;i>=0;--i)
	{
		if(!i)
		{
			up = A;
			break;
		}
		LL cur = cal(i);
		if(ans < cf*(n-i)+cm*cur)
		{
			ans = cf*(n-i)+cm*cur;
			up = cur;
			rem = i;
		}
		if(up == A) break;
		m -= (A - a[i-1]);
		if(m<0) break;
	}
	if(up == A)
	{
		printf("%lld\n",(LL)n*cf+A*cm);
		for(int i=0;i<n;++i) printf("%lld ",A);
	}
	else
	{
		printf("%lld\n",ans);
	//	printf("%lld %lld\n",up,rem);
		for(int i=0;i<n;++i) if(a[i] < up) a[i] = up; else break;
		for(int i=n-1;i>=rem;--i) a[i] = A;
		LL s = 0;
		for(int i=0;i<n;++i) res[id[i]] = a[i],s += a[i];
		assert(s - sum[n] > m);
		for(int i=0;i<n;++i) printf("%d ",res[i]);
	}
	return 0;
}

