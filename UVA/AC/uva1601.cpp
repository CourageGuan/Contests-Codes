/*还是状态图bfs，现在还想不到这些细节...直接看的代码库...*/
#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define SET(a,t) memset(a,t,sizeof(a))

	const int maxs=16+4;
	const int maxn=16*16;
	const int mv[5][2]={{-1,0},{0,-1},{1,0},{0,1},{0,0}};

	inline int ID(int a,int b,int c){
		return (a<<16)|(b<<8)|c;	//Amazing~ x,y->a/b/c  [3]->0x0x0x
	}

	inline bool conflict(int a,int b,int a2,int b2){
		return a2==b2 || (a2==b && b2==a); 
	}


	int deg[maxn],pic[maxn][5],s[3],t[3];		
	int dis[maxn][maxn][maxn];

	int bfs()
	{
		queue<int> q;
		SET(dis,-1);
		q.push(ID(s[0],s[1],s[2]));
		dis[s[0]][s[1]][s[2]]=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			int a=(u>>16)&0xff,b=(u>>8)&0xff,c=u&0xff;
			//cout<<dis[a][b][c]<<endl;
			if(a==t[0] && b==t[1] && c==t[2]) return dis[a][b][c];
			F(i,0,deg[a]-1){
				int a2=pic[a][i];
				F(j,0,deg[b]-1){
					int b2=pic[b][j];
					if(conflict(a,b,a2,b2)) continue;
					F(k,0,deg[c]-1){
						int c2=pic[c][k];
						if(conflict(a,c,a2,c2)) continue;
						if(conflict(b,c,b2,c2)) continue;
						if(dis[a2][b2][c2]!=-1) continue;
						dis[a2][b2][c2]=dis[a][b][c]+1;
						q.push(ID(a2,b2,c2));
					}
				}
			}
		}
		return -1;
	}

int main()
{
	//freopen("test","r",stdin);
	int w,h,n;
	while(scanf("%d%d%d",&w,&h,&n)==3 && n){
		getchar();
		char maze[maxs][maxs];
		F(i,0,h-1){
			scanf("%[^\n]%*c",maze[i]);
			//cout<<maze[i]<<endl;
		}
		int cnt,x[maxn],y[maxn],id[maxs][maxs];
		cnt=0;
		F(i,0,h-1)
			F(j,0,w-1)
			if(maze[i][j]!='#'){
				x[cnt]=i;y[cnt]=j;id[i][j]=cnt;
				if(islower(maze[i][j]))	s[maze[i][j]-'a']=cnt;
				else if (isupper(maze[i][j])) t[maze[i][j]-'A']=cnt;
				cnt++;
			}
		F(i,0,cnt-1){	//pre-processing the pic
			deg[i]=0;
			F(j,0,4){
				int nx=x[i]+mv[j][0],ny=y[i]+mv[j][1];
				if(maze[nx][ny]!='#') pic[i][deg[i]++]=id[nx][ny];
			}
		}

		if(n<=2){deg[cnt]=1;pic[cnt][0]=cnt;s[2]=t[2]=cnt++;}	//fakes nodes
		if(n<=1){deg[cnt]=1;pic[cnt][0]=cnt;s[2]=t[2]=cnt++;}	//wonderful!

		printf("%d\n",bfs());
	}
	return 0;
}

