#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e6 + 10;
double res[maxn];
char s[maxn];

double cal(int n)
{
	double res = 0;
	for(LL i=1;i<=n;++i)
	{
		res = res + 1.0/i/i;
	}
	printf("%.5lf\n",res);
}

void init()
{
	res[0] = 0;
	for(LL i=1;i<maxn;++i)
	{
		res[i] = res[i-1] + 1.0/i/i;
	}
}

int main()
{
//	freopen("test.txt","r",stdin);
	cal(2e8);
//	init();
	LL n;
	while(scanf("%s",s) == 1)
	{
		int len = strlen(s);
		LL sum = 0;
		for(int i=0;i<len;++i)
			if(sum < maxn) sum = sum*10 + s[i]-'0';
			else break;
		if(sum > maxn)
			printf("%.5lf\n",res[maxn-1]);
		else
			printf("%.5lf\n",res[sum]);
	}
	return 0;
}
