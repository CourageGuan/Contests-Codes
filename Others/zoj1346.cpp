//集合dp
//求满足偏序关系的拓扑排序方案(排列方案)
//d[s]表示集合s内的点已全部排序的方案数
//d[s] = Σd[s-i] i的后继不在s中(即i为集合中最后一个结点)
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cassert>

using namespace std;

const int maxn = 20;
typedef long long LL;

int G[maxn];
int vis[maxn];
LL d[1<<16];
int n,m;

map<string,int> id;

/*
bool dfs(int u)
{
	vis[u] = -1;
	for(int i=1;i<=n;++i)
	{
		if(G[u]&(1<<(i-1)))
		{
		//	printf("%d %d %d\n",u,i,vis[i]);
			if(vis[i]==-1) return false;
			if(!vis[i] && !dfs(i)) return false;
		}
	}
	vis[u] = 1;
	return true;
}
*/

void print(int x)
{
	do
	{
		putchar(x&1?'1':'0');
		x>>=1;
	}while(x);
	puts("");
}

void dp()
{
	memset(d,0,sizeof d);
	d[0] = 1;
	for(int i=0;i<(1<<n);++i)
	{
		if(!d[i]) continue;
//		printf("%d\n",d[i]);
		for(int j=1;j<=n;++j)
		{
			int t = G[j]|(1<<(j-1));
			if((t&i) == 0 )
			{
			   	d[i|(1<<(j-1))] += d[i];
			}
		}
	}
	printf("%lld\n",d[(1<<n)-1]);
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d",&m)==1)
	{
		n = 0;
		id.clear();
		memset(G,0,sizeof G);
		for(int i=0;i<m;++i)
		{
			char s1[20],s2[20];
			scanf("%s %s",s1,s2);
			if(!id[string(s1)])  id[string(s1)] = ++n;
			if(!id[string(s2)])  id[string(s2)] = ++n;
			G[id[string(s1)]] |= 1<<(id[string(s2)]-1);
		}
		bool flag = true;
//		memset(vis,0,sizeof vis);
	/*	for(int i=1;i<=n;++i)
		{
			if(!vis[i] && !dfs(i)){
				flag = false;
				puts("0");
				break;
			}
		}
		*/
		if(flag) dp();
	}
	return 0;
}
