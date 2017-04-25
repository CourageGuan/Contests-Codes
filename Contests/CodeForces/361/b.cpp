#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int res[maxn],a[maxn];
int n;

void dfs(int i,int k)
{
	if(res[i] <= k || i < 0 || i >= n) return;
	res[i] = k;
	dfs(a[i]-1,k+1);
	dfs(i+1,k+1);
	dfs(i-1,k+1);
}

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d",&n);
	memset(res,INF,sizeof res);
	for(int i=0;i<n;++i)
		scanf("%d",a+i);
	dfs(0,0);
	for(int i=0;i<n;++i)
	{
		printf("%d ",res[i]);
	}
	return 0;
}
