#include<cstdio>
#include<cstring>

typedef long long LL;
const int maxn = (1<<20) + 10;
int n,m,SIZE;
int K[45];

struct Trie{
	int next[maxn*20][2];
	int val[maxn*20];
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
		for(int i=20;i>=0;--i)
		{
			int t = (x>>i)&1;
			if(!next[j][t])
				next[j][t] = ++sz;
			val[next[j][t]]++;
			//printf("%d %d %d\n",sz,val[sz],t);
			j = next[j][t];
		}
	}

	LL query(int x)
	{
		int j = 0;
		LL res = 0;
		for(int i=20;i>=0;--i)
		{
			int t = (x>>i)&1,p = (m>>i)&1;
			if(!p)
			{
				res += val[next[j][t^1]];
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
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		trie.init();
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;++i) scanf("%d",K+i);
		if(m == 0)
		{
			printf("Case #%d: %I64d\n",z,(1LL<<n));
			continue;
		}
		--m;
		SIZE = n/2;
		for(int i=0;i<(1<<SIZE);++i)
		{
			int t = 0;
			for(int j=0;j<SIZE;++j) if(i&(1<<j)) t ^= K[j];
			trie.insert(t);
		}
		LL ans = 0;
		for(int i=0;i<(1<<(n-SIZE));++i)
		{
			int t = 0;
			for(int j=0;j<n-SIZE;++j) if(i&(1<<j)) t ^= K[j+SIZE];
			ans += trie.query(t);
		}
		printf("Case #%d: %I64d\n",z,ans);
	}
	return 0;
}

