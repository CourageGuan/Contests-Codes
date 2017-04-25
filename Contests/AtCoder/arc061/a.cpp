#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

char s[22];
LL p[22];
int n;
LL ans;

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%s",s);
	n = strlen(s);
	ans = 0;
	p[0] = p[1] = 1;
	F(i,2,21) p[i] = p[i-1]*2;
	F(l,0,n-1)
		F(i,0,n-l-1)
		{
			int j = i + l;
			LL cur = 0;
			for(int k=i;k<=j;++k) cur = cur*10 + s[k] - '0';
			ans += cur * p[i]*p[n-j-1];
		//	printf("%lld %lld %lld\n",cur,p[i],p[n-j-1]);
		}
	printf("%lld\n",ans);
	return 0;
}
