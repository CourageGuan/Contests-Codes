#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e6 + 10;
int n,k,a[maxn],sum[maxn];

struct Trie{
	int next[maxn*30][2];
	int val[maxn*30];
	int sz;

	void init()
	{
		memset(next,0,sizeof val);
		memset(val,0,sizeof val);
		sz = 0;
	}

	void insert(int x)
	{
		//printf("%d....\n",x);
		int j = 0;
		for(int i=30;i>=0;--i)
		{
			int t = (x>>i)&1;
			if(!next[j][t])
				next[j][t] = ++sz;
			val[next[j][t]]++;
			//printf("%d %d %d\n",sz,val[sz],t);
			j = next[j][t];
		}
	}

	int query(int x)
	{
		int j = 0,res = 0;
		for(int i=30;i>=0;--i)
		{
			int t = (x>>i)&1,p = (k>>i)&1;
			if(!p)
			{
				res += val[next[j][t^1]];
				//printf("..%d %d\n",val[next[j][t^1]],t);
				j = next[j][t]; 
			}
			else
			{
				j = next[j][t^1];
			}
			if(!j) break;
		}
		return res;
	}
} trie;

int main()
{
	//freopen("test.txt","r",stdin);
	scanf("%d %d",&n,&k);
	--k;
	sum[0] = 0;
	for(int i=1;i<=n;++i) scanf("%d",a+i),sum[i] = sum[i-1]^a[i];
	trie.init();
	LL res = 0;
	trie.insert(0);
	for(int i=1;i<=n;++i)
	{
		res += trie.query(sum[i]);
		trie.insert(sum[i]);
	}
	printf("%lld\n",res);
	return 0;
}

