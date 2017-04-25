#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,N;

typedef long long LL;

#define P(x) (LL)(x)*(x)
const int maxn = 1e5 + 10;
char s[maxn];
int d[maxn],p[maxn];
int n;
LL res,ans,pre;


void init()
{
	memset(d,0,sizeof d);
	memset(p,0,sizeof p);
	d[0] = 1;
	for(int i=1;i<n;++i)
	{
		if(s[i] == s[i-1])
		{
			d[i] = d[i-1] + 1;
		}
		else d[i] = 1;
	}
	p[n-1] = 1;
	for(int i=n-2;i>=0;--i)
	{
		if(s[i] == s[i+1])
		{
			p[i] = p[i+1] + 1;
		}
		else p[i] = 1;
	}
	s[n] = '#';
	res = 0;
	for(int i=1;i<=n;++i)
	{
		if(s[i] != s[i-1])
		{
			res += P(d[i-1]+p[i-1]-1);
		}
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> T;
	for(int z=1;z<=T;++z)
	{
		scanf("%s",s);
		n = strlen(s);
		init();
		pre = ans = res;
		for(int i=0;i<n;++i)
		{
			LL c = 1;
			res -= P(d[i]+p[i]-1);
			if(s[i+1] == s[i]) res += P(p[i+1]);
			else
			{
				c += p[i+1];
				res -= P(p[i+1]);
			}
			if(i && s[i-1] == s[i]) res += P(d[i-1]);
			else
			{
				c += d[i-1];
				res -= P(d[i-1]);
			}
			res += P(c);
			ans = max(ans,res);
			res = pre;
		}
		printf("Case #%d: %I64d\n",z,ans);
	}
	return 0;
}

