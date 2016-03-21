//插头dp
//自己的写法，几乎纯位运算
//用HashTable储存状态
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;


const int INF = 0x3f3f3f3f;
const int HASH = 10007;
const int maxd = 60000;
int pic[10][10];
int n,m;

struct HashTable
{
	int state[maxd],d[maxd];
	int head[HASH],next[maxd],size;

	void clear()
	{
		size = 0;
		memset(head,-1,sizeof head);
	}

	void push(int st,int res)
	{
		int h = st%HASH;
		for(int i=head[h];i!=-1;i=next[i])
		{
			if(st==state[i])
			{
				if(d[i]>res) d[i] = res;
				return ;
			}
		}
		state[size] = st;
		d[size] = res;
		next[size] = head[h];
		head[h] = size++;
	}

} h[2];

int main()
{
//	freopen("test.txt","r",stdin);
	while(scanf("%d %d",&n,&m)==2 && n && m)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&pic[i][j]);
		h[0].clear();
		h[0].push(0,0);
		int cur = 0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				cur^=1;
				h[cur].clear();
				for(int z=0; z<h[cur^1].size; ++z)
				{
					int k = h[cur^1].state[z];
					if(pic[i][j]<=1)
					{
						if(!(k&3) && !(k>>(m*2)))  h[cur].push(k<<2,h[cur^1].d[z]); //空
						if(!pic[i][j])
						{
							if(i!=0 && i!=n-1 && !(k&3) && (k>>(m*2)))	// |
							{
								int st = (k<<2)^((k>>(m*2))<<((m+1)*2))^((k>>(m*2))<<2);
								h[cur].push(st,h[cur^1].d[z]+1);
							}
							if(j!=0 && j!=m-1 && (k&3) && !(k>>(m*2)))	// ——
							{
								int st = (k<<2)^((k&3)<<2)^(k&3);
								h[cur].push(st,h[cur^1].d[z]+1);
							}
							if(i!=n-1 && j!=m-1 && !(k&3) && !(k>>(m*2)))	//┌ 
							{
								int st1 = (k<<2)^(1<<2)^1,st2 = (k<<2)^(2<<2)^2;
								h[cur].push(st1,h[cur^1].d[z]+1);
								h[cur].push(st2,h[cur^1].d[z]+1);
							}
							if(i!=n-1 && j!=0  && (k&3) && !(k>>(m*2)))	//┐ 
							{
								int st = k<<2;
								h[cur].push(st,h[cur^1].d[z]+1);
							}
							if(i!=0 && j!=m-1  && !(k&3) && (k>>(m*2)))	//└ 
							{
								int st = (k<<2)^((k>>(m*2))<<((m+1)*2))^(k>>(m*2));
								h[cur].push(st,h[cur^1].d[z]+1);
							}
							if(i!=0 && j!=0 && (k&3) && (k&3) == (k>>(m*2)))	//┘
							{
								int st = (k<<2)^((k&3)<<2)^((k&3)<<((m+1)*2));
								h[cur].push(st,h[cur^1].d[z]+1);
							}
						}
					}
					else
					{
						if(i!=0  && !(k&3) && ((k>>(m*2))==pic[i][j]-1))	//┯
						{
							int st = (k<<2)^((k>>(m*2))<<((m+1)*2));
							h[cur].push(st,h[cur^1].d[z]);
						}
						if(i!=n-1 && !(k&3) && !(k>>(m*2)))	//┷
						{
							int st = (k<<2)^((pic[i][j]-1)<<2);
							h[cur].push(st,h[cur^1].d[z]);
						}
						if(j!=0  && ((k&3)==pic[i][j]-1) && !(k>>(m*2)))	//┠
						{
							int st = (k<<2)^((k&3)<<2);
							h[cur].push(st,h[cur^1].d[z]);
						}
						if(j!=m-1 && !(k&3) && !(k>>(m*2)))	//┨
						{
							int st = (k<<2)^(pic[i][j]-1);
							h[cur].push(st,h[cur^1].d[z]);
						}
					}
				}
			}
		int ans = INF;
		for(int i=0;i<h[cur].size;++i) if(!h[cur].state[i]) ans = min(ans,h[cur].d[i]);
		if(ans<INF) printf("%d\n",ans+2);
		else puts("0");
	}
	return 0;
}

