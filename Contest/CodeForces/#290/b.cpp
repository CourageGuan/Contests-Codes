/*DFS,幸亏这个坑踩到了...
  判断是否有环，
  dfs加一个父节点坐标防止返回上一层*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define Fd(i,a,b) for(int i=(a);i>=(b);--i)

const int mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
const int maxn=50+5;
int pic[maxn][maxn],vis[maxn][maxn]; int m,n,cnt;

bool inside(int x,int y)
{
	return x>=0 && y>=0 && x<m && y<n;
}

bool dfs(int x,int y,int col,int cur,int lx,int ly)
{
	vis[x][y]=1;
	F(i,0,3){
		int u=x+mv[i][0],v=y+mv[i][1];
		if(inside(u,v) && pic[u][v]==col){
			if(u==lx && v==ly) continue;
			if(cur>=4 && vis[u][v]) return true;
			if(dfs(u,v,col,cur+1,x,y)) return true;
		}
	}
	return false;
}

int main()
{
	//freopen("test","r",stdin);
	memset(pic,0,sizeof(pic));
	memset(vis,0,sizeof(vis));
	cin>>m>>n;
	getchar();
	F(i,0,m-1){
		F(j,0,n-1){
			char ch=getchar();
			pic[i][j]=ch-'A'+1;
		}
		getchar();
	}
	bool flag=false;
	memset(vis,0,sizeof(vis));
	F(i,0,m-1){
		F(j,0,n-1){
			if(!vis[i][j] && dfs(i,j,pic[i][j],1,-1,-1)){
				//cout<<pic[i][j]<<endl;
				//cout<<i<<j<<endl;
				flag=true;
				break;
			}
		}
		if(flag) break;
	}
	puts(flag?"Yes":"No");
	/*F(i,0,m-1){
		F(j,0,n-1){
			cout<<pic[i][j];
		}
		cout<<endl;
	}*/
	return 0;
}

