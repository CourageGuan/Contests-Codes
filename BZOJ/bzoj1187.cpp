//插头dp
//因为不要求经过所有格子，所以每次插头状态为()时更新ans
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxd = 10010;
const int HASH = 4001;

int pic[110][10],R,C;

struct HashTable
{
	int state[maxd];
	int d[maxd];
	int head[HASH],next[maxd],size;

	void clear()
	{
		size = 0;
		memset(head,-1,sizeof head);
	}

	void push(int st,int ans)
	{
		int h = st%HASH;
		for(int i=head[h];i!=-1;i=next[i])
		{
			if(st == state[i])
			{
				d[i] = max(d[i],ans);	
				return ;
			}
		}
		state[size] = st;
		d[size] = ans;
		next[size] = head[h];
		head[h] = size++;
	}
	
} h[2];	

struct State
{
	int up[10];

	int encode()
	{
		int k = 0;
		for(int i=0;i<=C;++i)
		{
			k|=up[i]<<(i*2);
		}
		return k;
	}
};

State decode(int k)
{
	State T;
	for(int i=0;i<=C;++i)
	{
		T.up[i] = k&3;
		k>>=2;
	}
	return T;
}

int solve()
{
	int ans = -INF;
	h[0].clear();
	h[0].push(0,0);
	int cur = 0;
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
		{
			cur^=1;
			h[cur].clear();
			for(int z=0;z<h[cur^1].size;++z)
			{
				int k = h[cur^1].state[z];
				int d = h[cur^1].d[z];
				if(j==0) k<<=2;
				State S = decode(k);
				int lft =S.up[j],up = S.up[j+1];
				if(lft && up)
				{
					S.up[j] = S.up[j+1] = 0;
					if(lft == up)
					{
						stack<int> st;
						if(lft == 1)
						{
							st.push(1);
							for(int t=j+2;t<=C;++t)
								if(S.up[t]==2 && st.size()==1) 
								{
									S.up[t] = 1;
									break;
								}
								else if(S.up[t] == 1) st.push(1);
								else if(S.up[t] == 2) st.pop();
						}
						else
						{
							st.push(2);
							for(int t=j-1;t>=0;--t)
								if(S.up[t]==1 && st.size()==1) 
								{
									S.up[t] = 2;
									break;
								}
								else if(S.up[t] == 2) st.push(2);
								else if(S.up[t] == 1) st.pop();
						}
						h[cur].push(S.encode(),d+pic[i][j]);
					}
					else if(lft == 2) h[cur].push(S.encode(),d+pic[i][j]);
					else if(S.encode()==0) ans = max(ans,d+pic[i][j]);
				}
				else if(lft || up)
				{
					int t = lft?lft:up;
					if((lft && i!=R-1) || (up && j!=C-1)) h[cur].push(k,d+pic[i][j]);
					if((lft && j!=C-1) || (up && i!=R-1)) h[cur].push(k^(t<<(j*2))^(t<<((j+1)*2)),d+pic[i][j]);
				}
				else
				{
				   h[cur].push(k,d);
				   if(i!=R-1 && j!=C-1) h[cur].push(k^(1<<(2*j))^(2<<(2*(j+1))),d+pic[i][j]);
				}
			}
		}
	return ans;
}

int main()
{
//	freopen("test.txt","r",stdin);
	while(scanf("%d %d",&R,&C)==2)
	{
		for(int i=0;i<R;++i)
			for(int j=0;j<C;++j)
				scanf("%d",&pic[i][j]);
		printf("%d\n",solve());
	}
	return 0;
}

