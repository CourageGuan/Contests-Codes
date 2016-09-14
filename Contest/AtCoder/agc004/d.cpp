#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof a);

const int maxn = 1e5 + 10;
int n,k,ans,a[maxn];
vector<int> G[maxn];

int dfs(int u)
{
	int cur = 1;
	R(i,G[u].size())
	{
		int v = G[u][i];
		cur = max(cur,dfs(v)+1);
	}
	if(cur == k && a[u] != 1)
	{
	//	printf("%d %d\n",u,cur);
		cur = 0;
		++ans;
	}
	return cur;
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&k);
	ans = 0;
	scanf("%d",a+1);
	if(a[1] != 1) ++ans;
	a[1] = 1;
	F(i,2,n)
	{
		scanf("%d",a+i);
		G[a[i]].push_back(i);
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
