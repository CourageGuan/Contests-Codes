//对抗搜索
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 100;
const int UP = 0,FLOOR = 1,DOWN = 2;
//  / up \ down _ floor
int deck[maxn],n;

struct State
{
	int card[8],type[8];
	int hold[2];
	int pos;
	int score;

	State()
	{
		for(int i=0;i<8;++i)
		{
			card[i] = deck[i];
			type[i] = i&1 ? DOWN:UP;
		}
		hold[0] = hold[1] = score = 0;
		pos = 8;
	}

	bool IsFinal()
	{
		if(pos == 2*n)
		{
			score += hold[0] + hold[1];
			hold[0] = hold[1] = 0;
			return true;
		}
		return false;
	}

	int getScore(int a,int b,int c) const
	{
		int S = abs(a) + abs(b) + abs(c);
		int cnt = 0;
		if(a>0) ++cnt;
		if(b>0) ++cnt;
		if(c>0) ++cnt;
		return cnt>=2 ? S:-S;
	}

	State son() const
	{
		State s;
		memcpy(&s,this,sizeof(s));
		s.pos = pos + 1;
		return s;
	}

	void expend(int player,vector<State>& res) const
	{
		int cur = deck[pos];

		//1. hold in hand
		if(hold[player] == 0)
		{
			State s = son();
			s.hold[player] = cur;
			res.push_back(s);
		}

		//2. new ceil
		for(int i=0;i<7;++i) if(type[i] == DOWN && type[i+1] == UP)	
		{
			//use cur;
			State s = son();
			s.score += getScore(card[i],card[i+1],cur);
			s.type[i] = s.type[i+1] = FLOOR;
			s.card[i] = s.card[i+1] = cur;
			res.push_back(s);

			if(hold[player] != 0)
			{
				//use held card;
				State s = son();
				s.score += getScore(card[i],card[i+1],hold[player]);
				s.type[i] = s.type[i+1] = FLOOR;
				s.card[i] = s.card[i+1] = hold[player];
				s.hold[player] = cur;
				res.push_back(s);
			}
		}

		//3. new peak
		if(hold[player] != 0)
		{
			for(int i=0;i<7;++i) if(type[i] == FLOOR && type[i+1] == FLOOR && card[i] == card[i+1])
			{
				State s = son();
				s.score += getScore(card[i],hold[player],cur);
				s.type[i] = UP;
				s.type[i+1] = DOWN;
				s.card[i] = cur ;
				s.card[i+1] = hold[player];
				s.hold[player] = 0;
				res.push_back(s);

				swap(s.card[i],s.card[i+1]);
				res.push_back(s);
			}
		}

	}

};

int maxmin(State& S,int player,int alpha,int beta)
{
	if(S.IsFinal()) return S.score;

	vector<State> sons;

	S.expend(player,sons);

	int n = sons.size();
	for(int i=0;i<n;++i)
	{
		int v = maxmin(sons[i],player^1,alpha,beta);
		if(!player)
			alpha = max(alpha,v);
		else
			beta = min(beta,v);
		if(beta <= alpha) break;
	}
	return !player? alpha : beta;
}

int main()
{
	//freopen("test.txt","r",stdin);
	char name[10];
	int kase = 0;
	while(scanf("%s",name)==1 && name[0]!='E')
	{
		scanf("%d",&n);
		for(int i=0;i<n*2;++i)
		{
			char ch;
			scanf("%d%c",deck+i,&ch);
			if(ch == 'B') deck[i] = -deck[i];
		}
		State start;
		int first_player = deck[0]>0? 0 : 1;
		int score = maxmin(start,first_player,-INF,INF);

		if(name[0] == 'B') score = -score;
		printf("Case %d: ",++kase);
		if(score == 0) puts("Axel and Birgit tie");
		else if(score > 0) printf("%s wins %d\n",name,score);
		else printf("%s loses %d\n",name,-score);
	}
	return 0;
}


