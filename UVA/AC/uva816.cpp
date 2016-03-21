/*BFS，不过状态比较多，到达每个点的朝向，可以转的方向等
 　具体参考白书*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define Fd(i,a,b) for(int i=(a);i>=(b);--i)
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
#define OK puts("OK")

const int mv4[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const char* dirs="NESW";
const char* turns="FLR";
const int maxn=12;
int n,m,x0,y0,x1,y1,x2,y2,dir;
bool has[maxn][maxn][4][3];
int d[maxn][maxn][4];

struct node{
	int x,y,dir;
	node(int x=0,int y=0,int dir=0):x(x),y(y),dir(dir) {}
} p[maxn][maxn][4];	//father

void init()
{
	memset(d,-1,sizeof(d));
	memset(has,0,sizeof(has));
}


bool inside(int x,int y)
{
	return (x>0 && x<=n && y>0 && y<=m);
}

int id_dir(char c)
{
	return strchr(dirs,c)-dirs;
}

int id_turn(char c)
{
	return strchr(turns,c)-turns;
}

node to(const node &u,int turn)
{
	int dir=u.dir;
	if(turn==1) dir=(dir+3) % 4;	//逆时针
	if(turn==2) dir=(dir+1) % 4;	//顺时针
	return node(u.x+mv4[dir][0],u.y+mv4[dir][1],dir);
}

void read()
{
	char ch;
	cin>>x0>>y0>>ch>>x2>>y2;
	n=max(x0,x2);
	m=max(y0,y2);
	node u(x0,y0,id_dir(ch));
	node v=to(u,0);
	x1=v.x;y1=v.y;dir=v.dir;
	int x,y;
	while(cin>>x && x){
		cin>>y;
		//printf("(%d,%d) \n",x,y);
		n=max(n,x);
		m=max(m,y);
		string s;
		while(cin>>s && s[0]!='*'){
			F(i,1,s.size()-1){
				//cout<<id_dir(s[0])<<" "<<id_turn(s[i])<<endl;
				has[x][y][id_dir(s[0])][id_turn(s[i])]=1;
			}
		}
	}
}

void print(node u)
{	
	vector<node> nodes;
	for(;;){
		nodes.push_back(u);
		if(d[u.x][u.y][u.dir]==0) break;
		u=p[u.x][u.y][u.dir];
	}
	nodes.push_back(node(x0,y0,dir));
	int cnt=0;
	Fd(i,nodes.size()-1,0){
		if(cnt++%10==0) printf("\n ");
		printf(" (%d,%d)",nodes[i].x,nodes[i].y);
	}
	puts("");
}

void bfs()
{
	queue<node> q;
	node u(x1,y1,dir);
	d[x1][y1][dir]=0;
	q.push(u);
	while(!q.empty()){
		node u=q.front();q.pop();
		if(u.x==x2 && u.y==y2) {print(u);return;}
		//printf("(%d,%d),%d ",u.x,u.y,u.dir);
		F(i,0,2){
			node v=to(u,i);
			if(has[u.x][u.y][u.dir][i] && inside(v.x,v.y) && d[v.x][v.y][v.dir]<0){
				d[v.x][v.y][v.dir]=d[u.x][u.y][u.dir]+1;
				p[v.x][v.y][v.dir]=u;
				q.push(v);
			}
		}
	}
	printf("\n  No Solution Possible\n");
}




int main()
{
	//freopen("test","r",stdin);
	//freopen("1","w",stdout);
	string name;
	while(cin>>name && name!="END"){
		cout<<name;
		init();
		read();
		bfs();
	}
}



