/*离散化+floodfill 用bfs，dfs要爆栈
  填充对象为空气*/
#include<bits/stdc++.h>
using namespace std;

//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define SET(a,t) memset(a,t,sizeof(a))

const int maxn=50+5;
const int mv[6][3]={{0,0,1},{0,0,-1},{-1,0,0},{1,0,0},{0,-1,0},{0,1,0}};
					//up	 down  	  left	    right  foward	back
struct BOX{
	int x0,y0,z0,x,y,z;
} box[maxn];

int dx[2*maxn],dy[2*maxn],dz[2*maxn],v[2*maxn][2*maxn][2*maxn],s[6][2*maxn][2*maxn][2*maxn];
bool flag[2*maxn][2*maxn][2*maxn],vis[2*maxn][2*maxn][2*maxn];
int V,S,emp,n,nx,ny,nz;

void init()
{
	SET(v,0);
	SET(flag,0);
	SET(vis,0);
}


bool inside(int x,int y,int z)
{	
	return x>=0 && y>=0 && z>=0 && x<nx && y<ny && z<nz;
}

bool in(int x,int xx,int y,int yy,int z,int zz)
{
	F(i,1,n)
		if(x>=box[i].x0 && xx<=box[i].x && y>=box[i].y0 
	   	 &&	yy<=box[i].y && z>=box[i].z0 && zz<=box[i].z) return true;
	return false; 
}

/*void dfs(int x,int y,int z)	//stack Overflow
{
	//if(vis[x][y][z]) return;
	//cout<<x<<" "<<y<<" "<<z<<endl;
	//cout<<c<<endl;
	vis[x][y][z]=1;
	emp+=v[x][y][z];
	F(t,0,5){
		int i=x+mv[t][0],j=y+mv[t][1],k=z+mv[t][2];
		if(inside(i,j,k) && !vis[i][j][k]){
			if(!flag[i][j][k]) dfs(i,j,k);
		    else S+=s[t][i][j][k];
	    }
	}
}*/

struct point{
	int x,y,z;
	point(int x=0,int y=0,int z=0):x(x),y(y),z(z) {}
};

void bfs()
{
	queue<point> q;
	q.push(point(0,0,0));
	vis[0][0][0]=1;
	while(!q.empty()){
		int x=q.front().x,y=q.front().y,z=q.front().z;q.pop();
		emp+=v[x][y][z];
		F(t,0,5){
			int i=x+mv[t][0],j=y+mv[t][1],k=z+mv[t][2];
			if(inside(i,j,k) && !vis[i][j][k]){
				if(flag[i][j][k]) S+=s[t][i][j][k];
				else{
					vis[i][j][k]=1;
					q.push(point(i,j,k)); 
				}
			}
		}
	}
}
	
void solve()
{
	dx[0]=dy[0]=dz[0]=0;
	dx[2*n+1]=dy[2*n+1]=dz[2*n+1]=1001;
	sort(dx,dx+2*n+2);
	sort(dy,dy+2*n+2);
	sort(dz,dz+2*n+2);
	//F(i,1,2*n) cout<<dz[i]<<" ";
	nx=unique(dx,dx+2*n+2)-dx;
	ny=unique(dy,dy+2*n+2)-dy;
	nz=unique(dz,dz+2*n+2)-dz;
	//cout<<nx<<" "<<ny<<" "<<nz<<endl;
	/*F(i,0,nx) cout<<dx[i]<<" ";
	cout<<nx<<endl;
	F(i,0,ny) cout<<dy[i]<<" ";
	cout<<ny<<endl;
	F(i,0,nz) cout<<dz[i]<<" ";
	cout<<nz<<endl;
	cout<<endl;*/
	F(x,0,nx-2)
		F(y,0,ny-2)
			F(z,0,nz-2){
				int xx,yy,zz;
				xx=dx[x+1]-dx[x];
				yy=dy[y+1]-dy[y];
				zz=dz[z+1]-dz[z];
				v[x][y][z]=xx*yy*zz;
				//cout<<x<<" "<<y<<" "<<z<<" "<<v[x][y][z]<<endl;
				s[0][x][y][z]=s[1][x][y][z]=xx*yy;
				s[2][x][y][z]=s[3][x][y][z]=yy*zz;
				s[4][x][y][z]=s[5][x][y][z]=xx*zz;
				if(in(dx[x],dx[x+1],dy[y],dy[y+1],dz[z],dz[z+1])) flag[x][y][z]=1;
			}
	//cout<<mxx<<" "<<mnx<<endl;
	emp=0;S=0;
	/*F(x,0,nx-1)
		F(y,0,ny-1)
			F(z,0,nz-1)
				if(!flag[x][y][z] && !vis[x][y][z]) dfs(x,y,z);*/
	//dfs(0,0,0);
	bfs();
	V=1001*1001*1001-emp;
	//cout<<emp<<endl;
	printf("%d %d\n",S,V);
}

int main()
{
	//freopen("test","r",stdin);
	int kase;
	scanf("%d",&kase);
	while(kase--){
		init();
		scanf("%d",&n);
		F(i,1,n){
			int x,y,z;
			scanf("%d%d%d%d%d%d", &box[i].x0,&box[i].y0,&box[i].z0,&x,&y,&z);
			box[i].x=box[i].x0+x;box[i].y=box[i].y0+y;box[i].z=box[i].z0+z;
			//printf("%d %d %d %d %d %d\n", box[i].x0,box[i].y0,box[i].z0,x,y,z);
			dx[2*i-1]=box[i].x0;dx[2*i]=box[i].x;
			dy[2*i-1]=box[i].y0;dy[2*i]=box[i].y;
			dz[2*i-1]=box[i].z0;dz[2*i]=box[i].z;
		}
		solve();
	}
	return 0;
}
