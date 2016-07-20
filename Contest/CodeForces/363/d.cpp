#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 10;
int a[maxn],p[maxn],vis[maxn];
int n,root = 0;

void dfs(int u)
{
	if(vis[u] == -1)
	{
		if(root == 0)
			root = p[u] = u;
		else
			p[u] = root;
		vis[u] = 1;
		return;
	}
	if(vis[u]) return;
	vis[u] = -1;
	dfs(p[u]);
	vis[u] = 1;
}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		p[i] = a[i];
		if(root && i == a[i]) p[i] = root;
		if(!root && i == a[i]) root = i;
	}
//	printf("%d\n",root);
	for(int i=0;i<n;++i)
	{
		if(!vis[i])
		{
			dfs(i);
			vis[i] = 1;
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;++i) if(a[i] != p[i]) ++cnt;
	printf("%d\n",cnt);
	for(int i=1;i<=n;++i) printf("%d ",p[i]);
	return 0;
}

