#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1e6;
int d[maxn];

int dfs(LL u)
{
	if(u == 1) return 0;
	if(u < maxn && d[u]) return d[u];
	if(u < maxn) return d[u] = dfs(u&1?(3*u+1):u/2)+1;
	else return  dfs(u&1?(3*u+1):u/2)+1;
}

int solve()
{
	int res,cur = 0;
	for(int i=2;i<maxn;++i)
	{
		int t = dfs(i);
		if(t > cur)
		{
			cur = t;
			res = i;
		}
	}
	return res;
}

int main()
{
	printf("%d\n",solve());
	return 0;
}
