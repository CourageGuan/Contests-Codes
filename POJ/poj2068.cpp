#include<cstdio>
#include<cstring>

const int maxn = 1 << 14;
int d[maxn][30],m[30];
int n;

void dfs(int k,int t)
{
	if(d[k][t] != -1) return;
	if(k == 0)
	{
		d[k][t] = 1;
		return;
	}
	d[k][t] = 0;
	for(int i=1;i<=m[t];++i)
	{
		if(i > k) break;
		dfs(k - i,(t+1)%(2*n));
		if(!d[k-i][(t+1)%(2*n)]) d[k][t] = 1;
	}
//	printf("%d %d %d\n",k,t,d[k][t]);
}

int main()
{
//	freopen("test.txt","r",stdin);
	while(scanf("%d",&n) == 1 && n)
	{
		int k;
		scanf("%d",&k);
		for(int i=0;i<2*n;++i) scanf("%d",m+i);
		memset(d,-1,sizeof d);
		dfs(k,0);
		puts(d[k][0]?"1":"0");
	}
	return 0;
}
