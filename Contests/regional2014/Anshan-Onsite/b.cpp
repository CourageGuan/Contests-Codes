#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
typedef double DB;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define R(i,n) for(int i=(0);i<(n);++i)
#define fill(a,b) memset(a,b,sizeof(a))

struct P{
	int u;
	LL cnt;
	P(int u,LL c = 0):u(u),cnt(c) {}
	P() {}
};

vector<P> que;
int n,id,top;

int find(int u)
{
	R(i,que.size())
		if(que[i].u == u)
		{
			return i;
		}
	return -1;
}

void dele(int p)
{
	if(que[p].u == top) top = -1;
	for(int i=p;i<que.size()-1;++i)
	{
		que[i] = que[i+1];
	}
	que.pop_back();
}

void movf(int p)
{
	for(int i=p;i>0;--i)
	{
		swap(que[i],que[i-1]);
	}
}

void movf()
{
	int mx = 0,p = 0;
	R(i,que.size())
	{
		if(que[i].u > mx)
		{
			mx = que[i].u;
			p = i;
		}
	}
	movf(p);
}

int main()
{
    //freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	char emp[20] = "empty.",sus[20] = "success.",
		 invp[20] = "invalid priority.",
		 samep[20] = "same priority.",
		 nsp[20] = "no such person.",
		 outr[20] = "out of range.";

	while(T--)
	{
		top = -1;
		que.clear();
		scanf("%d",&n);
		F(z,1,n)
		{
			printf("Operation #%d: ",z);
			char op[10];
			scanf("%s",op);
			if(op[0] == 'P')
			{
				if(que.empty()) puts(emp);
				else
				{
					movf();
				   	puts(sus);
				}
			}
			else if(op[0] == 'U')
			{
				if(top == -1)
				{
					puts(nsp);
				}
				else
				{
					top = -1;
					puts(sus);
				}
			}
			else
			{
				int u;
				scanf("%d",&u);
				if(op[0] == 'A')
				{
					bool flag = 1;
					R(i,que.size()) if(que[i].u == u)
					{
						flag = 0;
						break;
					}
					if(flag)
					{
						puts(sus);
						que.push_back(P(u));
					}
					else puts(samep);
				}
				else if(op[0] == 'R')
				{
					if(u > que.size() || u < 1)
					{
						puts(outr);
					}
					else
					{
						movf(u-1);
						puts(sus);
					}
				}
				else if(op[0] == 'T')
				{
					int p = find(u);
					if(p == -1)
						puts(invp);
					else
					{
						puts(sus);
						top = u;
					}
				}
				else if(op[0] == 'C')
				{
					if(op[3] == 't')
					{
						if(que.empty()) puts(emp);
						else
						{
							if(top != -1)
								que[find(top)].cnt += u;
							else
								que[0].cnt += u;
							puts(sus);
						}
					}
					else if(op[3] == 's')
					{
						int p = find(u);
						if(p == -1)
							puts(invp);
						else
						{
							printf("close %d with %lld.\n",u,que[p].cnt);
							if(que[p].cnt != 0 && que[p].u == top)
							{
								printf("Bye %d: %lld\n",que[p].u,que[p].cnt);
							}
							dele(p);
						}
					}
					else
					{
						int p = find(u);
						if(p == -1)
							puts(invp);
						else
						{
							puts(sus);
							movf(p);
						}
					}
				}
			}
		}
		int p = find(top);
		if(p != -1 && que[p].cnt != 0)
		{
			printf("Bye %d: %lld\n",que[p].u,que[p].cnt);
		}
		R(i,que.size())
		{
			if(que[i].cnt != 0 && i != p)
			{
				printf("Bye %d: %lld\n",que[i].u,que[i].cnt);
			}
		}
	}
    return 0;
}
