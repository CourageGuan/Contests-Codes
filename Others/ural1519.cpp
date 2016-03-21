//插头dp 求哈密顿回路数
//最小表示法
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;
const int maxn = 15;
const int maxd = 100010;
const int HASH = 10007;
int pic[maxn][maxn];
int R,C,tx,ty;

struct HashTable
{
	LL state[maxd],d[maxd];
	int head[HASH],next[maxd],size;

	void clear()
	{
		size = 0;
		memset(head,-1,sizeof head);
	}

	void push(LL st,LL ans)
	{
		int h = st%HASH;
		for(int i=head[h];i!=-1;i=next[i])
			if(st == state[i])
			{
				d[i] += ans;
				return ;
			}
		state[size] = st;
		d[size] = ans;
		next[size] = head[h];
		head[h] = size++;
	}

} h[2];

int vis[13];
struct State
{
	LL up[13];

	LL encode() 	//最小表示法
	{
		memset(vis,-1,sizeof vis);
		vis[0] = 0;
		int cnt = 1;
		LL k=0;
		for(int i=0;i<=C;++i)
		{
			if(vis[up[i]]==-1) vis[up[i]]=cnt++;
			up[i] = vis[up[i]];
			k|=up[i]<<(3*i);
		}
		return k;
	}

};

State decode(LL k)
{
	State T;
	for(int i=0;i<=C;++i)
	{
		T.up[i] = k&7;
		k>>=3;
	}
	return T;
}

LL dp()
{
	h[0].clear();
	h[0].push(0,1);
	int cur = 0;
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
		{
			cur ^= 1;
			h[cur].clear();
			for(int z=0;z<h[cur^1].size;++z)
			{
				LL k = h[cur^1].state[z];
				LL d = h[cur^1].d[z];
				if(j==0) k<<=3;
				State S = decode(k);
				if(pic[i][j])
				{
					 h[cur].push(k,d); //empty
				}
				else
				{
					if(i!=0 && i!=R-1 && !pic[i+1][j] && !S.up[j] && S.up[j+1])	// |
					{
						h[cur].push(k^(S.up[j+1]<<(3*j))^(S.up[j+1]<<(3*(j+1))),d);
					}
					if(j!=0 && j!=C-1 && !pic[i][j+1] && S.up[j] && !S.up[j+1])	//——
					{
						h[cur].push(k^(S.up[j]<<(3*j))^(S.up[j]<<(3*(j+1))),d);
					}
					if(i!=R-1 && j!=C-1 && !pic[i+1][j] && !pic[i][j+1] && !S.up[j] && !S.up[j+1])	//<
					{
						State T = S;
						T.up[j] = T.up[j+1] = 8;
						h[cur].push(T.encode(),d);
					}
					if(i!=R-1 && j!=0 && !pic[i+1][j] && S.up[j] && !S.up[j+1])	//7
					{
						h[cur].push(k,d);
					}
					if(i!=0 && j!=C-1 && !pic[i][j+1] && !S.up[j] && S.up[j+1])	//L
					{
						h[cur].push(k,d);
					}
					if(i!=0 && j!=0 && S.up[j] && S.up[j+1])	//J
					{
						State T = S;
						T.up[j] = T.up[j+1] = 0;
						if(S.up[j] != S.up[j+1])
						{
							for(int t=0;t<=C;++t) if(S.up[j+1]==T.up[t]) T.up[t]=S.up[j];
							h[cur].push(T.encode(),d);
						}
						else if((i == tx) &&  (j== ty)) 
						{
							h[cur].push(T.encode(),d);
						}
					}
				}
			}
		}
	LL ans = 0;
	for(int i=0;i<h[cur].size;++i) if(!h[cur].state[i]) return h[cur].d[i];
	return ans;
}

int main()
{
	//freopen("test.txt","r",stdin);
	while(scanf("%d %d",&R,&C)==2)
	{
		tx = ty = -1;
		for(int i=0;i<R;++i)
		{
			char s[maxn];
			scanf("%s",s);	
			for(int j=0;j<C;++j)
			{
				pic[i][j] = (s[j]=='*');
				if(!pic[i][j]) tx = i,ty = j;
			}
		}
		if(tx!=-1)
			printf("%I64d\n",dp());	
		else
			puts("0");
	}
	return 0;
}

