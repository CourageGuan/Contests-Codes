#include<bits/stdc++.h>

const int maxn = 5e5 + 10;
const int csize = 26;

struct Aho{
	struct S{
		int next[csize];
		int fail,cnt;
	} st[maxn];

	int size;
	std::queue<int> que;

	void init()
	{
		while(que.size()) que.pop();
		for(int i=0;i<maxn;++i)
		{
			memset(st[i].next,0,sizeof(st[i].next));
			st[i].fail = st[i].cnt = 0;
		}
		size = 1;
	}

	inline int idx(char c)
	{
		return c - 'a';
	}

	void insert(char *s)
	{
		int n = strlen(s);
		int cur = 0;
		for(int i=0;i<n;++i)
		{
			char c = s[i];
			if(!st[cur].next[idx(c)])
				st[cur].next[idx(c)] = size++;
			cur = st[cur].next[idx(c)];
		}
		st[cur].cnt++;
	}

	void build()
	{
		st[0].fail = -1;
		que.push(0);

		while(que.size())
		{
			int u = que.front();  que.pop();
			for(int i=0;i<csize;++i)
				if(st[u].next[i])
				{
					int v = st[u].fail;
					while(v != -1)
						if(st[v].next[i])
						{
							st[st[u].next[i]].fail = st[v].next[i];
							break;
						}
						else v = st[v].fail;
					if(v == -1) st[st[u].next[i]].fail = 0;
					que.push(st[u].next[i]);
				}
		}
	}

	int get(int u)
	{
		int res = 0;
		while(u)
		{
			res += st[u].cnt;
			st[u].cnt = 0;
			u = st[u].fail;
		}
		return res;
	}

	int find(char *s)
	{
		int n = strlen(s);
		int res = 0,cur = 0;
		for(int i=0;i<n;++i)
		{
			char c = s[i];
			if(st[cur].next[idx(c)])
				cur = st[cur].next[idx(c)];
			else
			{
				int p = st[cur].fail;
				while(p != -1 && !st[p].next[idx(c)]) p = st[p].fail;
				if(p == -1) cur = 0;
				else cur = st[p].next[idx(c)];
			}
			if(st[cur].cnt)
				res += get(cur);
		}
		return res;
	}
} aho;

int n;
char s[2*maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		aho.init();
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%s",s);
			aho.insert(s);
		}
		aho.build();
		scanf("%s",s);
		int res = aho.find(s);
		printf("%d\n",res);
	}
	return 0;
}
