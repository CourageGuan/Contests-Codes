/*BFS 一个图统计访问和层数就够了*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int mv8[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
const int maxn=10;
int pic[maxn][maxn];


inline void init()
{
	memset(pic,0,sizeof(pic));
}

bool inside(int x,int y){return x>0 && x<=8 && y>0 && y<=8;}

int bfs(int x1,int y1,int x2,int y2)
{
	queue<int> xx,yy;
	xx.push(x1);yy.push(y1);
	while(!xx.empty()){
		int x=xx.front(),y=yy.front();
		xx.pop();yy.pop();
		if(x==x2 && y==y2) return pic[x][y];
		F(i,0,7){
			int x0=x+mv8[i][0],y0=y+mv8[i][1];
			if(inside(x0,y0) && !pic[x0][y0]){
				pic[x0][y0]=pic[x][y]+1;
				xx.push(x0);
				yy.push(y0);
			}
		}
	}
	return 0;
}

int main()
{
	//freopen("test","r",stdin);
	//freopen("1","w",stdout);
	char s1[3],s2[3];
	while(cin>>s1>>s2){
		init();
		printf("To get from %s to %s takes %d knight moves.\n",s1,s2,bfs(s1[0]-96,s1[1]-48,s2[0]-96,s2[1]-48));
	}
	return 0;
}

