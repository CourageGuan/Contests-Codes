//插头dp求哈密顿回路数
//括号表示法
#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;
typedef long long LL;
const int HASH = 10007;
const int maxd = 100010;
int R,C,tx,ty;
int pic[15][15];

struct HashTable
{
	int state[maxd];
	LL d[maxd];
	int head[HASH],next[maxd],size;

	void clear()
	{
		size = 0;
		memset(head,-1,sizeof head);	
	}

	void push(int st,LL ans)
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

struct  State
{
	int up[13];

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

LL solve()
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
				int k = h[cur^1].state[z];
				if(j==0) k<<=2;
				LL d = h[cur^1].d[z];
				State S = decode(k);
//				for(int t=0;t<C;++t) printf("%d ",S.up[t]);
//				puts("");
				int lft = S.up[j],up = S.up[j+1];
				if(pic[i][j]) h[cur].push(k,d);
				else
				{
					if(lft && up)
					{
						S.up[j] = S.up[j+1] = 0;
						if(lft == up )
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
								else if(S.up[t]==2) st.pop();
								else if(S.up[t]==1) st.push(1);
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
									else if(S.up[t]==1) st.pop();
									else if(S.up[t]==2) st.push(2);
							}
							h[cur].push(S.encode(),d);
						}
						else if(lft == 2 || (i == tx && j == ty)) 
						{
							h[cur].push(S.encode(),d);
						}
					}
					else if(lft || up)
					{
						int t = (lft)?lft:up;
						if((t==up && j!=C-1 && !pic[i][j+1]) || (t==lft && i!=R-1 && !pic[i+1][j]) ) h[cur].push(k,d);
						if((t==up && i!=R-1 && !pic[i+1][j]) || (t==lft && j!=C-1 && !pic[i][j+1]) ) h[cur].push(k^(t<<(2*j))^(t<<(2*(j+1))),d);
					}
					else if(i!=R-1 && j!=C-1 && !pic[i+1][j] && !pic[i][j+1]) h[cur].push(k^(1<<(2*j))^(2<<(2*(j+1))),d);
				}
			}
		}
	for(int i = 0;i<h[cur].size;++i) if(!h[cur].state[i]) return h[cur].d[i];
	return 0;
}

int main()
{
//	freopen("test.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d %d",&R,&C)==2)
	{
		tx = ty = -1;
		for(int i=0;i<R;++i)
		{
			char s[15];
			scanf("%s",s);
			for(int j=0;j<C;++j){
				pic[i][j] = (s[j]=='*'); 
				if(!pic[i][j]) tx=i,ty=j;
			}
		}
		if(tx==-1)
			puts("0");
		else
			printf("%I64d\n",solve());
	}
	return 0;
}

