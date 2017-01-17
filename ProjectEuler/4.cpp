#include<bits/stdc++.h>
using namespace std;


bool yes(int t)
{
	int num[10],cnt=0;
	while(t) num[cnt++] = t%10,t/=10;
	for(int i=0;i<cnt/2;++i)
	{
		if(num[i] != num[cnt-i-1]) return false;
	}
	return true;
}

int solve()
{
	int res = 0;
	for(int i=100;i<1000;++i)
		for(int j=100;j<1000;++j)
		{
			int t = i*j;
			if(yes(t)) res = max(res,t);
		}
	return res;
}

int main()
{
	printf("%lld\n",solve());
	return 0;
}
