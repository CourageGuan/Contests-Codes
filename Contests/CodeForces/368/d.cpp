#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1010;
bitset<maxn> b[maxn];
bitset<maxn> msk;

struct Node{
	int r,c,op;
} node[maxn*maxn];

vector<int> G[maxn*maxn];

int id[maxn*maxn];
int ans[maxn*maxn],n,m,q,tot;

void dfs(int u,int fa = 0,int cur = 0)
{
	bitset<maxn> pre;
	ans[u] = cur;
	R(i,G[u].size())
	{
		int v = G[u][i];
		if(v != fa)
		{
			int tmp = cur;
			pre = b[node[v].r];
			if(node[v].op == 3)
			{
				tmp -= b[node[v].r].count();
				b[node[v].r].flip();
				b[node[v].r] &= msk;
				tmp += b[node[v].r].count();
			}
			else if(node[v].op == 2)
			{
				tmp -= b[node[v].r].count();
				b[node[v].r].reset(node[v].c);
				tmp += b[node[v].r].count();
			}
			else
			{
				tmp -= b[node[v].r].count();
				b[node[v].r].set(node[v].c);
				tmp += b[node[v].r].count();
			}
			dfs(v,u,tmp);
			b[node[v].r] = pre;
		}
	}
}


int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&q);
	tot = 1;
	F(i,1,q)
	{
		int op,r,c;
		scanf("%d %d",&op,&r);
		switch(op) {
			case 1: 
			case 2: scanf("%d",&c),G[id[i-1]].push_back(id[i] = tot++),
					node[id[i]] = (Node){r-1,c-1,op};break;
			case 3: G[id[i-1]].push_back(id[i] = tot++),
					node[id[i]] = (Node){r-1,0,op};;break;
			case 4: id[i] = id[r];break;
		}
	}
	msk.reset();
	R(i,m) msk.set(i);
	dfs(0);
	F(i,1,q)
		printf("%d\n",ans[id[i]]);
	return 0;
}
