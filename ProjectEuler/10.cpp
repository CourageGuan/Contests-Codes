#include<bits/stdc++.h>
using namespace std;

typedef long long  LL;

const int maxn = 2e6;
bool vis[maxn];

LL solve()
{
	LL res = 0;
	res += 2;
	for(int i=3;i<maxn;i+=2)
	{
		if(!vis[i])
		{
			res += i;
			for(int j=i+i;j<maxn;j+=i) vis[j] = 1;
		}
	}
	return res;
}

int main()
{
	printf("%lld\n",solve());
	return 0;
}
