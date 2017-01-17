#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int mod = 1e9 + 7;
const int maxn = 2e6 + 10;
LL d[maxn];
int last[300],n,m,k;
char s[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&m,&k);
	scanf("%s",s+1);
	n = strlen(s+1);
	d[0] = 1;
	F(i,1,n)
	{
		d[i] = 2*d[i-1]%mod;
		if(last[s[i]])
			d[i] = (d[i] - d[last[s[i]]-1] + mod) %mod;
		last[s[i]] = i;
	}
	F(i,1,m)
	{
		int c,p = n+m+1;
		d[i+n] = 2*d[i+n-1]%mod;
		F(j,0,k-1)
			if(last['a'+j] < p)
			{
				c = 'a'+j;
				p = last['a'+j];
			}
		if(last[c])
			d[i+n] = (d[i+n] - d[last[c]-1] + mod)%mod;
		last[c] = i+n;
	}
	printf("%lld\n",d[n+m]);
	return 0;
}
