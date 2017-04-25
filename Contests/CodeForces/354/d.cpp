#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int INF = 0x3f3f3f3f;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};


char s[4][maxn][maxn];
int d[4][maxn][maxn];
int xt, yt, xm, ym,m,n;

bool check(int x,int y)
{
	return x < n && x >= 0 && y < m && y >= 0;
}

char turn(char c)
{
	switch(c)
	{
		case  '*':return '*';break;
		case  '+':return '+';break;
		case  '-':return '|';break;
		case  '|':return '-';break;
		case  '^':return '>';break;
		case  '>':return 'v';break;
		case  'v':return '<';break;
		case  '<':return '^';break;
		case  'L':return 'U';break;
		case  'U':return 'R';break;
		case  'R':return 'D';break;
		case  'D':return 'L';break;
	}
	return '.';
}

bool link(int t,int f,int x1,int y1,int x2,int y2)
{
	char c1 = s[t][x1][y1],c2 = s[t][x2][y2];
	if(c1 == '*' || c2 == '*') return false;
	if(f == 0)
	{
		if(c1 == '|' || c1 == '^' || c1 == '<' || c1 == 'v' || c1 == 'R') return false;
		if(c2 == '|' || c2 == '^' || c2 == '>' || c2 == 'v' || c2 == 'L') return false;
	}
	if(f == 1)
	{
		if(c1 == '-' || c1 == '^' || c1 == '<' || c1 == '>' || c1 == 'D') return false;
		if(c2 == '-' || c2 == 'v' || c2 == '<' || c2 == '>' || c2 == 'U') return false;
	}
	if(f == 2)
	{
		if(c1 == '|' || c1 == '^' || c1 == '>' || c1 == 'v' || c1 == 'L') return false;
		if(c2 == '|' || c2 == '^' || c2 == '<' || c2 == 'v' || c2 == 'R') return false;
	}
	if(f == 3)
	{
		if(c1 == '-' || c1 == 'v' || c1 == '<' || c1 == '>' || c1 == 'U') return false;
		if(c2 == '-' || c2 == '^' || c2 == '<' || c2 == '>' || c2 == 'D') return false;
	}
	return true;
}

struct Node
{
	int x,y;
	int turn;
	int cost;
	Node(int x=0,int y=0,int t=0,int c=0):x(x),y(y),turn(t),cost(c) {}
};


int bfs()
{
	queue<Node> Q;
	Q.push(Node(xt,yt,0,0));
	d[0][xt][yt] = 1;
	int res = INF;
	while(!Q.empty())
	{
		Node u = Q.front(); Q.pop();
		if(u.x == xm && u.y == ym)
		{
			return u.cost;
		}
		for(int i=0;i<4;++i)
		{
			int tx = u.x + dx[i],ty = u.y + dy[i];
			if(check(tx,ty) && link(u.turn,i,u.x,u.y,tx,ty) && !d[u.turn][tx][ty])
			{
				d[u.turn][tx][ty] = 1;
				Q.push(Node(tx,ty,u.turn,u.cost+1));
			}
		}
		if(!d[(u.turn+1)%4][u.x][u.y])
		{
			d[(u.turn+1)%4][u.x][u.y] = 1;
			Q.push(Node(u.x,u.y,(u.turn+1)%4,u.cost+1));
		}
	}
	return -1;
}


int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n >> m;
	for(int i=0;i<n;++i)
		scanf("%s",s[0][i]);
	for(int i=1;i<4;++i)
	{
		for(int j=0;j<n;++j)
			for(int k=0;k<m;++k)
			{
				assert(turn(s[i-1][j][k]) != '.');
				s[i][j][k] = turn(s[i-1][j][k]);
			}
	}
	cin >> xt >> yt >> xm >> ym;
	--xt,--yt,--xm,--ym;
	cout << bfs() << '\n';
	return 0;
}

