//Trie + DP
//d[i] 表示以s[i..n]为前缀的字符串可以由集合构成的情况
//d[i] = Σ d[i+len(x)]
#include<cstdio>
#include<cstring>

const int maxnode = 4010*101;
const int sigma_size = 26;
const int maxn = 300010;
const int mod = 20071027;
int d[maxn],n;
char S[maxn];

struct Trie
{
	int sz;
	int ch[maxnode][sigma_size];
	int val[maxnode];

	void clear()
	{
		sz = 1;
		memset(ch[0],0,sizeof (ch[0]));
	}

	int idx(char c) { return c -'a'; }

	void insert(char *s)
	{
		int len = strlen(s),u = 0;
		for(int i=0;i<len;++i)
		{
			int c = idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof ch[sz]);
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u] = len;
	}

	void find_pre(char *s,int cur)
	{
		int len = strlen(s),u=0;
		for(int i=0;i<len;++i)
		{
			int c = idx(s[i]);
			u = ch[u][c];
			if(!u) break;
			if(val[u])
			{
				if(cur+val[u] > n) break;
				else d[cur] = (d[cur] + d[cur+val[u]])%mod;
			}
		}
	}


} T;



int main()
{
	//freopen("test.txt","r",stdin);
	int cnt =  0;
	while(scanf("%s",S)==1)
	{
		T.clear();
		memset(d,0,sizeof d);
		scanf("%d",&n);
		char ss[110];
		for(int i=0;i<n;++i)
		{
			scanf("%s",ss);
			T.insert(ss);
		}
//		for(int i=0;i<T.sz;++i) printf("%d %d\n",i,T.val[i]);
		n = strlen(S);
	//	printf("%d\n",n);
		d[n] = 1;
		for(int i=n-1;i>=0;--i) T.find_pre(S+i,i);
		printf("Case %d: %d\n",++cnt,d[0]);
	}
}


