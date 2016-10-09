#include<bits/stdc++.h>

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 1010;
int n;
int pref[maxn][maxn],rank[maxn][maxn],next[maxn];
int has_man[maxn],has_woman[maxn];
std::queue<int> q;

int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		while(q.size()) q.pop();
		F(i,1,n)
		{
		   	F(j,1,n) scanf("%d",&pref[i][j]);
			q.push(i);
			next[i] = 1;
		}
		F(i,1,n)
		{
			int x;
		   	F(j,1,n) scanf("%d",&x),rank[i][x] = j;
		}
		memset(has_man,0,sizeof has_man);
		memset(has_woman,0,sizeof has_woman);
		while(q.size())
		{
			int man = q.front(); q.pop();
			int woman = pref[man][next[man]++];
			if(!has_man[woman])
			{
				has_man[woman] = man;
				has_woman[man] = woman;
			}
			else if(rank[woman][has_man[woman]] > rank[woman][man])
			{
				has_woman[has_man[woman]] = 0;
				q.push(has_man[woman]);
				has_woman[man] = woman;
				has_man[woman] = man;
			}
			else q.push(man);
		}
		F(i,1,n) printf("%d\n",has_woman[i]);
		if(T) puts("");
	}
	return 0;
}
