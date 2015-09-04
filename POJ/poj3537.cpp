//sg搜索
#include<cstdio>
#include<cstring>

const int maxn = 2010;
int sg[maxn];

int dfs(int n)
{
	if(n<=0) return 0;
	int &ans = sg[n];
	if(ans!=-1) return ans;

	bool vis[maxn];
	memset(vis,0,sizeof vis);

	for(int i=1;i<=n/2 + 1;++i)
	{
		vis[dfs(i-3)^dfs(n-i-2)] = 1;
	}
	for(int j=0;;++j)
		if(!vis[j]) return sg[n] = j;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n;
	memset(sg,-1,sizeof sg);
	while(scanf("%d",&n)==1)
	{
		puts(dfs(n)?"1":"2");
	}
	return 0;
}
