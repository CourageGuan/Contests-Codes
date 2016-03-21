//插头dp
//这是刘汝佳的写法
//记忆化搜索，三进制
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int G[10][10];
int d[9][9][59049];
int R,C;

struct State
{
	int left;
	int up[9];

	int encode() const
	{
		int k = left;
		for(int i=0;i<C;++i) k = k*3 + up[i];
		return k;
	}

	bool next(int r,int c,int UP,int DOWN,int LEFT,int RIGHT,State &T)
	{
		if( (r == R-1 && DOWN!=0) || (c == C-1 && RIGHT!=0)) return false;
		int must_left = (c>0 && left);
		int must_up = (r>0 && up[c]);

		if((must_left && LEFT!=left) || (!must_left && LEFT)) return false;
		if((must_up && UP!=up[c]) || (!must_up && UP)) return false;
		if(must_up && must_left && left!=up[c]) return false;

		for(int i=0;i<C;++i) T.up[i] = up[i];
		T.left = RIGHT;
		T.up[c] = DOWN;
		return true;
	}

};

int dp(int r,int c,State& S)
{
	if(c>=C) ++r,c=0;
	if(r>=R) return 0;
	int& res = d[r][c][S.encode()];
	if(res>=0) return res;
	res = INF;

	State T;

	if(G[r][c]<=1)
	{
		if(S.next(r,c,0,0,0,0,T)) res = min(res,dp(r,c+1,T));
		if(!G[r][c])
		{
			for(int t=1;t<=2;++t)
			{
				if(S.next(r,c,t,t,0,0,T)) res = min(res,dp(r,c+1,T)+1);
				if(S.next(r,c,t,0,t,0,T)) res = min(res,dp(r,c+1,T)+1);
				if(S.next(r,c,t,0,0,t,T)) res = min(res,dp(r,c+1,T)+1);
				if(S.next(r,c,0,t,t,0,T)) res = min(res,dp(r,c+1,T)+1);
				if(S.next(r,c,0,t,0,t,T)) res = min(res,dp(r,c+1,T)+1);
				if(S.next(r,c,0,0,t,t,T)) res = min(res,dp(r,c+1,T)+1);
			}
		}
	}
	else
	{
		int t = G[r][c] - 1;
		if(S.next(r,c,t,0,0,0,T)) res = min(res,dp(r,c+1,T));
		if(S.next(r,c,0,t,0,0,T)) res = min(res,dp(r,c+1,T));
		if(S.next(r,c,0,0,t,0,T)) res = min(res,dp(r,c+1,T));
		if(S.next(r,c,0,0,0,t,T)) res = min(res,dp(r,c+1,T));
	}
	return res;
}


int main()
{
//	freopen("test.txt","r",stdin);
	while(scanf("%d %d",&R,&C)==2 && R && C)
	{
		for(int r=0;r<R;++r)
			for(int c=0;c<C;++c)
				scanf("%d",&G[r][c]);

		State s;
		memset(&s,0,sizeof(s));
		memset(d,-1,sizeof (d));
		int ans = dp(0,0,s);
		if(ans==INF) puts("0");
		else printf("%d\n",ans+2);
	}
	return 0;
}

