#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define mp make_pair
#define fi first
#define se second

const int maxn = 1010;
int n,m;
pair<int,LL> d[maxn][maxn*7];
LL f[maxn*7],a[maxn],b[maxn],k;
map<LL,int> fac;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %lld",&n,&k);
	LL kk = k;
	F(i,1,n) scanf("%lld",a+i),b[i] = __gcd(a[i],k),kk /= __gcd(kk,b[i]);
	if(k == 1)
	{
		printf("1\n%d\n",int(min_element(a+1,a+n+1) - a));
		return 0;
	}
	if(kk != 1)
	{
		puts("-1");
		return 0;
	}
	m = 0;
	for(LL i=1;i*i<=k;++i)
	{
		if(k%i) continue;
		f[m++] = i;
		if(i*i != k) f[m++] = k/i;
	}
	sort(f,f+m);
	fac.clear();
	F(i,0,m-1)
	{
	   	fac[f[i]] = i;
		d[0][i] = mp(n+1,0);
	}
	d[0][0] = mp(0,0);

	F(i,1,n)
		F(j,0,m-1)
		{
			d[i][j] = d[i-1][j];
			LL v = fac[f[j]/__gcd(f[j],b[i])];
			if(d[i][j] > mp(d[i-1][v].fi+1,d[i-1][v].se + a[i]))
				d[i][j] = mp(d[i-1][v].fi+1,d[i-1][v].se + a[i]);
		}

	printf("%d\n",d[n][m-1].fi);
	for(int i=n;i>0;--i)
	{
		if(d[i][fac[k]] == d[i-1][fac[k]]) continue;
		printf("%d ",i);
		k /= __gcd(k,b[i]);
	}
	return 0;
}
