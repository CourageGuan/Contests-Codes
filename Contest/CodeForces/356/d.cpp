#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 5;
LL p[maxn];
pair<int,LL> ans;

void dfs(LL m,int fi,LL se)
{
	if(m == 0)
	{
		ans = max(ans,make_pair(fi,se));
		return ;
	}

	int x = lower_bound(p,p+maxn,m) - p;
	if(p[x] > m) --x;

//	printf("%lld %d\n",m,p[x]);

	dfs(m-p[x],fi+1,se+p[x]);
	if(x-1 >= 0)
		dfs(p[x]-1-p[x-1],fi+1,se+p[x-1]);
}

int main()
{
	//freopen("test.txt","r",stdin);
	for(int i=1;i<maxn;++i) p[i] = (LL)i*i*i;
	LL m;
	scanf("%lld",&m);
	dfs(m,0,0);
	printf("%d %lld\n",ans.first,ans.second);
	return 0;
}
