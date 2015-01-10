#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=123;
const int mv4[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
queue<pair<int,int> > q;
int pic[maxn][maxn],dis[maxn][maxn],m,n;
bool have_ar[maxn][maxn];

void bfs(int d,int x,int y)
{
	pair<int,int> p=make_pair(x,y);
	q.push(p);
	dis[x][y]=d;
	have_ar[x][y]=1;
	while(!q.empty()){
		p=q.front();
		q.pop();
		d=dis[p.first][p.second]+1;
		for(int i=0;i<4;i++){
			x=p.first+mv4[i][0];
			y=p.second+mv4[i][1];
			if(!pic[x][y] || have_ar[x][y] || x<0 || x>=n || y<0 || y>=m) continue;
			have_ar[x][y]=1;
			dis[x][y]=d;
			pair<int,int> pa=make_pair(x,y);
			q.push(pa);
		}
	}
}
	
int main()
{
	freopen("test","r",stdin);
	memset(pic,0,sizeof(pic));
	memset(have_ar,0,sizeof(have_ar));
	memset(dis,0,sizeof(dis));
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>pic[i][j];
	bfs(0,0,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<dis[i][j]<<" ";
		cout<<endl;
	}
}


