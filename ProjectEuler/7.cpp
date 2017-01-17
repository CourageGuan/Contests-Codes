#include<bits/stdc++.h>
using namespace std;

int n = 10001;
const int maxn = 1e6;
bool vis[maxn];

int solve()
{
	--n;
	for(int i=3;i<maxn;i+=2)
	{
		if(!vis[i])
		{
			--n;
			if(!n) return i;
			for(int j=i+i;j<maxn;j+=i) vis[j] = 1;
		}
	}
	return -1;
}

int main()
{
	printf("%d\n",solve());
	return 0;
}
