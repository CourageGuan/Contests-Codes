/*刚开始理解错题目了，以为障碍只能直穿，结果是可以依次走k个障碍
  每次遇到障碍k值减一，压入栈里，若遇到空白压入k，k为0则不进行本次bfs
  还要注意一下不用对障碍标记，否则从不同方向就进不去障碍了*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn=20+10;
const int mv4[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int m,n,k,pic[maxn][maxn],dis[maxn][maxn],vis[maxn][maxn];

void init()
{
	memset(pic,0,sizeof(pic));
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
}

bool inside(int x,int y){return x>0 && y>0 && x<=n && y<=m;}
	
int bfs()
{
	queue<int> xx,yy,life;
	xx.push(1);yy.push(1);life.push(k);
	vis[1][1]=1;
	while(!xx.empty()){
		int x=xx.front(),y=yy.front(),lif=life.front();
		xx.pop();yy.pop();life.pop();
		//cout<<x<<" "<<y<<" "<<lif<<endl;
		if(x==n && y==m) return dis[n][m];
		F(i,0,3){
			int x0=x+mv4[i][0],y0=y+mv4[i][1];
			if(inside(x0,y0) && !vis[x0][y0]){
				if(!pic[x0][y0]){
					vis[x0][y0]=1;
					dis[x0][y0]=dis[x][y]+1;
					xx.push(x0);yy.push(y0);life.push(k);
				}
				else if(lif){
					//vis[x0][y0]=1;
					dis[x0][y0]=dis[x][y]+1;
					xx.push(x0);yy.push(y0);life.push(lif-1);
				}
			}
		}
	}
	return -1;
}


int main()
{
	//freopen("test","r",stdin);
	int kase;
	cin>>kase;
	while(kase--){
		init();
		cin>>n>>m;
		cin>>k;
		F(i,1,n)
			F(j,1,m)
				cin>>pic[i][j];
		cout<<bfs()<<endl;
		/*F(i,1,n){
			F(j,1,m)
				cout<<dis[i][j]<<" ";
			cout<<endl;
		}*/
	}
	return 0;
}
