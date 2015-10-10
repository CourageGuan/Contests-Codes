#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int maxn = 510;
const int INF = 0x3f3f3f3f;
const int dx[] = {1,0,-1,0,0};
const int dy[] = {0,-1,0,1,0};

int bx,by,tx,ty;

struct Node 
{
	int x,y;
	int t;
	Node(int r,int c,int t):x(r),y(c),t(t) {}
	bool operator<(const Node& rhs) const
	{
		return t>rhs.t;
	}
};

int d[maxn][maxn][4];
int pic[maxn][maxn];
int n;


inline bool check(int bx,int by,int t)
{
	if(pic[bx][by]>=0 && pic[bx][by]<=3) return true;
	for(int i=0;i<4;++i)
	{
		int x=bx+dx[i],y=by+dy[i];
		if(x>=0 && y>=0 && x<n && y<n && pic[x][y]<4 && pic[x][y]>=0 && (pic[x][y]+t)%4 == i)
		{
			return true;
		}
	}
	return false;
}

inline int bfs()
{
	priority_queue<Node> Q;
	Q.push(Node(bx,by,0));
	memset(d,INF,sizeof d);
	while(!Q.empty())
	{
		Node p = Q.top(); Q.pop();

		//printf("%d %d %d\n",p.x,p.y,p.t);
		if(p.x==tx && p.y==ty)	return p.t;
		if(d[p.x][p.y][p.t%4]<p.t) continue;

		int box = check(p.x,p.y,p.t);
//		printf("%d %d %d .. %d\n",p.x,p.y,p.t,box);

		for(int i=0;i<5;++i)
		{
			int x = p.x+dx[i] , y = p.y+dy[i];
			if(x>=0 && y>=0 && x<n && y<n && pic[x][y]<4)
			{
				int t;
				int tbox = check(x,y,p.t);
				//printf("%d %d %d .. %d\n",x,y,p.t,tbox);
				if(x == p.x && y == p.y || (!tbox && !box))
				{
					t = p.t + 1;
					if(t<d[x][y][t%4])
					{
						d[x][y][t%4] = t;
						Q.push(Node(x,y,t));
					}
				}
				else
				{
					t = p.t + 3;
					if(t<d[x][y][t%4])
					{
						d[x][y][t%4] = t;
						Q.push(Node(x,y,t));
					}

				}
			}
		}
	}
	return -1;
}



int main()
{
	//freopen("test.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		char s[maxn];
		tx = ty = bx = by = -1;
		for(int i=0;i<n;++i)
		{
			scanf("%s",s);
			for(int j=0;j<n;++j)
			{
				int t = 0;
				switch(s[j])
				{
					case '.':t=-1;break;
					case '#':t=4;break;
					case 'N':t=0;break;
					case 'E':t=1;break;
					case 'S':t=2;break;
					case 'W':t=3;break;
					case 'M':bx = i,by = j,t=-1; break;
					case 'T':tx = i,ty = j,t=-1;break;
				}
				pic[i][j] = t;
			}
		}
	//	for(int i=0;i<n;++i) for(int j=0;j<n;++j) printf("%d%c",pic[i][j],j==n-1?'\n':' ');
	//	printf("%d %d %d %d\n",tx,ty,bx,by);
		if(tx == -1 || bx == -1)
		{
			printf("Case #%d: %d\n",z,-1);
			continue;
		}
		printf("Case #%d: %d\n",z,bfs());
	}
	return 0;
}


