#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL solve()
{
	LL res = 0;
	char s[110];
	for(int i=0;i<100;++i)
	{
		scanf("%s",s);
		LL cur = 0;
		for(int i=0;i<11;++i)
			cur = cur*10+s[i]-'0';
		res += cur;
	}
	return res/1000;
}

int main()
{
	freopen("13.txt","r",stdin);
	printf("%lld\n",solve());
	return 0;
}
