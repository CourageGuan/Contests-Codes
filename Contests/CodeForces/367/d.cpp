#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=0;i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

const int maxn = 1e5 + 10;
const int bit = 30;

struct Trie{
	int nxt[30*maxn][2];
	int cnt[maxn*30],val[maxn*30];
	int sz;

	void init()
	{
		fill(nxt,-1);
		fill(val,0);
		sz = 0;
	}

	void insert(int x)
	{
		int u = 0;
		for(int i=bit;i>=0;--i)
		{
			int t = (x>>i)&1;
			if(nxt[u][t] == -1) nxt[u][t] = ++sz;
			u = nxt[u][t];
			cnt[u]++;
		}
//		printf("%d\n",u);
		val[u] = x;
	}

	void remove(int x)
	{
		int u = 0;
		for(int i=bit;i>=0;--i)
		{
			int t = (x>>i)&1;
			u = nxt[u][t];
			cnt[u]--;
		}
	}

	int query(int x)
	{
		int u = 0;
		for(int i=bit;i>=0;--i)
		{
			int t = (x>>i)&1;
			if(nxt[u][t^1] != -1 && cnt[nxt[u][t^1]]) u = nxt[u][t^1];
			else u = nxt[u][t];
			if(u == -1 || cnt[u] == 0) break;
		}
		return max(val[u]^x,x);
	}
} trie;


int main()
{
	//freopen("test.txt","r",stdin);
	int q;
	scanf("%d",&q);
	trie.init();
	while(q--)
	{
		char op[2];
		int x;
		scanf("%s %d",op,&x);
		if(op[0] == '+')
		{
			trie.insert(x);
		}
		else if(op[0] == '-')
		{
			trie.remove(x);
		}
		else
		{
			printf("%d\n",trie.query(x));
		}
	}
	return 0;
}
